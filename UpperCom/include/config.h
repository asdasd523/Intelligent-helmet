#ifndef CONFIG_H
#define CONFIG_H

#include "typedef.h"

struct SSystemConfig{
   //串口相关
    QString m_SCom{"COM1"};
    QString m_SBaud{"115200"};
    QString m_SDataBits{"8"};
    QString m_SStopBits{"1"};
    QString m_SParity{"N"};

    //设备ID
    QString m_SDeviceID{"1"};

    //网络Socket相关
    QString m_SProtocol{"TCP"};
    QString m_SIpAddr{"127.0.0.1"};
    QString m_SLocalIpAddr{"127.0.0.1"};
    QString m_STCPPort{"8000"};
    QString m_SUDPPort{"8001"};
    QString m_SLocalPort{"8100"};
};

void SystemConfigUpdate(void);
void SystemConfigInfoInit(void);
SSystemConfig *GetSystemConfigInfo(void);

#endif // CONFIG_H
