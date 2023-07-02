#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "include/protocol.h"
#include "include/tcpclient.h"
#include <QDir>
#include <QFileDialog>
#include <QRandomGenerator>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pSystemConfigInfo;
    pCTcpSocketInfo = nullptr;
    delete sendThread;
}


/*!
    界面窗口的初始化
    完成Uart应用, Tcp Socket应用的初始化
*/
void MainWindow::initialize()
{
    SystemConfigInfoInit();
    pSystemConfigInfo = GetSystemConfigInfo();

    //设置table的分页参数  Device
    ui->tabWidget->setCurrentIndex(1);

    //设置协议类型
//    QStringList SocketTypeList;
//    SocketTypeList<<"TCP"<<"UDP";
//    ui->combo_box_socket_type->addItems(SocketTypeList);
//    ui->combo_box_socket_type->setCurrentIndex(ui->combo_box_socket_type->findText(pSystemConfigInfo->m_SProtocol));

    //设置网络相关的配置
    ui->line_edit_ipaddr->setText      (pSystemConfigInfo->m_SIpAddr);
    ui->line_edit_local_ipaddr->setText(pSystemConfigInfo->m_SLocalIpAddr);
    ui->tcp_port->setText              (pSystemConfigInfo->m_STCPPort);
    ui->udp_port->setText              (pSystemConfigInfo->m_SUDPPort);

    //添加Uart相关设置
    //添加COM口
    QStringList comList;
    comList << "/dev/ttyUSB1";
    ui->combo_box_com->addItems(comList);
    ui->combo_box_com->setCurrentIndex(ui->combo_box_com->findText(pSystemConfigInfo->m_SCom));

    //波特率选项
    QStringList BaudList;
    BaudList << "9600" << "38400" << "76800" << "115200" << "230400";
    ui->combo_box_baud->addItems(BaudList);
    ui->combo_box_baud->setCurrentIndex(ui->combo_box_baud->findText(pSystemConfigInfo->m_SBaud));

    //数据位选项
    QStringList dataBitsList;
    dataBitsList << "6" << "7" << "8" << "9";
    ui->combo_box_data->addItems(dataBitsList);
    ui->combo_box_data->setCurrentIndex(ui->combo_box_data->findText(pSystemConfigInfo->m_SDataBits));

    //停止位选项
    QStringList StopBitsList;
    StopBitsList<<"1"<<"2";
    ui->combo_box_stop->addItems(StopBitsList);
    ui->combo_box_stop->setCurrentIndex(ui->combo_box_stop->findText(pSystemConfigInfo->m_SStopBits));

    //校验位
    QStringList ParityList;
    ParityList<<"N"<<"Odd"<<"Even";
    ui->combo_box_parity->addItems(ParityList);
    ui->combo_box_parity->setCurrentIndex(ui->combo_box_parity->findText(pSystemConfigInfo->m_SParity));

    //默认按键配置不可操作
    init_btn_disable();
    ui->btn_socket_close->setDisabled(true);

    //qDebug() << "main:" << this->thread();

    //Thread init
    sendThread = new SendThread();    //用movetothread不允许接parent
    qRegisterMetaType<SSendBuffer*>("SSendBuffer*");
    connect(this,SIGNAL(SetSendBuff(SSendBuffer*)),sendThread,SLOT(GetSendBuff(SSendBuffer *)),Qt::QueuedConnection);

    //tcp init
    pCTcpSocketInfo = CTcpSocketInfo::getTcpSocketInfoptr();
    connect(pCTcpSocketInfo, SIGNAL(send_edit_recv(QString)), this, SLOT(append_text_edit_recv(QString)),Qt::QueuedConnection);
    connect(pCTcpSocketInfo, SIGNAL(send_edit_test(QString)), this, SLOT(append_text_edit_test(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetDevId(short)),pCTcpSocketInfo,SLOT(GetDevId(short)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetTCPOpen(QString , int)),pCTcpSocketInfo,SLOT(GetTCPOpen(QString ,int)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetTCPClose()),pCTcpSocketInfo,SLOT(GetTCPClose()),Qt::QueuedConnection);


    //udp init
    pCUdpSocketInfo = CUdpSocketInfo::getUdpSocketInfoptr();
    connect(pCUdpSocketInfo, SIGNAL(send_edit_recv(QString)), this, SLOT(append_text_edit_recv(QString)),Qt::QueuedConnection);
    connect(pCUdpSocketInfo, SIGNAL(send_edit_test(QString)), this, SLOT(append_text_edit_test(QString)),Qt::QueuedConnection);
    qRegisterMetaType<uint8_t*>("uint8_t*");
    connect(pCUdpSocketInfo,SIGNAL(send_hardware_status(uint8_t*)),this,SLOT(recv_hardware_status(uint8_t*)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetDevId(short)),pCUdpSocketInfo,SLOT(GetDevId(short)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetUDPOpen(QString ,QString,int)),pCUdpSocketInfo,SLOT(GetUDPOpen(QString,QString,int)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetUDPClose()),pCUdpSocketInfo,SLOT(GetUDPClose()),Qt::QueuedConnection);

    //uart init
    pCUartInfo = CUartInfo::getUartInfoptr();
    connect(pCUartInfo, SIGNAL(send_edit_recv(QString)), this, SLOT(append_text_edit_recv(QString)),Qt::QueuedConnection);
    connect(pCUartInfo, SIGNAL(send_edit_test(QString)), this, SLOT(append_text_edit_test(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetDevId(short)),pCUartInfo,SLOT(GetDevId(short)),Qt::QueuedConnection);
    qRegisterMetaType<CUartInfo::UartInfo_t *>("CUartInfo::UartInfo_t *");
    connect(this,SIGNAL(SetUARTOpen(CUartInfo::UartInfo_t *)),pCUartInfo,SLOT(GetUARTOpen(CUartInfo::UartInfo_t *)),Qt::QueuedConnection);
    connect(this,SIGNAL(SetUARTClose()),pCUartInfo,SLOT(GetUARTClose()),Qt::QueuedConnection);

    //HW init
    pHWInfo = hardwareInfo::gethardwareInfoptr();

    connect(&timer,SIGNAL(timeout()),this,SLOT(getHWStatusRefresh()));


    //tab 2
    ui->tabWidget->setCurrentIndex(2);

    ui->hygro_lcd->setDigitCount(3);
    ui->hygro_lcd->setMode(QLCDNumber::Dec);
    ui->hygro_lcd->setSegmentStyle(QLCDNumber::Flat);
    ui->hygro_lcd->display(QString("0"));
    ui->therm_lcd->setDigitCount(3);
    ui->therm_lcd->setMode(QLCDNumber::Dec);
    ui->therm_lcd->setSegmentStyle(QLCDNumber::Flat);
    ui->therm_lcd->display(QString("0"));

    thermWnd = ui->therm_widget;
    connect(this,SIGNAL(Set_thermWnd_update(qreal)),thermWnd,SLOT(Update_value(qreal)),Qt::QueuedConnection);

    hygroWnd = ui->hygro_widget;
    connect(this,SIGNAL(Set_hygroWnd_update(qreal)),hygroWnd,SLOT(Update_value(qreal)),Qt::QueuedConnection);

    //tab 3
    ui->tabWidget->setCurrentIndex(3);
    GPSWnd = ui->gps_wnd;
    qRegisterMetaType<hardwareInfo::GPS_Data>("hardwareInfo::GPS_Data");
    connect(this,SIGNAL(Set_gpsWnd_update(hardwareInfo::GPS_Data)),GPSWnd,SLOT(Update_value(hardwareInfo::GPS_Data)),Qt::QueuedConnection);
    connect(this,SIGNAL(Set_locating_alert()),GPSWnd,SLOT(Enable_locating_alert()),Qt::QueuedConnection);

    sendThread->start();

    ui->tabWidget->show();
}

/*!
    关闭按钮(包含串口和网络)执行的界面状态管理函数
*/
void MainWindow::init_btn_disable()
{
    ui->btn_led_on->setDisabled(true);
    ui->btn_led_off->setDisabled(true);
    ui->btn_reboot->setDisabled(true);
    ui->btn_beep_on->setDisabled(true);
    ui->btn_beep_off->setDisabled(true);
    ui->btn_refresh->setDisabled(true);
    ui->btn_send_cmd->setDisabled(true);
    //ui->btn_filepath_update->setDisabled(true);
    ui->line_edit_dev_id->setReadOnly(false);
}


/*!
    开启按钮(包含串口和网络)执行的界面状态管理函数
*/
void MainWindow::init_btn_enable()
{
    ui->btn_led_on->setEnabled(true);
    ui->btn_led_off->setEnabled(true);
    ui->btn_reboot->setEnabled(true);
    ui->btn_beep_on->setEnabled(true);
    ui->btn_beep_off->setEnabled(true);
    ui->btn_refresh->setEnabled(true);
    ui->btn_send_cmd->setEnabled(true);
    //ui->btn_filepath_update->setEnabled(true);
    ui->line_edit_dev_id->setReadOnly(true);
}


/*!
    指令数据的发送和创建，提供给应用线程处理
*/
void MainWindow::CmdSendBuffer(uint8_t *pStart, uint16_t nSize, int nCommand, bool isThrough,
                               std::function<QString(uint8_t *, int)> pfunc, PROTOCOL_STATUS nProtocolStatus, QString pathInfo)
{
    SSendBuffer *pSendbuf = new SSendBuffer(pStart, nSize, nCommand, isThrough, pfunc, nProtocolStatus, pathInfo);

    emit SetSendBuff(pSendbuf);
}


/*!
    通用发送指令的槽函数，需要为十六进制
*/
void MainWindow::on_btn_send_cmd_clicked()
{
    static uint8_t nCacheBuf[256];
    bool bStatus;
    uint8_t nSize;
    QStringList QStrArr = ui->line_edit_cmd->text().split(" ");  //以空格为分割，将字符串分割为字符串数组

    nSize = QStrArr.size();

    for (int index = 0; index < nSize; index++)
    {
        nCacheBuf[index] = QStrArr[index].toInt(&bStatus, 16);  //the input characters are directly converted to hex
    }

    CmdSendBuffer(nCacheBuf, nSize, DEV_WRITE_THROUGH_CMD, false, nullptr);  //创建发送队列1
}

/*!
    开启led执行的槽函数
*/
void MainWindow::on_btn_led_on_clicked()
{
    quint8 status;
    hardwareInfo::HWCommandInfo* HWInfoptr;

    status |= (ui->LEDBox_blue->isChecked()  & 0x01)        ;
    status |= (ui->LEDBox_green->isChecked() & 0x01)    << 1;
    status |= (ui->LEDBox_red->isChecked()   & 0x01)    << 2;

    qDebug() << status;
    HWInfoptr = pHWInfo->getHwCmd(hardwareInfo::LED_ON,status);

    if(!HWInfoptr)
           perror("HardWare led error");

    CmdSendBuffer(HWInfoptr->m_pbuffer, HWInfoptr->m_nSize, HWInfoptr->m_nCommand, false, HWInfoptr->pFunc);  //创建发送队列
}

/*!
    关闭led执行的槽函数
*/
void MainWindow::on_btn_led_off_clicked()
{
    hardwareInfo::HWCommandInfo* HWInfoptr;
    HWInfoptr = pHWInfo->getHwCmd(hardwareInfo::LED_OFF);

    if(!HWInfoptr)
           perror("HardWare led error");

    CmdSendBuffer(HWInfoptr->m_pbuffer, HWInfoptr->m_nSize, HWInfoptr->m_nCommand, false, HWInfoptr->pFunc);  //创建发送队列
}

/*刷新状态*/
void MainWindow::getHWStatusRefresh(){
    hardwareInfo::HWCommandInfo* HWInfoptr;
    HWInfoptr = pHWInfo->getHwCmd(hardwareInfo::SYSTEM_UPDATE_CMD);

    if(!HWInfoptr)
           perror("HardWare led error");

    CmdSendBuffer(HWInfoptr->m_pbuffer, HWInfoptr->m_nSize, HWInfoptr->m_nCommand, false, HWInfoptr->pFunc,PROTOCOL_UDP);  //创建发送队列
}

void MainWindow::recv_hardware_status(uint8_t* pRecvData){

    hardwareInfo::SRegInfoList* pSRegInfo;

    pSRegInfo = reinterpret_cast<hardwareInfo::SRegInfoList *>(pRecvData);

    hardwareInfo::GPS_Data gpsinfo;
    qreal therm_value;
    qreal hygro_value;
    uint32_t gasconcen;


    gpsinfo = pSRegInfo->sensor_gps;
    emit Set_gpsWnd_update(gpsinfo);


    therm_value = pSRegInfo->sensor_temp;
    emit Set_thermWnd_update(therm_value);
    ui->therm_lcd->display(QString::number(therm_value));

    gasconcen = pSRegInfo->sensor_gasconcen;

    if(gasconcen)
        emit Set_locating_alert();

    hygro_value = pSRegInfo->sensor_humi;
    emit Set_hygroWnd_update(hygro_value);
    ui->hygro_lcd->display(QString::number(hygro_value));


}

/*刷新状态并打印状态信息*/
void MainWindow::on_btn_refresh_clicked()
{
    hardwareInfo::HWCommandInfo* HWInfoptr;
    HWInfoptr = pHWInfo->getHwCmd(hardwareInfo::GET_INFO_CMD);

    if(!HWInfoptr)
           perror("HardWare led error");

    CmdSendBuffer(HWInfoptr->m_pbuffer, HWInfoptr->m_nSize, HWInfoptr->m_nCommand, false, HWInfoptr->pFunc);  //创建发送队列
}


void MainWindow::on_btn_socket_open_clicked()
{
    int timeCount = 0;
    emit SetDevId(ui->line_edit_dev_id->text().toShort());
//    if(ui->combo_box_socket_type->currentText() == QString("TCP"))  //tcp
//    {
    emit SetTCPOpen(ui->line_edit_ipaddr->text(), ui->tcp_port->text().toInt());
    //protocol_flag = PROTOCOL_TCP;    //设置当前协议类型为TCP,传入设置消息类型
    while(!pCTcpSocketInfo->IsTCPConnect()) {
        QThread::msleep(50);
        if(timeCount++ > 50){
            protocol_flag = PROTOCOL_NULL;
            qDebug() << "TCP Connect time out";
            return;
        }
    }
//    }
//    else{   //udp
    QThread::msleep(5);
    emit SetUDPOpen(ui->line_edit_ipaddr->text(),ui->line_edit_local_ipaddr->text(),
                       ui->udp_port->text().toInt());
    timer.start(Timerinterval);
    //QThread::msleep(5);
    //protocol_flag = PROTOCOL_UDP;    //设置当前协议类型为UDP,传入设置消息类型
//    }

    init_btn_enable();
    ui->btn_uart_close->setDisabled(true);
    ui->btn_uart_open->setDisabled(true);
    ui->btn_socket_open->setDisabled(true);
    ui->btn_socket_close->setEnabled(true);
    ui->udp_port->setDisabled(true);
    ui->tcp_port->setDisabled(true);
    ui->line_edit_ipaddr->setDisabled(true);
    ui->line_edit_local_ipaddr->setDisabled(true);
    update_system_config();
    SystemConfigUpdate();
}

void MainWindow::on_btn_socket_close_clicked(void)
{
    init_btn_disable();

    ui->btn_uart_close->setEnabled(true);
    ui->btn_uart_open->setEnabled(true);
    ui->btn_socket_open->setEnabled(true);
    ui->btn_socket_close->setDisabled(true);
    ui->udp_port->setEnabled(true);
    ui->tcp_port->setEnabled(true);
    ui->line_edit_ipaddr->setEnabled(true);
    ui->line_edit_local_ipaddr->setEnabled(true);



//    if(ui->combo_box_socket_type->currentText() == QString("TCP"))
//    {
           emit SetTCPClose();
           append_text_edit_test(QString::fromLocal8Bit("Tcp Socket Close!"));
//    }
//    else{
           emit SetUDPClose();
           append_text_edit_test(QString::fromLocal8Bit("Udp Socket Close!"));

      timer.stop();
//    }
//    protocol_flag = PROTOCOL_NULL;
}


void MainWindow::on_btn_uart_open_clicked(){
    update_system_config();
    CUartInfo::UartInfo_t Info;

    Info.PortName = ui->combo_box_com->currentText();
    Info.BaudRate = ui->combo_box_baud->currentText().toInt();
    Info.DataBits = QSerialPort::DataBits(ui->combo_box_data->currentText().toInt());
    Info.StopBits = QSerialPort::StopBits(ui->combo_box_stop->currentText().toInt());
    Info.Parity   = QSerialPort::Parity(ui->combo_box_parity->currentText().toInt());

    emit SetUARTOpen(&Info);
    QThread::msleep(5);        //跨线程通信，需要等待,给定5ms测试可行

    if(pCUartInfo->IsOpen()){
        init_btn_enable();
        emit SetDevId(ui->line_edit_dev_id->text().toShort());
        ui->btn_uart_close->setEnabled(true);
        ui->btn_uart_open->setDisabled(true);
        ui->btn_socket_open->setDisabled(true);
        ui->btn_socket_close->setDisabled(true);
        ui->combo_box_com->setDisabled(true);
        ui->combo_box_baud->setDisabled(true);
        ui->combo_box_data->setDisabled(true);
        ui->combo_box_stop->setDisabled(true);
        ui->combo_box_parity->setDisabled(true);
        append_text_edit_test(QString::fromLocal8Bit("serial open success!"));
        //protocol_flag = PROTOCOL_UART;
        SystemConfigUpdate();
    }
    else
        append_text_edit_test(QString::fromLocal8Bit("serial open failed !"));
}


void MainWindow::on_btn_uart_close_clicked(){
    init_btn_disable();

    ui->btn_uart_close->setDisabled(true);
    ui->btn_uart_open->setEnabled(true);
    ui->btn_socket_open->setEnabled(true);
    ui->btn_socket_close->setEnabled(true);
    ui->combo_box_com->setEnabled(true);
    ui->combo_box_baud->setEnabled(true);
    ui->combo_box_data->setEnabled(true);
    ui->combo_box_stop->setEnabled(true);
    ui->combo_box_parity->setEnabled(true);

    emit SetUARTClose();

//    protocol_flag = PROTOCOL_NULL;
    append_text_edit_test(QString::fromLocal8Bit("serial close!"));

}


/*!
    清理显示窗口执行的槽函数
*/
void MainWindow::on_btn_clear_clicked(){
    ui->text_edit_test->clear();
    ui->text_edit_recv->clear();
}


/*!
    更新内部数据
*/
void MainWindow::update_system_config(void)
{
    //串口相关配置更新
    pSystemConfigInfo->m_SCom = ui->combo_box_com->currentText();
    pSystemConfigInfo->m_SBaud = ui->combo_box_baud->currentText();
    pSystemConfigInfo->m_SDataBits = ui->combo_box_data->currentText();
    pSystemConfigInfo->m_SParity = ui->combo_box_parity->currentText();
    pSystemConfigInfo->m_SStopBits = ui->combo_box_stop->currentText();

    //设备ID
    pSystemConfigInfo->m_SDeviceID = ui->line_edit_dev_id->text();

    //协议类型
    pSystemConfigInfo->m_SIpAddr = ui->line_edit_ipaddr->text();
    pSystemConfigInfo->m_STCPPort = ui->tcp_port->text();
    pSystemConfigInfo->m_SUDPPort = ui->udp_port->text();
    pSystemConfigInfo->m_SLocalIpAddr = ui->line_edit_local_ipaddr->text();

}
/*!
    将数据显示在接收窗口的槽函数
*/
void MainWindow::append_text_edit_recv(QString s)
{
    ui->text_edit_recv->clear();
    ui->text_edit_recv->setText(s);
}

/*!
    将数据显示在测试窗口的槽函数
*/
void MainWindow::append_text_edit_test(QString s)
{
    //对于超长数据，截取后显示
    if(s.size() > 150)
        s = s.mid(0, 40) + "..." + s.mid(s.size()-20, s.size());

    if(ui->text_edit_test->document()->lineCount() > 20)
              ui->text_edit_test->setText(s);
    else
              ui->text_edit_test->append(s);
}



