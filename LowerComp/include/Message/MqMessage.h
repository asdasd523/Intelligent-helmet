#ifndef MQMESSAGE_H
#define MQMESSAGE_H

#include <common/Typedef.h>
#include <Message/BaseMessage.h>
#include <mqueue.h>              //队列文件?


/**************************************************************************
* Global Macro Definition
***************************************************************************/
#define MAIN_MQ       MAIN_BASE_MESSAGE
#define APP_MQ        APP_BASE_MESSAGE

/**************************************************************************
* Global Type Definition
***************************************************************************/
class CMqMessageInfo:public CBaseMessageInfo
{
public:
    CMqMessageInfo():CBaseMessageInfo(){

    };
    ~CMqMessageInfo(){};

    /*创建并打开消息队列*/
    int CreateInfomation(void) override;                                     

    /*释放消息队列*/
    int CloseInformation(uint8_t info) override;                            

    /*向消息队列投递消息*/
    int WaitInformation(uint8_t info, char *buf, int bufsize) override;       

    /*发送数据给消息队列*/
    int SendInformation(uint8_t info, char *buf, int bufsize, int prio) override; 


private:
    
    /*主消息队列描述符*/
    mqd_t m_MainMqd{-1};

    /*应用消息队列描述符*/
    mqd_t m_AppMqd{-1};
};


#endif