#include <include/udpclient.h>
#include <include/hardwareclient.h>
#include <include/common.h>

static uint8_t udp_rx_buffer[BUFF_CACHE_SIZE];
static uint8_t udp_tx_buffer[BUFF_CACHE_SIZE];

//主要为了完成信号槽链接的工作，而将对象初始化为全局变量
CUdpSocketInfo* CUdpSocketInfo::pCUdpSocketInfo = new CUdpSocketInfo(udp_rx_buffer, udp_tx_buffer, BUFF_CACHE_SIZE);

CUdpSocketInfo* CUdpSocketInfo::getUdpSocketInfoptr(){
    return pCUdpSocketInfo;
}



void CUdpSocketInfo::dataReceived()
{
    if(this->CheckReceiveData(true) == RT_OK)
    {
       if(pSendBufferInfo && pSendBufferInfo->m_pFunc != nullptr)
       {
            //emit send_edit_test(pSendBufferInfo->m_pFunc(m_pRxDataBuffer, m_RxBufSize-RECV_DATA_HEAD));
            emit send_hardware_status(m_pRxDataBuffer);
       }
    }
    m_pSemphore->release();
}



void CUdpSocketInfo::GetUDPOpen(QString SServerIpAddress, QString SLocalIpAddress, int nPort)
{
    m_nPort = nPort;
    if(!m_pServerIp->setAddress(SServerIpAddress)){
        qDebug()<<"SetAddress error\n";
    }

    if(!m_pLocalIp->setAddress(SLocalIpAddress)){
        qDebug()<<"SetAddress error\n";
    }

    //绑定到指定的UDP端口，并用于选择发送的网卡
    if(m_pUdpSocket->state() != QAbstractSocket::BoundState){
        //如果绑定本地端口失败e
        if(m_pUdpSocket->bind(*m_pLocalIp, UDP_DEFAULT_PORT) != true)
        {
            qDebug() << *m_pLocalIp << UDP_DEFAULT_PORT << m_pUdpSocket->state();
            emit send_edit_test(QString("Udp Bind Socket failed"));
        }
        else
            emit send_edit_test(QString("Udp Bind Socket successfully"));
    }
}

void CUdpSocketInfo::GetDevId(short Id){
     this->SetId(Id);
}

void CUdpSocketInfo::UdpClientSendFunc(SSendBuffer *pSendbuffer){
    quint16 nLen;

    if(pSendbuffer && pSendbuffer->m_nCommand != hardwareInfo::ABORT_CMD){
        pSendBufferInfo = pSendbuffer;
        nLen = CreateSendBuffer(this->GetId(), pSendbuffer->m_nSize,
                       pSendbuffer->m_pBuffer, pSendbuffer->m_IsWriteThrough);

        if(m_pUdpSocket->state() != QAbstractSocket::BoundState){
            qDebug() << "udp state error !";
            return;
        }

        this->DeviceWrite(tx_buffer, nLen);

        //emit send_edit_test(QString("Udp Socket Send Ok"));
        //通知主线程更新窗口
        //emit send_edit_test(byteArrayToHexString("Sendbuf:", tx_buffer, nLen, "\n"));

        //等待发送和接收完成
        m_pUdpSocket->waitForBytesWritten(1000);

        if(m_pUdpSocket->waitForReadyRead(10000))
            //if(m_pSemphore->tryAcquire(1, 10000))
                //qDebug()<<"Udpclient.cpp:Semphore Read";
            //else
            if(!m_pSemphore->tryAcquire(1, 10000))
                emit send_edit_test(QString("Udp Socket Semphore failed"));
//        else
//            emit send_edit_test(QString("Udp Socket Read Failed"));
    }
    else{
        if(!pSendbuffer) {
            qDebug("Send buffer is null");
            return ;
        }
        emit send_edit_test(QString("Udp Socket Close"));
        if(m_pUdpSocket->state() != QAbstractSocket::UnconnectedState)
        {
            qDebug()<<"Udp Socket abort";
            m_pUdpSocket->abort();
        }
    }
    return ;
}


