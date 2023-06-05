#include "include/sendthread.h"
#include <QDebug>


SendThread::SendThread(QObject *parent):QObject(parent)
{
    this->moveToThread(&m_thread);                          //定义一个QObject对象，并将其移到一个线程中执行
    connect(&m_thread,SIGNAL(started()),this,SLOT(InterfaceInitial()));
    m_pQueue = new CProtocolQueue();

    //tcp init
    pCTcpSocketInfo = CTcpSocketInfo::getTcpSocketInfoptr();
    pCTcpSocketInfo->moveToThread(&m_thread);
    qRegisterMetaType<SSendBuffer*>("SSendBuffer*");
    connect(this,SIGNAL(SetExecTCPSend(SSendBuffer*)),pCTcpSocketInfo,SLOT(TcpClientSendFunc(SSendBuffer *)));

    //udp init
    pCUdpSocketInfo = CUdpSocketInfo::getUdpSocketInfoptr();
    pCUdpSocketInfo->moveToThread(&m_thread);
    qRegisterMetaType<SSendBuffer*>("SSendBuffer*");
    connect(this,SIGNAL(SetExecUDPSend(SSendBuffer*)),pCUdpSocketInfo,SLOT(UdpClientSendFunc(SSendBuffer *)));

    //uart init
    pCUartInfo = CUartInfo::getUartInfoptr();
    pCUartInfo->moveToThread(&m_thread);
    qRegisterMetaType<SSendBuffer*>("SSendBuffer*");
    connect(this,SIGNAL(SetExecUARTSend(SSendBuffer*)),pCUartInfo,SLOT(UartClientSendFunc(SSendBuffer *)));
}

SendThread::~SendThread()
{
   delete  m_pQueue;
   m_pQueue = nullptr;     //delete pCTcpSocketInfo;
   delete pSendBuffer;
   pCTcpSocketInfo = nullptr;
   pCUdpSocketInfo = nullptr;
   pCUartInfo = nullptr;
   m_thread.exit();
   m_thread.wait();        //同步型线程设计，等待线程生命周期结束后再销毁此QObject对象
}
void SendThread::InterfaceInitial(){   //保证对象依附于sendthread
    pCTcpSocketInfo->InitTcpInfo();
    pCUdpSocketInfo->InitUdpInfo();
    pCUartInfo     ->InitUartInfo();
}
int SendThread::InterfaceProcess(SSendBuffer *SendBuffer)
{
        if(SendBuffer){
           if(SendBuffer->m_nProtocolStatus == PROTOCOL_UART)
               emit SetExecUARTSend(SendBuffer);
           else if(SendBuffer->m_nProtocolStatus == PROTOCOL_TCP)
               emit SetExecTCPSend(SendBuffer);
           else if(SendBuffer->m_nProtocolStatus == PROTOCOL_UDP)
               emit SetExecUDPSend(SendBuffer);
           else
               qDebug()<<"Invalid Protocol Type";
        }
        else
            return RT_EMPTY;


        return RT_FAIL;
}

void SendThread::GetSendBuff(SSendBuffer *buffer){
     if(m_pQueue && (m_pQueue->QueuePost(buffer) != QUEUE_INFO_OK)){    //添加一个消息进入消息队列
                 delete buffer;                                        //若添加不成功，删除掉已申请的缓冲区
                 return ;
     }

     //qDebug() << "SendThread start handle send message";
     int nStatus;
     SSendBuffer SendBufferInfo;

     nStatus = m_pQueue->QueuePend(&SendBufferInfo);     //取出要发送的消息
     if(nStatus == QUEUE_INFO_OK){
         if(SendBufferInfo.m_nCommand != hardwareInfo::SYSTEM_UPDATE_CMD){
             SendBufferInfo.m_bUploadStatus = false;
             InterfaceProcess(&SendBufferInfo);
         }
     }

     return;
}

void SendThread::FileUpdateProcess()
{

}


bool SendThread::trypause(){
     m_TryStopThreadLoop = true;
     return m_IsStopThreadLoop;
}

void SendThread::start()
{
    m_thread.start();     //默认调用run()方法并调用exec()方法，开启了线程的事件循环
}

void SendThread::terminate()
{
    m_thread.terminate();
}

void SendThread::exit(int c)
{
    m_thread.exit();
}


