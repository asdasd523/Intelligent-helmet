#ifndef _UARTTHREAD_H
#define _UARTTHREAD_H

#include <common/Typedef.h>
#include <Protocol.h>
#include <thread>
#include <memory>
#include <SystemConfig.h>
#include <error.h>
#include <condition_variable>
#include <fcntl.h>


#define UART_BUFFER_SIZE     		1200


template<class T>
class CUartProtocolInfo:public CProtocolInfo<T>{

public:

CUartProtocolInfo(uint8_t *pRxCachebuf, uint8_t *pTxCacheBuf, uint16_t nMaxSize,
                  SystemConfigInfo::SSystemConfig *p):pSystemConfigInfo(p),CProtocolInfo<T>(pRxCachebuf,
                  pTxCacheBuf,nMaxSize){
    //open device /dev/ttymxc2
    if((nComFd = open(pSystemConfigInfo->m_dev_serial.c_str(),O_RDWR|O_NOCTTY|O_NDELAY)) < 0){
		USR_DEBUG("Open %s Failed\n", pSystemConfigInfo->m_dev_serial.c_str());
		return;
    }
    else{
        if(set_opt(nComFd, pSystemConfigInfo->m_baud, pSystemConfigInfo->m_data_bits,
                   pSystemConfigInfo->m_parity, pSystemConfigInfo->m_stop_bits) != 0)
		{
			USR_DEBUG("uart config failed\n");
			return;
		}
		USR_DEBUG("Open %s Success!\t\n", pSystemConfigInfo->m_dev_serial.c_str());
    }
}


void ThreadRun(){
    m_thread = std::thread(&CUartProtocolInfo<T>::UartLoopThread, this);  
}

int DeviceRead(int nFd, uint8_t *pDataStart, uint16_t nDataSize, T ExtraInfo) override{
        *ExtraInfo = read(nFd, pDataStart, nDataSize);
        return *ExtraInfo;
}


int DeviceWrite(int nFd,uint8_t *pDataStart, uint16_t nDataSize, T ExtraInfo) override{
        *ExtraInfo = write(nFd, pDataStart, nDataSize);
        return *ExtraInfo;       
}


    /**
 * 配置Uart硬件的功能
 * 
 * @param fd 	 设置的串口设备ID
 * @param nBaud 波特率
 * @param nDataBits  数据位
 * @param cParity 奇偶校验位
 * @param nStopBits  停止位
 *  
 * @return NULL
 */
int set_opt(int nFd, int nBaud, int nDataBits, std::string cParity, int nStopBits)
{
	struct termios newtio;
	struct termios oldtio;

	if(tcgetattr(nFd, &oldtio)  !=  0) 
	{ 
		USR_DEBUG("Get Serial Attribute Failed\n");
		return -1;
	}
	bzero(&newtio, sizeof(newtio));
	newtio.c_cflag |= (CLOCAL|CREAD);
	newtio.c_cflag &= ~CSIZE;

	switch(nDataBits)
	{
		case 7:
			newtio.c_cflag |= CS7;
			break;
		case 8:
			newtio.c_cflag |= CS8;
			break;
		default:
			break;
	}

	switch(cParity[0])
	{
		case 'O':
		case 'o':
			newtio.c_cflag |= PARENB;
			newtio.c_cflag |= PARODD;
			newtio.c_iflag |= (INPCK | ISTRIP);
			break;
		case 'E': 
		case 'e':
			newtio.c_iflag |= (INPCK | ISTRIP);
			newtio.c_cflag |= PARENB;
			newtio.c_cflag &= ~PARODD;
			break;
		case 'N': 
		case 'n': 
			newtio.c_cflag &= ~PARENB;
			break;
	}

	switch(nBaud)
	{
		case 2400:
			cfsetispeed(&newtio, B2400);
			cfsetospeed(&newtio, B2400);
			break;
		case 4800:
			cfsetispeed(&newtio, B4800);
			cfsetospeed(&newtio, B4800);
			break;
		case 9600:
			cfsetispeed(&newtio, B9600);
			cfsetospeed(&newtio, B9600);
			break;
		case 115200:
			cfsetispeed(&newtio, B115200);
			cfsetospeed(&newtio, B115200);
			break;
		case 460800:
			cfsetispeed(&newtio, B460800);
			cfsetospeed(&newtio, B460800);
			break;
		case 921600:
			cfsetispeed(&newtio, B921600);
			cfsetospeed(&newtio, B921600);
			break;
		default:
			cfsetispeed(&newtio, B9600);
			cfsetospeed(&newtio, B9600);
			break;
	}
	
	if(nStopBits == 1)
	{
		newtio.c_cflag &=  ~CSTOPB;
	}
	else if (nStopBits == 2)
	{
		newtio.c_cflag |=  CSTOPB;
	}
	newtio.c_cc[VTIME]  = 0;
	newtio.c_cc[VMIN] = 0;

	tcflush(nFd, TCIFLUSH);
	if((tcsetattr(nFd, TCSANOW, &newtio))!=0)
	{
		USR_DEBUG("Serial Config Error\n");
		return -1;
	}

	USR_DEBUG("Serial Config Done Success!\n\r");
	return 0;
}

void UartLoopThread(){
    int nFlag;
    int size;

    USR_DEBUG("Uart Thread Loop Start\n");

    for (;;){
        nFlag = this->CheckRxBuffer(nComFd, false, &size);
        if(nFlag == RT_OK){
			USR_DEBUG("Uart Get a Message \n");
            this->ExecuteCommand(nComFd);
			m_mtx.lock();
			while(size < (this->SendTxBuffer(nComFd, &size))) {};
			m_mtx.unlock();
			printf("Uart Send buffer Complete \r\n");
		}
		else
            usleep(50);
    }
    return;
}

private:

    std::thread m_thread;
    SystemConfigInfo::SSystemConfig *pSystemConfigInfo;
    uint8_t 	nComFd;
	std::mutex m_mtx;
};

#endif