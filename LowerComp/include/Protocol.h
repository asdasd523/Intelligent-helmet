#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <common/Typedef.h>
#include <Message/MqMessage.h>
#include <Message/FifoMessage.h>
#include <Message/CalCRC16.h>
#include <SystemConfig.h>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <memory>
#include <hardwareserver.h>

/*协议数据长度*/
#define FRAME_HEAD_SIZE			3   //协议头数据的宽度
#define EXTRA_HEAD_SIZE			3   //设备号加随机数数据宽度
#define CRC_SIZE				2   //CRC数据的长度 

/*协议数据格式*/
#define PROTOCOL_REQ_HEAD  		0x5A	/*协议数据头*/
#define PROTOCOL_ACK_HEAD		0x5B	/*应答数据头*/

/*设备操作指令*/
#define CMD_REG_READ 			0x01    /*读寄存器*/
#define CMD_REG_WRITE			0x02	/*写寄存器*/
#define CMD_UPLOAD_CMD			0x03	/*上传指令*/
#define CMD_UPLOAD_DATA			0x04	/*上传数据*/

/*设备应答指令*/
#define ACK_OK					0x00
#define ACK_INVALID_CMD			0x01
#define ACK_OTHER_ERR			0xff

#define DEFAULT_CRC_VALUE		0xFFFF


#define BIG_ENDING      0


#if BIG_ENDING == 1
     #define LENGTH_CONVERT(val)	(val)
#else
     #define LENGTH_CONVERT(val) (((val)<<8) |((val)>>8))
#endif


/*协议文件的头格式*/
#pragma pack(push, 1)   //先将当前字节对齐值压入编译栈栈顶, 然后再将 1 设为当前值
struct req_frame{
    uint8_t head;
    uint16_t length;
};
#pragma pack(pop)       //将编译栈栈顶的字节对齐值弹出并设为当前值.

class CHardWareServer;

template<class T>
class CProtocolInfo{

public:
/**
	 * 内部数据构造函数
	 * 
	 * @param pRxCachebuf  接收数据缓存首地址指针
	 * @param pTxCacheBuf  发送数据缓存首地址指针
	 * @param pRxData      接收到有效数据的首地址
	 * @param nMaxSize     最大缓存数据长度
	 *  
	 * @return NULL
*/   
    CProtocolInfo(uint8_t *pRxCachebuf, uint8_t *pTxCacheBuf, uint16_t nMaxSize){
		m_RxCachePtr = pRxCachebuf;
		m_TxCachePtr = pTxCacheBuf;
		m_RxCacheDataPtr = &pRxCachebuf[FRAME_HEAD_SIZE+EXTRA_HEAD_SIZE];
		m_RxBufSize = 0;
		m_TxBufSize = 0;
		m_PacketNum = 0;
		m_RxDataSize = 0;
		m_MaxCacheBufSize = nMaxSize;
		m_PacketNum = 0;
		m_RxTimeout = 0;          
    };

    ~CProtocolInfo(void) {}

	/**
	 * 判断路径是否存在，不存在则创建路径
	 * 
	 * @param fd 执行的设备ID号
	 *  
	 * @return 执行执行的结果
	 */
	int dir_process(const char *pDirPath)
	{
       DIR* pDirInfo;
       if(pDirPath == nullptr)
           return -1;
       else if((pDirInfo = opendir(pDirPath)) != nullptr)
           closedir(pDirInfo);            //判断目录是否存在，存在那么关闭信息，避免泄漏
       else 
           mkdir(pDirPath,0775);
       return 0; 
    }

	/**
	 * 执行具体的指令,生成发送缓冲区数据
	 * 
	 * @param fd 执行的设备ID号
	 *  
	 * @return 执行执行的结果
	 */
     int ExecuteCommand(int fd){
           uint8_t nCommand;
           uint16_t nRegIndex, nRxDataSize;
           //char buf = 1;
		   char buf = 1;
		   std::shared_ptr<SystemConfigInfo::SSystemConfig> ExepSSystemConfig(SystemConfigInfo::pShardSystemConfig);
		   std::unique_ptr<uint8_t[]> uq_reg(new uint8_t[nRxDataSize]);
		   std::shared_ptr<CBaseMessageInfo> pMessageInfo = CBaseMessageInfo::pSharedMqMessage;
		   std::shared_ptr<CHardWareServer> pHardWareReg = CHardWareServer::pSharedHardWareServ;

		   m_TxBufSize = 0;

		   nCommand = m_RxCacheDataPtr[0];

		   switch(nCommand){
			   case CMD_REG_READ:
					nRegIndex   = m_RxCacheDataPtr[1] << 8 | m_RxCacheDataPtr[2];
					nRxDataSize = m_RxCacheDataPtr[3] << 8 | m_RxCacheDataPtr[4];	
					pHardWareReg->GetMultipleReg(nRegIndex, nRxDataSize, uq_reg.get());
					pMessageInfo->SendInformation((int)APP_BASE_MESSAGE, &buf, sizeof(buf), 0);
					m_isUploadStatus = false;
					m_TxBufSize = CreateTxBuffer(ACK_OK, nRxDataSize, uq_reg.get());
					break;
			   case CMD_REG_WRITE:   //写入硬件服务器的数据缓冲区
					nRegIndex   = m_RxCacheDataPtr[1]<<8 | m_RxCacheDataPtr[2];
					nRxDataSize = m_RxCacheDataPtr[3]<<8 | m_RxCacheDataPtr[4];
					pHardWareReg->SetMultipleReg(nRegIndex, nRxDataSize, &m_RxCacheDataPtr[5]);
					pMessageInfo->SendInformation(APP_BASE_MESSAGE, &buf, sizeof(buf), 0);
					m_isUploadStatus = false;
					m_TxBufSize = CreateTxBuffer(ACK_OK, 0, NULL);
					pHardWareReg->DataModified_fromUpper();   //置位Data标志
					break;
			//    case CMD_UPLOAD_CMD:
			// 	    break;
			//    case CMD_UPLOAD_DATA:
			// 	    break;
			   default:
				   m_isUploadStatus = false;
				   m_TxBufSize = CreateTxBuffer(ACK_OK, 0, nullptr);
				   break;
			   }

		   m_RxBufSize = 0;
		   return RT_OK;
	 }

	/**
	 * 接收数据以及校验
	 * 
	 * @param nFd 访问设备的ID
	 * @param IsSignalCheckHead bool型，兼容UDP的接收实现，UDP协议不支持分片的数据接收
	 * @param ExtraInfo 兼容UDP的接收实现，需要额外的信息处理
	 *  
	 * @return 接收数据和校验的结果
	 */
    int CheckRxBuffer(int nFd, bool IsSignalCheckHead, T ExtraInfo){
        int nread;
        int CrcRecv, CrcCacl;
        req_frame *frame_ptr;
        frame_ptr = (struct req_frame *)m_RxCachePtr;

		//数据包头的处理
		if(m_RxBufSize == 0 && !IsSignalCheckHead){
			//printf("i am waiting for message.... \r\n");
        while(1){
			nread = DeviceRead(nFd, &m_RxCachePtr[m_RxBufSize], 1, ExtraInfo); //读取报头确认报头后开始解析数据
			if (nread > 0 && frame_ptr->head == PROTOCOL_REQ_HEAD)
			{ //确认报头后开始解析数据
				m_RxBufSize++; 
                m_RxTimeout = 0;
				break;
			}
			else if(nread < 0){
                m_RxBufSize = 0;
				return RT_FAIL;
			}
            else{
                m_RxBufSize = 0;
                return RT_EMPTY;
            }
		}
        }
        //数据包解析
		if(m_RxBufSize > 0 || IsSignalCheckHead == true){
            /*从设备中读取数据*/
            nread = DeviceRead(nFd, &m_RxCachePtr[m_RxBufSize], 
                               (m_MaxCacheBufSize-m_RxBufSize), ExtraInfo);   //通信成功，返回其copy的字节数
            if(nread > 0){
                  if(IsSignalCheckHead && frame_ptr->head != PROTOCOL_REQ_HEAD){
                      usleep(1);
                      m_RxBufSize = 0;
                      return RT_FAIL;
                  }
  
                  m_RxTimeout = 0;
                  m_RxBufSize += nread;

                  /*已经接收到指定长度的数据*/
                  if(m_RxBufSize >= FRAME_HEAD_SIZE){
                       int nLen;
 
                       /*获取到接收的数据的总长度*/
                       m_RxDataSize = LENGTH_CONVERT(frame_ptr->length)-3;  //m_RxBufSize -> m_RxDataSize

                       /*获取数据的长度*/
                       nLen = m_RxDataSize + FRAME_HEAD_SIZE + CRC_SIZE + EXTRA_HEAD_SIZE;

					   /*CRC 冗余校验*/
                       if(m_RxBufSize >= nLen){
                            /*计算head后到CRC尾之前的所有数据的CRC值*/
                            CrcRecv = (m_RxCachePtr[m_RxBufSize-2]<<8) + m_RxCachePtr[m_RxBufSize-1];
                            CrcCacl = CrcCalculate(&m_RxCachePtr[1],m_RxBufSize-1-CRC_SIZE);
                            if(CrcRecv == CrcCacl){
                                 if(m_RxCachePtr[3] != DEVICE_ID){
								    USR_DEBUG("Device ID Error:%d\n", m_RxCachePtr[3]);
								    return RT_INVALID;
                                 }
                                 m_PacketNum = m_RxCachePtr[4] << 8 | m_RxCachePtr[5];
                                 return RT_OK;
                            }
                            else{
								 m_RxBufSize = 0;
							     USR_DEBUG("CRC Check ERROR!. rx_data:%d, r:%d, c:%d\n", m_RxDataSize, CrcRecv, CrcCacl);
							     return RT_INVALID;                                
                            }
                       }
                  }
            }
            else{
                  usleep(1);
                  m_RxTimeout++;
                  if(m_RxTimeout > 4000){
                      m_RxBufSize = 0;
                      m_RxTimeout = 0;
                      USR_DEBUG("Recv RxTimeout\n");
                  }
            }

        }

        return RT_EMPTY;       
    }    

	/**
	 * 提交数据到上位机
	 * 
	 * @param fd 执行的设备ID号
	 *  
	 * @return 执行执行的结果
	 */
    int SendTxBuffer(int nFd,T ExtraInfo) {
		//printf("send buffer:");
		//SystemLogArray(m_TxCachePtr, m_TxBufSize); //在服务器终端打印发送的数据
		return DeviceWrite(nFd, m_TxCachePtr, m_TxBufSize, ExtraInfo);  
    }

	/**
	 * 生成发送的数据包格式
	 * 
	 * @param nAck      应答数据的状态
	 * @param nDataSize 应答有效数据的长度
	 * @param pData     应答有效数据的首指针
	 *  
	 * @return 执行执行的结果
	 */
    int CreateTxBuffer(uint8_t nAck, uint16_t nDataSize, uint8_t *pData){
         uint8_t nOutSize, nIndex;
         uint16_t nCrcCalc;
         uint16_t nBufSize;

         nBufSize = nDataSize+4;
         nOutSize = 0;
		 m_TxCachePtr[nOutSize++] = PROTOCOL_ACK_HEAD;
		 m_TxCachePtr[nOutSize++] = (uint8_t)(nBufSize>>8);
		 m_TxCachePtr[nOutSize++] = (uint8_t)(nBufSize&0xff);	
		 m_TxCachePtr[nOutSize++] = DEVICE_ID;
		 m_TxCachePtr[nOutSize++] = (uint8_t)(m_PacketNum>>8);
		 m_TxCachePtr[nOutSize++] = (uint8_t)(m_PacketNum&0xff);
		 m_TxCachePtr[nOutSize++] = nAck;

		if(nDataSize != 0 && pData != NULL)
		{
			for(nIndex=0; nIndex<nDataSize; nIndex++)
			{
				m_TxCachePtr[nOutSize++] = *(pData+nIndex);
			}
		}

		nCrcCalc = CrcCalculate(&m_TxCachePtr[1], nOutSize-1);
		m_TxCachePtr[nOutSize++] = (uint8_t)(nCrcCalc>>8);
		m_TxCachePtr[nOutSize++] = (uint8_t)(nCrcCalc&0xff);	

		return nOutSize;         
    }



	/**
	 * CRC16计算实现
	 * 
	 * @param pDataStart 计算CRC数据的首地址
	 * @param nDataSize  计算CRC数据的长度
	 *  
	 * @return NULL
	 */
	uint16_t CrcCalculate(uint8_t *pDataStart, uint16_t nDataSize)
	{
		uint16_t nCrcOut;

		assert(pDataStart != nullptr);
		nCrcOut = crc16(DEFAULT_CRC_VALUE, pDataStart, nDataSize);
		return nCrcOut;
	}	

	/**
	 * 获取文件上传状态
	 * 
	 * @param NULL
	 *  
	 * @return 文件上传状态
	 */
	bool GetFileUploadStatus(void)
	{
		return m_isUploadStatus;
	}

	/*设备读写函数，因为不同设备的实现可能不同，用纯虚函数*/
	virtual int DeviceRead(int nFd, uint8_t *pDataStart, uint16_t nDataSize, T ExtraInfo)=0;  
	virtual int DeviceWrite(int nFd, uint8_t *pDataStart, uint16_t nDataSize, T ExtraInfo)=0;


private:
	uint8_t *m_RxCachePtr;       	//接收数据首指针
	uint8_t *m_TxCachePtr;	   		//发送数据首指针
	uint8_t *m_RxCacheDataPtr;  	//接收数据数据段首指针
	uint16_t m_RxBufSize;	   		//接收数据长度
	uint16_t m_TxBufSize;      		//发送数据长度
	uint16_t m_RxDataSize; 			//接收数据数据段长度
	uint16_t m_MaxCacheBufSize;  	//最大的数据长度
	uint16_t m_PacketNum;	  		//数据包的编号,用于数据校验同步
	uint32_t m_RxTimeout; 			//超时时间
	uint16_t m_FileSize;			//文件的总长度
	uint16_t m_FileBlock;           //文件的总块数
	bool  m_isUploadStatus;			//文件传输模式
	std::string m_FileName;
};

#endif