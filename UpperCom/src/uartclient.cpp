#include <include/uartclient.h>
#include <include/hardwareclient.h>
#include <include/common.h>

static uint8_t uart_rx_buffer[BUFF_CACHE_SIZE];
static uint8_t uart_tx_buffer[BUFF_CACHE_SIZE];

//主要为了完成信号槽链接的工作，而将对象初始化为全局变量

CUartInfo* CUartInfo::pCUartInfo = new CUartInfo(uart_rx_buffer, uart_tx_buffer, BUFF_CACHE_SIZE);

CUartInfo* CUartInfo::getUartInfoptr(){
    return pCUartInfo;
}

void CUartInfo::GetUARTOpen(CUartInfo::UartInfo_t *Info)
{
    m_serial->setBaudRate(Info->BaudRate);
    m_serial->setDataBits(Info->DataBits);
    m_serial->setParity(Info->Parity);
    m_serial->setPortName(Info->PortName);
    m_serial->setStopBits(Info->StopBits);

    int count = 0;
    while(!m_serial->open(QIODevice::ReadWrite)){
        if(count++ == 5){
            qDebug() << "open serial port error:" << m_serial->error();
            return;
        }
    }
    m_serial->clear();

    isOpen = true;
}

void CUartInfo::GetUARTClose()
{
    m_serial->close();
    isOpen = false;
}

void CUartInfo::dataReceived()
{
    if(m_serial->bytesAvailable() >= 9){             //每次接收到一个字节的数据都会调用此槽函数
        if(this->CheckReceiveData(false) == RT_OK)   //false
        {
           emit send_edit_test(byteArrayToHexString("Recv Buf:",
                m_pRxBuffer, m_RxBufSize, "\n"));
           if(pSendBufferInfo && pSendBufferInfo->m_pFunc != nullptr)
                emit send_edit_recv(pSendBufferInfo->m_pFunc(m_pRxDataBuffer, m_RxBufSize-RECV_DATA_HEAD));

           emit send_edit_test(QString("Uart Recv Ok"));

           m_pSemphore->release();
        }
        else
        {
           emit send_edit_test(QString("Receive Failed"));
           return ;
        }

       m_pSemphore->release();
    }
}

void CUartInfo::GetDevId(short Id)
{
    this->SetId(Id);
}

void CUartInfo::UartClientSendFunc(SSendBuffer *pSendbuffer)
{
    int nLen;

    if(isOpen && pSendbuffer){
        pSendBufferInfo = pSendbuffer;

        nLen = this->CreateSendBuffer(this->GetId(), pSendbuffer->m_nSize,
                                      pSendbuffer->m_pBuffer, pSendbuffer->m_IsWriteThrough);
        this->DeviceWrite(tx_buffer, nLen);

        emit send_edit_test(byteArrayToHexString("Sendbuf:", tx_buffer, nLen, "\n"));

        m_serial->waitForBytesWritten(10000);

        if(m_serial->waitForReadyRead(100))
            if(m_pSemphore->tryAcquire(1, 10000))
                qDebug()<<"Uartclient.cpp:Semphore Read";
            else
                emit send_edit_test(QString("Uart Semphore failed"));
        else
            emit send_edit_test(QString("Uart Read Failed"));
    }
    else{
        if(!pSendbuffer) {
            qDebug("Send buffer is null");
            return ;
        }
    }
}














