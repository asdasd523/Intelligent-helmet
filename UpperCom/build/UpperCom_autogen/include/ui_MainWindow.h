/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <gpsinfownd.h>
#include <hygrownd.h>
#include <thermwnd.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_uart;
    QLabel *label_comid;
    QComboBox *combo_box_com;
    QLabel *label_baud;
    QComboBox *combo_box_baud;
    QLabel *label_data;
    QComboBox *combo_box_data;
    QLabel *label_stop;
    QComboBox *combo_box_stop;
    QLabel *label_parity;
    QComboBox *combo_box_parity;
    QPushButton *btn_uart_open;
    QPushButton *btn_uart_close;
    QLabel *label_dev_id_4;
    QFrame *frame_dev;
    QLabel *label_dev_id;
    QLineEdit *line_edit_dev_id;
    QLabel *label_dev_id_3;
    QFrame *frame_socket;
    QLabel *label_server_ipaddr;
    QLineEdit *line_edit_ipaddr;
    QLabel *label_server_port;
    QLineEdit *tcp_port;
    QPushButton *btn_socket_open;
    QPushButton *btn_socket_close;
    QLabel *label_local_ipaddr;
    QLineEdit *line_edit_local_ipaddr;
    QLabel *label_dev_id_2;
    QLabel *label_server_port_2;
    QLineEdit *udp_port;
    QTabWidget *tabWidget;
    QWidget *deviceTab;
    QFrame *frame_info;
    QLabel *label_led;
    QPushButton *btn_led_on;
    QPushButton *btn_led_off;
    QLabel *label_beep;
    QPushButton *btn_beep_on;
    QPushButton *btn_beep_off;
    QTextEdit *text_edit_recv;
    QLabel *label_stauts;
    QPushButton *btn_refresh;
    QLabel *label_reboot;
    QPushButton *btn_reboot;
    QPushButton *btn_filepath_choose;
    QLabel *label_file_path;
    QComboBox *combo_box_filepath;
    QPushButton *btn_filepath_update;
    QCheckBox *LEDBox_red;
    QCheckBox *LEDBox_blue;
    QCheckBox *LEDBox_green;
    QFrame *frame_test;
    QLabel *label_cmd;
    QLineEdit *line_edit_cmd;
    QPushButton *btn_send_cmd;
    QLabel *label_test;
    QTextEdit *text_edit_test;
    QPushButton *btn_clear;
    QWidget *tab;
    ThermWnd *therm_widget;
    QLCDNumber *therm_lcd;
    QLCDNumber *hygro_lcd;
    HygroWnd *hygro_widget;
    QLabel *label;
    QLabel *label_2;
    GPSInfoWnd *gps_wnd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(730, 830);
        MainWindow->setMinimumSize(QSize(730, 830));
        MainWindow->setMaximumSize(QSize(730, 830));
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setAutoFillBackground(true);
        frame_uart = new QFrame(centralwidget);
        frame_uart->setObjectName(QStringLiteral("frame_uart"));
        frame_uart->setGeometry(QRect(500, 40, 221, 261));
        frame_uart->setMinimumSize(QSize(100, 100));
        frame_uart->setAutoFillBackground(false);
        frame_uart->setFrameShape(QFrame::StyledPanel);
        frame_uart->setFrameShadow(QFrame::Raised);
        label_comid = new QLabel(frame_uart);
        label_comid->setObjectName(QStringLiteral("label_comid"));
        label_comid->setGeometry(QRect(10, 60, 81, 20));
        combo_box_com = new QComboBox(frame_uart);
        combo_box_com->setObjectName(QStringLiteral("combo_box_com"));
        combo_box_com->setGeometry(QRect(100, 60, 111, 21));
        label_baud = new QLabel(frame_uart);
        label_baud->setObjectName(QStringLiteral("label_baud"));
        label_baud->setGeometry(QRect(10, 90, 71, 20));
        combo_box_baud = new QComboBox(frame_uart);
        combo_box_baud->setObjectName(QStringLiteral("combo_box_baud"));
        combo_box_baud->setGeometry(QRect(100, 90, 111, 21));
        label_data = new QLabel(frame_uart);
        label_data->setObjectName(QStringLiteral("label_data"));
        label_data->setGeometry(QRect(10, 120, 71, 20));
        combo_box_data = new QComboBox(frame_uart);
        combo_box_data->setObjectName(QStringLiteral("combo_box_data"));
        combo_box_data->setGeometry(QRect(100, 120, 111, 21));
        label_stop = new QLabel(frame_uart);
        label_stop->setObjectName(QStringLiteral("label_stop"));
        label_stop->setGeometry(QRect(10, 150, 71, 20));
        combo_box_stop = new QComboBox(frame_uart);
        combo_box_stop->setObjectName(QStringLiteral("combo_box_stop"));
        combo_box_stop->setGeometry(QRect(100, 150, 111, 21));
        label_parity = new QLabel(frame_uart);
        label_parity->setObjectName(QStringLiteral("label_parity"));
        label_parity->setGeometry(QRect(10, 180, 71, 20));
        combo_box_parity = new QComboBox(frame_uart);
        combo_box_parity->setObjectName(QStringLiteral("combo_box_parity"));
        combo_box_parity->setGeometry(QRect(100, 180, 111, 21));
        btn_uart_open = new QPushButton(frame_uart);
        btn_uart_open->setObjectName(QStringLiteral("btn_uart_open"));
        btn_uart_open->setGeometry(QRect(10, 220, 85, 25));
        btn_uart_close = new QPushButton(frame_uart);
        btn_uart_close->setObjectName(QStringLiteral("btn_uart_close"));
        btn_uart_close->setGeometry(QRect(110, 220, 85, 25));
        label_dev_id_4 = new QLabel(frame_uart);
        label_dev_id_4->setObjectName(QStringLiteral("label_dev_id_4"));
        label_dev_id_4->setGeometry(QRect(10, 20, 181, 21));
        QFont font;
        font.setPointSize(14);
        label_dev_id_4->setFont(font);
        frame_dev = new QFrame(centralwidget);
        frame_dev->setObjectName(QStringLiteral("frame_dev"));
        frame_dev->setGeometry(QRect(500, 370, 221, 81));
        frame_dev->setAutoFillBackground(true);
        frame_dev->setFrameShape(QFrame::StyledPanel);
        frame_dev->setFrameShadow(QFrame::Raised);
        label_dev_id = new QLabel(frame_dev);
        label_dev_id->setObjectName(QStringLiteral("label_dev_id"));
        label_dev_id->setGeometry(QRect(10, 40, 71, 21));
        line_edit_dev_id = new QLineEdit(frame_dev);
        line_edit_dev_id->setObjectName(QStringLiteral("line_edit_dev_id"));
        line_edit_dev_id->setGeometry(QRect(40, 40, 111, 21));
        label_dev_id_3 = new QLabel(frame_dev);
        label_dev_id_3->setObjectName(QStringLiteral("label_dev_id_3"));
        label_dev_id_3->setGeometry(QRect(10, 0, 181, 21));
        label_dev_id_3->setFont(font);
        frame_socket = new QFrame(centralwidget);
        frame_socket->setObjectName(QStringLiteral("frame_socket"));
        frame_socket->setGeometry(QRect(500, 530, 221, 211));
        frame_socket->setAutoFillBackground(true);
        frame_socket->setFrameShape(QFrame::StyledPanel);
        frame_socket->setFrameShadow(QFrame::Raised);
        label_server_ipaddr = new QLabel(frame_socket);
        label_server_ipaddr->setObjectName(QStringLiteral("label_server_ipaddr"));
        label_server_ipaddr->setGeometry(QRect(10, 50, 81, 20));
        line_edit_ipaddr = new QLineEdit(frame_socket);
        line_edit_ipaddr->setObjectName(QStringLiteral("line_edit_ipaddr"));
        line_edit_ipaddr->setGeometry(QRect(100, 50, 111, 20));
        label_server_port = new QLabel(frame_socket);
        label_server_port->setObjectName(QStringLiteral("label_server_port"));
        label_server_port->setGeometry(QRect(10, 110, 81, 20));
        tcp_port = new QLineEdit(frame_socket);
        tcp_port->setObjectName(QStringLiteral("tcp_port"));
        tcp_port->setGeometry(QRect(100, 110, 111, 21));
        btn_socket_open = new QPushButton(frame_socket);
        btn_socket_open->setObjectName(QStringLiteral("btn_socket_open"));
        btn_socket_open->setGeometry(QRect(10, 170, 85, 25));
        btn_socket_close = new QPushButton(frame_socket);
        btn_socket_close->setObjectName(QStringLiteral("btn_socket_close"));
        btn_socket_close->setGeometry(QRect(110, 170, 85, 25));
        label_local_ipaddr = new QLabel(frame_socket);
        label_local_ipaddr->setObjectName(QStringLiteral("label_local_ipaddr"));
        label_local_ipaddr->setGeometry(QRect(10, 80, 81, 20));
        line_edit_local_ipaddr = new QLineEdit(frame_socket);
        line_edit_local_ipaddr->setObjectName(QStringLiteral("line_edit_local_ipaddr"));
        line_edit_local_ipaddr->setGeometry(QRect(100, 80, 111, 20));
        label_dev_id_2 = new QLabel(frame_socket);
        label_dev_id_2->setObjectName(QStringLiteral("label_dev_id_2"));
        label_dev_id_2->setGeometry(QRect(10, 10, 181, 21));
        label_dev_id_2->setFont(font);
        label_server_port_2 = new QLabel(frame_socket);
        label_server_port_2->setObjectName(QStringLiteral("label_server_port_2"));
        label_server_port_2->setGeometry(QRect(10, 140, 81, 20));
        udp_port = new QLineEdit(frame_socket);
        udp_port->setObjectName(QStringLiteral("udp_port"));
        udp_port->setGeometry(QRect(100, 140, 111, 21));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 481, 771));
        tabWidget->setAutoFillBackground(true);
        deviceTab = new QWidget();
        deviceTab->setObjectName(QStringLiteral("deviceTab"));
        deviceTab->setAutoFillBackground(true);
        frame_info = new QFrame(deviceTab);
        frame_info->setObjectName(QStringLiteral("frame_info"));
        frame_info->setGeometry(QRect(0, 0, 481, 431));
        frame_info->setAutoFillBackground(true);
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        label_led = new QLabel(frame_info);
        label_led->setObjectName(QStringLiteral("label_led"));
        label_led->setGeometry(QRect(10, 10, 81, 16));
        btn_led_on = new QPushButton(frame_info);
        btn_led_on->setObjectName(QStringLiteral("btn_led_on"));
        btn_led_on->setGeometry(QRect(110, 10, 90, 23));
        btn_led_off = new QPushButton(frame_info);
        btn_led_off->setObjectName(QStringLiteral("btn_led_off"));
        btn_led_off->setGeometry(QRect(220, 10, 91, 23));
        label_beep = new QLabel(frame_info);
        label_beep->setObjectName(QStringLiteral("label_beep"));
        label_beep->setGeometry(QRect(10, 70, 91, 21));
        btn_beep_on = new QPushButton(frame_info);
        btn_beep_on->setObjectName(QStringLiteral("btn_beep_on"));
        btn_beep_on->setGeometry(QRect(110, 70, 91, 23));
        btn_beep_off = new QPushButton(frame_info);
        btn_beep_off->setObjectName(QStringLiteral("btn_beep_off"));
        btn_beep_off->setGeometry(QRect(220, 70, 91, 23));
        text_edit_recv = new QTextEdit(frame_info);
        text_edit_recv->setObjectName(QStringLiteral("text_edit_recv"));
        text_edit_recv->setGeometry(QRect(0, 170, 461, 191));
        text_edit_recv->setAcceptDrops(false);
        text_edit_recv->setReadOnly(true);
        label_stauts = new QLabel(frame_info);
        label_stauts->setObjectName(QStringLiteral("label_stauts"));
        label_stauts->setGeometry(QRect(10, 130, 101, 21));
        btn_refresh = new QPushButton(frame_info);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));
        btn_refresh->setGeometry(QRect(110, 130, 91, 21));
        label_reboot = new QLabel(frame_info);
        label_reboot->setObjectName(QStringLiteral("label_reboot"));
        label_reboot->setGeometry(QRect(10, 100, 71, 21));
        btn_reboot = new QPushButton(frame_info);
        btn_reboot->setObjectName(QStringLiteral("btn_reboot"));
        btn_reboot->setGeometry(QRect(110, 100, 91, 23));
        btn_filepath_choose = new QPushButton(frame_info);
        btn_filepath_choose->setObjectName(QStringLiteral("btn_filepath_choose"));
        btn_filepath_choose->setGeometry(QRect(430, 370, 41, 21));
        label_file_path = new QLabel(frame_info);
        label_file_path->setObjectName(QStringLiteral("label_file_path"));
        label_file_path->setGeometry(QRect(10, 370, 71, 21));
        combo_box_filepath = new QComboBox(frame_info);
        combo_box_filepath->setObjectName(QStringLiteral("combo_box_filepath"));
        combo_box_filepath->setGeometry(QRect(90, 370, 331, 21));
        btn_filepath_update = new QPushButton(frame_info);
        btn_filepath_update->setObjectName(QStringLiteral("btn_filepath_update"));
        btn_filepath_update->setGeometry(QRect(370, 400, 101, 21));
        LEDBox_red = new QCheckBox(frame_info);
        LEDBox_red->setObjectName(QStringLiteral("LEDBox_red"));
        LEDBox_red->setGeometry(QRect(10, 40, 92, 23));
        LEDBox_blue = new QCheckBox(frame_info);
        LEDBox_blue->setObjectName(QStringLiteral("LEDBox_blue"));
        LEDBox_blue->setGeometry(QRect(120, 40, 92, 23));
        LEDBox_green = new QCheckBox(frame_info);
        LEDBox_green->setObjectName(QStringLiteral("LEDBox_green"));
        LEDBox_green->setGeometry(QRect(230, 40, 92, 23));
        frame_test = new QFrame(deviceTab);
        frame_test->setObjectName(QStringLiteral("frame_test"));
        frame_test->setGeometry(QRect(0, 430, 481, 331));
        frame_test->setAutoFillBackground(true);
        frame_test->setFrameShape(QFrame::StyledPanel);
        frame_test->setFrameShadow(QFrame::Raised);
        label_cmd = new QLabel(frame_test);
        label_cmd->setObjectName(QStringLiteral("label_cmd"));
        label_cmd->setGeometry(QRect(10, 10, 131, 20));
        line_edit_cmd = new QLineEdit(frame_test);
        line_edit_cmd->setObjectName(QStringLiteral("line_edit_cmd"));
        line_edit_cmd->setGeometry(QRect(10, 30, 311, 31));
        btn_send_cmd = new QPushButton(frame_test);
        btn_send_cmd->setObjectName(QStringLiteral("btn_send_cmd"));
        btn_send_cmd->setGeometry(QRect(330, 30, 141, 31));
        label_test = new QLabel(frame_test);
        label_test->setObjectName(QStringLiteral("label_test"));
        label_test->setGeometry(QRect(10, 70, 111, 20));
        text_edit_test = new QTextEdit(frame_test);
        text_edit_test->setObjectName(QStringLiteral("text_edit_test"));
        text_edit_test->setGeometry(QRect(10, 100, 461, 171));
        text_edit_test->setReadOnly(true);
        btn_clear = new QPushButton(frame_test);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setGeometry(QRect(10, 280, 92, 28));
        tabWidget->addTab(deviceTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        therm_widget = new ThermWnd(tab);
        therm_widget->setObjectName(QStringLiteral("therm_widget"));
        therm_widget->setGeometry(QRect(0, 100, 231, 631));
        therm_lcd = new QLCDNumber(tab);
        therm_lcd->setObjectName(QStringLiteral("therm_lcd"));
        therm_lcd->setGeometry(QRect(40, 40, 161, 51));
        hygro_lcd = new QLCDNumber(tab);
        hygro_lcd->setObjectName(QStringLiteral("hygro_lcd"));
        hygro_lcd->setGeometry(QRect(280, 40, 161, 51));
        hygro_widget = new HygroWnd(tab);
        hygro_widget->setObjectName(QStringLiteral("hygro_widget"));
        hygro_widget->setGeometry(QRect(250, 100, 211, 631));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 0, 131, 31));
        label->setFont(font);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 0, 131, 31));
        label_2->setFont(font);
        tabWidget->addTab(tab, QString());
        gps_wnd = new GPSInfoWnd();
        gps_wnd->setObjectName(QStringLiteral("gps_wnd"));
        tabWidget->addTab(gps_wnd, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_comid->setText(QApplication::translate("MainWindow", "PortName", nullptr));
        label_baud->setText(QApplication::translate("MainWindow", "BaudRate", nullptr));
        label_data->setText(QApplication::translate("MainWindow", "DataBits", nullptr));
        label_stop->setText(QApplication::translate("MainWindow", "StopBits", nullptr));
        label_parity->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        btn_uart_open->setText(QApplication::translate("MainWindow", "open", nullptr));
        btn_uart_close->setText(QApplication::translate("MainWindow", "close", nullptr));
        label_dev_id_4->setText(QApplication::translate("MainWindow", "Serial Control", nullptr));
        label_dev_id->setText(QApplication::translate("MainWindow", "ID", nullptr));
        line_edit_dev_id->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_dev_id_3->setText(QApplication::translate("MainWindow", "Helmet ID", nullptr));
        label_server_ipaddr->setText(QApplication::translate("MainWindow", "Server IP", nullptr));
        line_edit_ipaddr->setText(QApplication::translate("MainWindow", "192.168.1.251", nullptr));
        label_server_port->setText(QApplication::translate("MainWindow", "TCP port", nullptr));
        tcp_port->setText(QApplication::translate("MainWindow", "8000", nullptr));
        btn_socket_open->setText(QApplication::translate("MainWindow", "connect", nullptr));
        btn_socket_close->setText(QApplication::translate("MainWindow", "disconnect", nullptr));
        label_local_ipaddr->setText(QApplication::translate("MainWindow", "Local IP", nullptr));
        line_edit_local_ipaddr->setText(QApplication::translate("MainWindow", "192.168.1.105", nullptr));
        label_dev_id_2->setText(QApplication::translate("MainWindow", "Socket Control", nullptr));
        label_server_port_2->setText(QApplication::translate("MainWindow", "UDP port", nullptr));
        udp_port->setText(QApplication::translate("MainWindow", "8001", nullptr));
        label_led->setText(QApplication::translate("MainWindow", "LED Control", nullptr));
        btn_led_on->setText(QApplication::translate("MainWindow", "open", nullptr));
        btn_led_off->setText(QApplication::translate("MainWindow", "close", nullptr));
        label_beep->setText(QApplication::translate("MainWindow", "BEEP Control", nullptr));
        btn_beep_on->setText(QApplication::translate("MainWindow", "open", nullptr));
        btn_beep_off->setText(QApplication::translate("MainWindow", "close", nullptr));
        label_stauts->setText(QApplication::translate("MainWindow", "Internal status", nullptr));
        btn_refresh->setText(QApplication::translate("MainWindow", "refresh", nullptr));
        label_reboot->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        btn_reboot->setText(QApplication::translate("MainWindow", "reset", nullptr));
        btn_filepath_choose->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_file_path->setText(QApplication::translate("MainWindow", "File path", nullptr));
        btn_filepath_update->setText(QApplication::translate("MainWindow", "file update", nullptr));
        LEDBox_red->setText(QApplication::translate("MainWindow", "red", nullptr));
        LEDBox_blue->setText(QApplication::translate("MainWindow", "blue", nullptr));
        LEDBox_green->setText(QApplication::translate("MainWindow", "green", nullptr));
        label_cmd->setText(QApplication::translate("MainWindow", "Custom instruction", nullptr));
        btn_send_cmd->setText(QApplication::translate("MainWindow", "Command sending", nullptr));
        label_test->setText(QApplication::translate("MainWindow", "Debug window", nullptr));
        btn_clear->setText(QApplication::translate("MainWindow", "Clear data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(deviceTab), QApplication::translate("MainWindow", "Device Management ", nullptr));
        label->setText(QApplication::translate("MainWindow", "thermometer", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "hygrometer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "thermo-hygrometer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(gps_wnd), QApplication::translate("MainWindow", "GPS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
