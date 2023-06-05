#ifndef FIFOMESSAGE_H
#define FIFOMESSAGE_H

/*
 * File      : FifoManage.h
 * 命名管道管理接口
*/


#include <common/Typedef.h>
#include <Message/BaseMessage.h>
#include <mqueue.h>            

#define MAIN_FIFO        MAIN_BASE_MESSAGE
#define APP_FIFO         APP_BASE_MESSAGE

class CFifoManageInfo:public CBaseMessageInfo
{
public:
    CFifoManageInfo():CBaseMessageInfo(){};
        ~CFifoManageInfo(){};

    /*创建并打开FIFO*/
    int CreateInfomation(void) override;                        

    /*关闭FIFO并释放资源*/
    int CloseInformation(uint8_t info) override;         
    
    /*等待FIFO数据接收*/
    int WaitInformation(uint8_t info, char *buf, int bufsize) override;              

    /*向FIFO中投递数据*/
    int SendInformation(uint8_t info, char *buf, int bufsize, int prio) override;  

private:

    /*主FIFO读描述符*/
    int m_rfd_main{-1};

    /*主FIFO写描述符*/
    int m_wfd_main{-1};

    /*应用FIFO读描述符*/
    int m_rfd_app{-1};

    /*应用FIFO写描述符*/
    int m_wfd_app{-1};
};




#endif