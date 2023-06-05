/**
 *  IMX6ULL
 */
#include <common/Typedef.h>
#include <Message/CalCRC16.h>
#include <Message/FifoMessage.h>
#include <Message/MqMessage.h>
#include <Protocol.h>
#include <SystemConfig.h>
#include <tcpserver.h>
#include <udpserver.h>
#include <uartserver.h>
#include <hardwareserver.h>
#include <hardware/led.h>





int main(int argc, char **argv)
{
      int RT_daemon;
      bool nConfigDefault = false; //  if use default config file

      std::unique_ptr<CTcpProtocolInfo<int *>> TcpProtocolptr;
      std::unique_ptr<CUdpProtocolInfo<UdpInfo *>> UdpProtocolptr;
      std::unique_ptr<CUartProtocolInfo<int *>> UartProtocolptr;
      std::shared_ptr<SystemConfigInfo::SSystemConfig> MainpSSystemConfig;
      std::shared_ptr<CBaseMessageInfo> pMainMessageInfo;
      std::shared_ptr<CHardWareServer> pMainHardWareInfo;

      std::string sConfigFile;
      sConfigFile = std::string("config.json");
      SystemConfigInfo SystemConfig(&sConfigFile);

      //设置为守护进程，在后台中运行
      // RT_daemon = daemon(1, 1);
      // if (RT_daemon < 0)
      // {
      //       USR_DEBUG("daemon error \n");
      //       return RT_daemon;
      // }

      //选中配置文件
      if (!nConfigDefault)
      {
            //USR_DEBUG("config file:%s\n", sConfigFile.c_str()); //Show ConfigFile
            if (SystemConfig.ConfigInitilize() != EXIT_SUCCESS)
                  USR_DEBUG("system config read fail, use default\n");
            SystemConfig.ShowSSystemConfigInfo();
      }
      else
            USR_DEBUG("system config use default");

      //SystemConfig Init
      MainpSSystemConfig = SystemConfigInfo::pShardSystemConfig;

      //Message Queue Init
      pMainMessageInfo = CBaseMessageInfo::pSharedMqMessage;
      pMainMessageInfo->CreateInfomation();

      //TCP Server Init
      std::unique_ptr<uint8_t[]> nTCPRxCacheBuffer(new uint8_t[SOCKET_BUFFER_SIZE]);
      std::unique_ptr<uint8_t[]> nTCPTxCacheBuffer(new uint8_t[SOCKET_BUFFER_SIZE]);
      TcpProtocolptr = std::make_unique<CTcpProtocolInfo<int*>>(nTCPRxCacheBuffer.get(), 
                                   nTCPTxCacheBuffer.get(), SOCKET_BUFFER_SIZE, MainpSSystemConfig.get());
      TcpProtocolptr->ThreadRun();

            //UDP Server Init
      std::unique_ptr<uint8_t[]> nUDPRxCacheBuffer(new uint8_t[SOCKET_BUFFER_SIZE]);
      std::unique_ptr<uint8_t[]> nUDPTxCacheBuffer(new uint8_t[SOCKET_BUFFER_SIZE]);
      UdpProtocolptr = std::make_unique<CUdpProtocolInfo<UdpInfo*>>(nUDPRxCacheBuffer.get(), 
                                   nUDPTxCacheBuffer.get(), SOCKET_BUFFER_SIZE, MainpSSystemConfig.get());
      UdpProtocolptr->ThreadRun();

      //UART Server Init
      std::unique_ptr<uint8_t[]> nUARTRxCacheBuffer(new uint8_t[UART_BUFFER_SIZE]);
      std::unique_ptr<uint8_t[]> nUARTTxCacheBuffer(new uint8_t[UART_BUFFER_SIZE]);
      UartProtocolptr = std::make_unique<CUartProtocolInfo<int*>>(nUARTRxCacheBuffer.get(), 
                                   nUARTTxCacheBuffer.get(), UART_BUFFER_SIZE, MainpSSystemConfig.get());
      UartProtocolptr->ThreadRun();

      //HardWare Server Init
      pMainHardWareInfo = CHardWareServer::pSharedHardWareServ;
      pMainHardWareInfo->ThreadRun();


      for(;;){
          static char MainMqFlag;
          int flag;
          flag = pMainMessageInfo->WaitInformation(MAIN_BASE_MESSAGE, &MainMqFlag, sizeof(MainMqFlag));
          if(flag != -1){
			pMainMessageInfo->CloseInformation(MAIN_BASE_MESSAGE);
			break;
	    }
	    else{
			USR_DEBUG("Mq Wait Error,Error Code:%s\n", strerror(errno));
			sleep(100);
	    }
      }

      USR_DEBUG("Process Lower_app stop, error:%s\n", strerror(errno));
      return RT_daemon;
}