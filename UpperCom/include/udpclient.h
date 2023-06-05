#ifndef UDPCLIENT_H
#define UDPCLIENT_H


#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include "protocol.h"

class CUdpSocketInfo:public QObject, public CProtocolInfo
{
    Q_OBJECT

public:
    CUdpSocketInfo(uint8_t *pRxBuffer, uint8_t *pTxBuffer, int nMaxBufSize):
        CProtocolInfo(pRxBuffer, pTxBuffer, nMaxBufSize){

        m_pSemphore = new QSemaphore(0);

        assert(pTxBuffer != nullptr);
        tx_buffer = pTxBuffer;

        assert(pRxBuffer != nullptr);
        rx_buffer = pRxBuffer;
    }
    ~CUdpSocketInfo(){
        m_pUdpSocket->deleteLater();
        delete rx_buffer;
        delete tx_buffer;
        delete m_pSemphore;
        delete m_pServerIp;
        delete pCUdpSocketInfo;
        pCUdpSocketInfo = nullptr;
    }
    int DeviceRead(uint8_t *pStart, uint16_t nMaxSize){
        uint16_t nReadSize = 0;

        if(m_pUdpSocket->hasPendingDatagrams())
            nReadSize = m_pUdpSocket->readDatagram((char*)pStart, nMaxSize, m_pServerIp, (quint16*)&m_nPort);

        return nReadSize;
    }
    int DeviceWrite(uint8_t *pStart, uint16_t nSize){
        return m_pUdpSocket->writeDatagram((char*)pStart, nSize, *m_pServerIp,(quint16)m_nPort);
    }

    static CUdpSocketInfo* getUdpSocketInfoptr();

    void InitUdpInfo(){
        m_pUdpSocket = new QUdpSocket();
        m_pServerIp = new QHostAddress();
        m_pLocalIp = new QHostAddress();
        connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    }


private:
    bool statue{false};
    QSemaphore *m_pSemphore;
    QUdpSocket *m_pUdpSocket;
    QHostAddress *m_pServerIp;
    QHostAddress *m_pLocalIp;
    int m_nPort;
    SSendBuffer *pSendBufferInfo;
    uint8_t *rx_buffer;
    uint8_t *tx_buffer;

    static CUdpSocketInfo* pCUdpSocketInfo;

signals:
    void send_edit_recv(QString);
    void send_edit_test(QString);
    void send_hardware_status(uint8_t* );

public slots:
    void GetUDPOpen(QString SServerIpAddress, QString SLocalIpAddress, int nPort);
    void GetUDPClose(){ m_pUdpSocket->abort();}
    void dataReceived();
    void UdpClientSendFunc(SSendBuffer *pSendbuffer);
    void GetDevId(short Id);          //从用户界面中获取设备Id号
};


#endif // UDPCLIENT_H
