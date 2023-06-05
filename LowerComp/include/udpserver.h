#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <sys/socket.h>
#include <common/Typedef.h>
#include <Protocol.h>
#include <thread>
#include <memory>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <SystemConfig.h>
#include <error.h>
#include <condition_variable>
#include "hardwareserver.h"

#define SOCKET_BUFFER_SIZE		1200



struct UdpInfo
{
    struct sockaddr_in clientaddr;
    socklen_t client_sock_len;   
};


template<class T>
class CUdpProtocolInfo:public CProtocolInfo<T>{
public:
      CUdpProtocolInfo(uint8_t *pRxCachebuf, uint8_t *pTxCacheBuf, uint16_t nMaxSize,
                       SystemConfigInfo::SSystemConfig *p):pSystemConfigInfo(p),
                       CProtocolInfo<T>(pRxCachebuf,pTxCacheBuf,nMaxSize){

     }

      ~CUdpProtocolInfo() {
      }

    void ThreadRun(){
          m_thread = std::thread(&CUdpProtocolInfo<T>::SocketUdpLoopThread, this);
    }

    	/*UDP Socket数据读取接口*/
	int DeviceRead(int nFd, uint8_t *pDataStart, uint16_t nDataSize, T extra_info) override
	{
		int nLen;
		UdpInfo *pUdpInfo = (UdpInfo *)extra_info;
		nLen = recvfrom(nFd, pDataStart, nDataSize, 0, (struct sockaddr *)&(pUdpInfo->clientaddr), 
					&(pUdpInfo->client_sock_len));

		return nLen;
	}

	/*UDP Socket数据写入接口*/
	int DeviceWrite(int nFd, uint8_t *pDataStart, uint16_t nDataSize, T extra_info) override
	{
		UdpInfo *pUdpInfo = (UdpInfo *)extra_info;
		return sendto(nFd, pDataStart, nDataSize, 0, (struct sockaddr *)&(pUdpInfo->clientaddr), 
					pUdpInfo->client_sock_len);
	}

    void SocketUdpLoopThread(){
        int socket_fd, result;
        struct sockaddr_in servaddr, clientaddr;  
        int is_bind_fail = 0;
        char recvbuf[1024] = {0};
        socklen_t client_sock_len;
        UdpInfo sUdpInfo;

        USR_DEBUG("Socket Udp Thread Start!\n");

        socket_fd = socket(PF_INET, SOCK_DGRAM, 0);  /*创建socket接口, SOCK_DGRAM表示无连接的udp接口*/
        if(socket_fd != -1){
            /*绑定到指定端口*/
            memset(&servaddr, 0, sizeof(servaddr));
            servaddr.sin_family = AF_INET;     
            //servaddr.sin_addr.s_addr = inet_addr(pSystemConfigInfo->m_udp_ipaddr.c_str());  
            servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
            servaddr.sin_port = htons(pSystemConfigInfo->m_udp_net_port); 
        

            do {
                result = bind(socket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
                if(result == -1){
                    if(is_bind_fail == 0){
                        is_bind_fail = 1;
                        SOCKET_DEBUG("Udp Bind Failed!ServerIp:%s, NetPort:%d\n", std::to_string(INADDR_ANY).c_str(), 
                        pSystemConfigInfo->m_udp_net_port);
                    }
                    sleep(1);
                }
                else
                    break;
            } while (1); //网络等待socket绑定完成后执行后续

            SOCKET_DEBUG("Udp Bind ok, ServerIp:%s, NetPort:%d\n", std::to_string(INADDR_ANY).c_str(), 
                    pSystemConfigInfo->m_udp_net_port);

            long count = 0;
            for (;;){
                int nFlag;
                nFlag = this->CheckRxBuffer(socket_fd, true, &sUdpInfo);
                if(nFlag == RT_OK){
                    this->ExecuteCommand(socket_fd);
                    this->SendTxBuffer(socket_fd, &sUdpInfo);
		        }
                else
                    sleep(1);

                if(count++ % 100 == 0){
                    printf("udp send remain ... \r\n");
                }
            }
        }
        else
            SOCKET_DEBUG("Udp Socket Init Failed\n");

        close(socket_fd);
        return;
    }

private:
      std::thread m_thread;
      SystemConfigInfo::SSystemConfig *pSystemConfigInfo;
};

#endif