#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H


#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QWidget>
#include "common.h"
#include "protocol.h"

//QObject不允许跨线程调用

class CTcpSocketInfo:public QObject, public CProtocolInfo
{
    Q_OBJECT

public:
    CTcpSocketInfo(uint8_t *pRxBuffer, uint8_t *pTxBuffer, int nMaxBufSize):
        CProtocolInfo(pRxBuffer, pTxBuffer, nMaxBufSize){
        m_pSemphore = new QSemaphore(0);

        assert(pTxBuffer != nullptr);
        tx_buffer = pTxBuffer;

        assert(pRxBuffer != nullptr);
        rx_buffer = pRxBuffer;
    }

    ~CTcpSocketInfo()
    {
        m_pTcpSocket->deleteLater();
        //m_pTcpSocket = nullptr;           //增加置nullptr?
        delete m_pSemphore;
        delete m_pServerIp;
        delete pSendBufferInfo;
        delete rx_buffer;
        delete tx_buffer;
        delete pCTcpSocketInfo;
        pCTcpSocketInfo = nullptr;
    }

    int DeviceRead(uint8_t *pStart, uint16_t nMaxSize) override{
        uint16_t nReadSize = 0;

        if(CTcpSocketInfo::m_pTcpSocket->bytesAvailable() > 0)
        {
          nReadSize = CTcpSocketInfo::m_pTcpSocket->read((char *)pStart, nMaxSize);
        }
        return nReadSize;
    }

    int DeviceWrite(uint8_t *pStart, uint16_t nSize) override{
        return CTcpSocketInfo::m_pTcpSocket->write((char *)pStart, nSize);
    }

    void InitTcpInfo(){
        m_pTcpSocket = new QTcpSocket();
        m_pServerIp = new QHostAddress();
        connect(m_pTcpSocket, SIGNAL(connected())   , this, SLOT(slotConnected()));
        connect(m_pTcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
        connect(m_pTcpSocket, SIGNAL(readyRead())   , this, SLOT(dataReceived()));
    }

    void SetSocketInfo(QString SIpAddress, int nPort)
    {

        if(!m_pServerIp->setAddress(SIpAddress)){
            qDebug()<<"SetAddress error\n";
        }
        m_nPort = nPort;
    }

    int IsTCPConnect(){
        return is_connect;
    }

    static CTcpSocketInfo* getTcpSocketInfoptr();


private:
    bool status{false};
    SSendBuffer *pSendBufferInfo;
    uint8_t *rx_buffer;
    uint8_t *tx_buffer;
    bool is_connect = false;
    QTcpSocket * m_pTcpSocket;
    QHostAddress * m_pServerIp;
    QSemaphore *m_pSemphore;
    int m_nPort;
    bool ifinitial = false;

    static CTcpSocketInfo* pCTcpSocketInfo;

signals:
    void send_edit_recv(QString);
    void send_edit_test(QString);


public slots:
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
    void GetDevId(short Id);          //从用户界面中获取设备Id号
    void GetTCPOpen(QString SIpAddr,int Port); //从用户界面中获取Socket信息
    void GetTCPClose();
    void TcpClientSendFunc(SSendBuffer *pSendbuffer);
};

#endif
