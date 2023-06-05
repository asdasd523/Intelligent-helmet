#ifndef UARTCLIENT_H
#define UARTCLIENT_H

#include "protocol.h"
#include <QObject>
#include <QtSerialPort/QtSerialPort>


//name:ttyUSB1
class CUartInfo:public QObject, public CProtocolInfo
{
    Q_OBJECT

public:
    struct UartInfo_t{
        QString PortName;
        qint32 BaudRate;
        QSerialPort::DataBits DataBits;
        QSerialPort::StopBits StopBits;
        QSerialPort::Parity Parity;
    };
    CUartInfo(uint8_t *pRxBuffer, uint8_t *pTxBuffer, int nMaxBufSize):
        CProtocolInfo(pRxBuffer, pTxBuffer, nMaxBufSize){

        m_pSemphore = new QSemaphore(0);

        assert(pTxBuffer != nullptr);
        tx_buffer = pTxBuffer;

        assert(pRxBuffer != nullptr);
        rx_buffer = pRxBuffer;
    }

    ~CUartInfo(){
        m_serial->deleteLater();
        delete rx_buffer;
        delete tx_buffer;
    }

    void InitUartInfo(){
        m_serial = new QSerialPort;
        connect(m_serial,&QSerialPort::readyRead,this,&CUartInfo::dataReceived,Qt::QueuedConnection);
    }

    int DeviceRead(uint8_t *pStart, uint16_t nMaxSize){
        return m_serial->read((char*)pStart,nMaxSize);
    }

    int DeviceWrite(uint8_t *pStart, uint16_t nMaxSize){
        return m_serial->write((char*)pStart,nMaxSize);
    }

    bool IsOpen(){ return isOpen;}

    static CUartInfo* getUartInfoptr();

    void InitUdpInfo(){

    }


signals:
    void send_edit_recv(QString);
    void send_edit_test(QString);


public slots:
    void GetUARTOpen(CUartInfo::UartInfo_t *Info);
    void GetUARTClose();
    void dataReceived();
    void GetDevId(short Id);          //从用户界面中获取设备Id号
    void UartClientSendFunc(SSendBuffer *);

private:
    uint8_t *rx_buffer;
    uint8_t *tx_buffer;
    QSemaphore *m_pSemphore;
    QSerialPort *m_serial = nullptr;
    SSendBuffer *pSendBufferInfo;
    bool isOpen = false;

    static CUartInfo* pCUartInfo;
};

#endif // UARTCLIENT_H
