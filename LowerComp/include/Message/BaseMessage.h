#ifndef _BASEMESSAGE_H
#define _BASEMESSAGE_H


#include <common/Typedef.h>

#define MAIN_BASE_MESSAGE                   1    
#define APP_BASE_MESSAGE                    2


class CBaseMessageInfo
{
public:
    CBaseMessageInfo(){};
   ~CBaseMessageInfo(){};

    /*通讯队列的创建*/
    virtual int CreateInfomation(void) = 0;     

    /*通讯队列的资源释放*/                            
    virtual int CloseInformation(uint8_t info) = 0;       

    /*等待通讯队列的数据接收*/                    
    virtual int WaitInformation(uint8_t info, char *buf, int bufsize) = 0;      
    
    /*向通讯队列投递数据*/    
    virtual int SendInformation(uint8_t info, char *buf, int bufsize, int prio) = 0;   

    static std::shared_ptr<CBaseMessageInfo> pSharedMqMessage;
};

#endif