#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <sys/socket.h>
#include <common/Typedef.h>
#include <Protocol.h>
#include <thread>
#include <memory>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <SystemConfig.h>
#include <tcpserver.h>
#include <error.h>
#include <thread>
#include <condition_variable>


#define SOCKET_BUFFER_SIZE		1200

template<class T>
class CTcpProtocolInfo:public CProtocolInfo<T>{
public:
      CTcpProtocolInfo(uint8_t *pRxCachebuf, uint8_t *pTxCacheBuf, uint16_t nMaxSize,
                       SystemConfigInfo::SSystemConfig *p):pSystemConfigInfo(p),
                       CProtocolInfo<T>(pRxCachebuf,pTxCacheBuf,nMaxSize){

     };
     ~CTcpProtocolInfo() {
      }

     void ThreadRun(){
          m_thread = std::thread(&CTcpProtocolInfo<T>::SocketTcpLoopThread,this);
          m_dpthread = std::thread(&CTcpProtocolInfo<T>::SocketTcpDataProcessThread,this);
     }
 
      /*TCP Socket 数据读取接口*/
      int DeviceRead(int nFd,uint8_t *pDataStart, uint16_t nDataSize, T ExtraInfo) override{
           *ExtraInfo = recv(nFd, pDataStart, nDataSize,0);
           return *ExtraInfo;
      }

      /*TCP Socket数据写入接口*/
      int DeviceWrite(int nFd,uint8_t *pDataStart, uint16_t nDataSize, T ExtraInfo) override{
           *ExtraInfo = send(nFd, pDataStart, nDataSize, 0);
           return *ExtraInfo;
      }

      void SocketTcpLoopThread(){
          int server_fd;
          int bind_result;
          struct sockaddr_in serverip, clientip;
          int is_bind_fail = 0;
          uint32_t client_size;
          int client_fd;
          

          USR_DEBUG("Socket Tcp Thread Start!\n");
          memset((char *)&serverip, 0, sizeof(serverip));
          serverip.sin_family = AF_INET;                       //ip
          serverip.sin_port = htons(pSystemConfigInfo->m_tcp_net_port);
          //serverip.sin_addr.s_addr = inet_addr(pSystemConfigInfo->m_tcp_ipaddr.c_str());
          serverip.sin_addr.s_addr = htonl(INADDR_ANY);

          server_fd = socket(AF_INET, SOCK_STREAM, 0);
          if(server_fd != -1){
               int one = 1;
               /*Linux平台默认断开后2min内处于Wait Time状态，不允许重新绑定，需要添加配置，允许在该状态下重新绑定*/
               setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (void*) &one, (socklen_t)sizeof(one));
               
               do{        //socket 绑定
                    bind_result = bind(server_fd, (struct sockaddr *)&serverip, sizeof(serverip));
                    if(bind_result == -1){
                         static int check;
                         if(is_bind_fail == 0){
                              is_bind_fail = 1;
                              SOCKET_DEBUG("Tcp Bind %s Failed!, error:%s\r\n", 
                                        std::to_string(INADDR_ANY).c_str(), strerror(errno));
                              if(errno == EADDRINUSE){
                              server_fd = socket(AF_INET, SOCK_STREAM, 0);
                              }
                         }
                         sleep(1);
                    }
                    else  break;
               }while(1);

               SOCKET_DEBUG("Tcp Bind ok, ServerIp:%s, NetPort:%d\n", std::to_string(INADDR_ANY).c_str(), 
                         pSystemConfigInfo->m_tcp_net_port);

               listen(server_fd,32);

               client_size = sizeof(clientip);   //size ： size of ip address

               while(1){
                    USR_DEBUG("TCP Server is listenning .... \r\n");
                    client_fd = accept(server_fd, (struct sockaddr *)&clientip, &client_size);

                    if(client_fd < 0)
                         SOCKET_DEBUG("Tcp accept failed!\r\n");
                    else{
                         SOCKET_DEBUG("server accept the client...\r\n");

                         
                         m_clientfd = client_fd;  //transfer client_fd to PD thread
                         IfStartDP = true;     //notify data process thread to start
                         m_cv.notify_one();

                         std::unique_lock<std::mutex> lk(m_mtx);  //block self
                         m_cv.wait(lk, [this]() -> bool
                              { return !this->IfStartDP; });  //waiting for the DP thread complete
                    }
               }
          }
          else{
               SOCKET_DEBUG("Tcp Init Failed!\r\n");
          }
          close(server_fd);
          
          return;
     }
     void SocketTcpDataProcessThread(){

          int client_fd;
          int nFlag;
          int size;
          uint8_t is_loop = 0;
          fd_set read_set;

          while(1){   
               std::unique_lock<std::mutex> lk(m_mtx);
               m_cv.wait(lk, [this]() -> bool
                         { return this->IfStartDP; });   //block here,waiting for the signal of start
               
               if(m_clientfd < 0) {
                    SOCKET_DEBUG("TCP Data Process error\r\n");
                    return;
               }
               else{
                    client_fd = m_clientfd;
                    m_clientfd = -1;
               }

               FD_ZERO(&read_set);
               FD_SET(client_fd,&read_set);

               for(;;){
                    nFlag = this->CheckRxBuffer(client_fd,false,&size);
                    if (nFlag == RT_OK)
                    {
                         SOCKET_DEBUG("TCP Data Process Successfully \r\n");
                         this->ExecuteCommand(client_fd); //底层驱动相关指令,create tx buffer
                         this->SendTxBuffer(client_fd, &size);
                         if (this->GetFileUploadStatus())
                              break;
                    }
                    else if(nFlag == RT_FAIL){
                         SOCKET_DEBUG("TCP Data Process Failed \r\n");
                         struct timeval client_timeout = {0, 100};  //Second  microSecond
                         nFlag = select(client_fd, &read_set, NULL, NULL, &client_timeout);   
                         if (nFlag < 0)
                              break;
                    }
                    else {
                         break;
                    }
               }

               IfStartDP = false;
               m_cv.notify_one();   //运行到此处代表客户端断开连接，那么唤醒TCP主线程，并阻塞DP线程，等待下次客户端连接

               close(client_fd);
          }
          return;
     }

private:
      std::thread m_thread;
      std::thread m_dpthread;
      bool IfStartDP = false;   //是否开启数据处理线程
      std::condition_variable m_cv;
      std::mutex m_mtx;
      int m_clientfd = -1;
      SystemConfigInfo::SSystemConfig *pSystemConfigInfo;
};




#endif