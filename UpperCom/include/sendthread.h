#ifndef APPTHREAD_H
#define APPTHREAD_H

#include <QThread>
#include "protocol.h"
#include "common.h"
#include "tcpclient.h"
#include "typedef.h"
#include "protocol.h"
#include "hardwareclient.h"
#include "udpclient.h"
#include "uartclient.h"


class SendThread:public QObject{

    Q_OBJECT

protected slots:
    void GetSendBuff(SSendBuffer *buffer);  //从用户界面获取发送的指令
    void InterfaceInitial();

public:
    explicit SendThread(QObject* parent = 0);
    ~SendThread();

    int  InterfaceProcess(SSendBuffer *SendBuffer);    //单次通讯的线程执行
    void FileUpdateProcess(void);  //用于文件传输的处理
    void start();
    void terminate();
    void exit(int c = 0);
    bool trypause();



signals:
    void SetExecTCPSend(SSendBuffer *);
    void SetExecUDPSend(SSendBuffer *);
    void SetExecUARTSend(SSendBuffer *);


private:
    QThread m_thread;
    CTcpSocketInfo* pCTcpSocketInfo;
    CUdpSocketInfo* pCUdpSocketInfo;
    CUartInfo* pCUartInfo;
    CProtocolQueue* m_pQueue;
    SSendBuffer * pSendBuffer;
    QSemaphore *pTcp_InitSem;
    volatile bool m_TryStopThreadLoop   = false;
    volatile bool m_IsStopThreadLoop    = false;


};

#endif // APPTHREAD_H
