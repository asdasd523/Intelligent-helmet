#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <functional>
#include <QStringList>
#include <QThread>
#include <QTimer>
#include "include/tcpclient.h"
#include "include/typedef.h"
#include "include/common.h"
#include "include/hardwareclient.h"
#include "include/config.h"
#include "include/sendthread.h"
#include "include/udpclient.h"
#include "include/uartclient.h"
#include "include/gpsinfownd.h"
#include "include/hygrownd.h"
#include "include/thermwnd.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialize();
    void init_btn_disable();
    void init_btn_enable();
    void CmdSendBuffer(uint8_t *pStart, uint16_t nSize, int nCommand, bool isThrough,
                       std::function<QString(uint8_t *, int)> pfunc,PROTOCOL_STATUS nProtocolStatus = PROTOCOL_TCP, QString pathInfo = nullptr);
    void update_system_config(void);


public slots:
    void append_text_edit_recv(QString s);
    void append_text_edit_test(QString s);
    void on_btn_send_cmd_clicked(void);
    void on_btn_socket_open_clicked(void);
    void on_btn_socket_close_clicked(void);
    void on_btn_uart_close_clicked();
    void on_btn_uart_open_clicked();
    void on_btn_clear_clicked();
    void on_btn_led_on_clicked();
    void on_btn_led_off_clicked();
    void on_btn_refresh_clicked();
    void getHWStatusRefresh();
    void recv_hardware_status(uint8_t*);

signals:
    void SetDevId(short);
    void SetTCPOpen(QString , int);
    void SetTCPClose();
    void SetUDPOpen(QString ,QString, int);
    void SetUDPClose();
    void SetUARTOpen(CUartInfo::UartInfo_t * Info);
    void SetUARTClose();
    void SetSendBuff(SSendBuffer *);
    void Set_thermWnd_update(qreal);
    void Set_hygroWnd_update(qreal);
    void Set_gpsWnd_update(hardwareInfo::GPS_Data);
    void Set_locating_alert();


private:
    Ui::MainWindow *ui;

    CTcpSocketInfo* pCTcpSocketInfo;
    CUdpSocketInfo* pCUdpSocketInfo;
    CUartInfo* pCUartInfo;
    hardwareInfo* pHWInfo;
    SSystemConfig *pSystemConfigInfo;
    SendThread * sendThread;


    PROTOCOL_STATUS protocol_flag;
    volatile bool m_IsStopThread;

    GPSInfoWnd* GPSWnd;
    ThermWnd* thermWnd;
    HygroWnd* hygroWnd;
    QTimer timer;
    int Timerinterval = 100;


};

#endif // MAINWINDOW_H
