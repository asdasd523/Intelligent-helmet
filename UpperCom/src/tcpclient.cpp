#include "include/tcpclient.h"

static uint8_t tcp_rx_buffer[BUFF_CACHE_SIZE];
static uint8_t tcp_tx_buffer[BUFF_CACHE_SIZE];

//主要为了完成信号槽链接的工作，而将对象初始化为全局变量
CTcpSocketInfo* CTcpSocketInfo::pCTcpSocketInfo = new CTcpSocketInfo(tcp_rx_buffer, tcp_tx_buffer, BUFF_CACHE_SIZE);

CTcpSocketInfo* CTcpSocketInfo::getTcpSocketInfoptr(){
    return pCTcpSocketInfo;
}


/*!
    Socket连接时执行的槽函数
*/
void CTcpSocketInfo::slotConnected()
{
    qDebug()<<"Tcpclient.cpp:Socket Connect";
}

/*!
    Socket断开时执行的槽函数
*/
void CTcpSocketInfo::slotDisconnected()
{
    qDebug()<<"Tcpclient.cpp:Socket Disconnected";
}

/*!
    Tcp Socket数据接收时执行的回调函数
*/
void CTcpSocketInfo::dataReceived()
{
    if(this->CheckReceiveData(false) == RT_OK){
       #if TEST_DEBUG == 1
       emit send_edit_test(byteArrayToHexString("Server Recv Buf:",m_pRxBuffer, m_RxBufSize, "\n"));
       #endif

       //增加判断pSendBufferInfo指针是否为空
       if(pSendBufferInfo && pSendBufferInfo->m_pFunc != nullptr){
           emit send_edit_recv(pSendBufferInfo->m_pFunc(m_pRxDataBuffer, m_RxBufSize-RECV_DATA_HEAD));
       }

    }
    m_pSemphore->release(1);          //释放1个信号量,维护的信号量加1
}


/*!
    Tcp Socket循环的应用执行
*/
void CTcpSocketInfo::TcpClientSendFunc(SSendBuffer *pSendbuffer)
{
    if(!pSendbuffer)  return ;       //发送buff为空
    int nLen;

    pSendBufferInfo = pSendbuffer;
    nLen = this->CreateSendBuffer(this->GetId(), pSendbuffer->m_nSize,
                                  pSendbuffer->m_pBuffer, pSendbuffer->m_IsWriteThrough);

//    if(pSendBufferInfo->m_bUploadStatus == false){

//    }
    if(is_connect){
//        #if TEST_DEBUG == 1
//        emit send_edit_test(QString("tcp socket client ok"));
//        #endif
        this->DeviceWrite(tx_buffer, nLen);
        //通知主线程更新窗口
        #if TEST_DEBUG == 1
        emit send_edit_test(byteArrayToHexString("Sendbuf:", tx_buffer, nLen, "\n"));
        #endif

        //等待发送和接收完成
        m_pTcpSocket->waitForBytesWritten(1000);

        if(pSendBufferInfo->m_bUploadStatus)
            m_pTcpSocket->waitForReadyRead();
        else
            m_pTcpSocket->waitForReadyRead(2000);

        if(m_pSemphore->tryAcquire(1, 10000))    //acquire the Sem,receive callback is completed
        {
            #if TEST_DEBUG == 1
            qDebug()<<"Receive Callback is Completed";
            #endif
        }
        else
        {
            #if TEST_DEBUG == 1
            qDebug()<<"Semphore Acquire Failed";
            #endif
        }
    }
    else
    {
        emit send_edit_test(QString("socket client fail\n"));
        return ;
    }
    //return RT_OK;
}

void CTcpSocketInfo::GetDevId(short Id){
     this->SetId(Id);
}

void CTcpSocketInfo::GetTCPOpen(QString SIpAddr,int Port){
    if(!m_pTcpSocket || !m_pServerIp) return;

     qDebug() << "TCPOpen:" << QThread::currentThread();

     this->SetSocketInfo(SIpAddr,Port);

     if(m_pTcpSocket->state() != QAbstractSocket::ConnectedState){
            m_pTcpSocket->connectToHost(*m_pServerIp, m_nPort);
            is_connect = m_pTcpSocket->waitForConnected(10000);
            if(!is_connect)
                 emit send_edit_test(QString("trying to connect to server failed\n"));
            else
                 emit send_edit_test(QString("connect to server successfully\n"));
     }
     else
            is_connect = true;
}

void CTcpSocketInfo::GetTCPClose(){
    if(m_pTcpSocket->state() == QAbstractSocket::ConnectedState){
          m_pTcpSocket->disconnectFromHost();
          this->m_pQueue->clear();
          is_connect = false;
    }
    else{
          qDebug() << "TCP Connection is already closed";
    }
}

