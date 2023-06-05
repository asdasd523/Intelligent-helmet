#ifndef HARDWARECLIENT_H
#define HARDWARECLIENT_H

#include "typedef.h"
#include <functional>

class hardwareInfo{
public:
    enum hw_cmd{
        LED_ON = 0,
        LED_OFF,
        BEEP_ON,
        BEEP_OFF,
        DEV_REBOOT,
        GET_INFO_CMD,
        ABORT_CMD,
        SYSTEM_UPDATE_CMD
    };


    #pragma pack(push)
    #pragma pack(1)
    struct GPS_Data{
        struct {   //时间戳
            int year;
            int mon;
            int day;
            int hour;
            int min;
            int sec;
        }cur_time;
        struct {
            int inuse;
            int inview;
        }satinfo;
        float deg_lat;     //纬度
        float deg_lon;     //经度
        float elv;         //海拔高度
        float speed;       //速度
        float direction;   //航向
        float PDOP;
        float HDOP;
        float VDOP;
    };
    #pragma pack(pop)

    union UBaseStatus{
        uint32_t d32;

        struct {
            uint8_t  led:3;
            uint32_t beep:1;
            uint32_t reserved:28;
        }b;
    };

    #pragma pack(push)       //当前字节对齐值压入编译栈栈顶
    #pragma pack(1)          //将当前的字节对齐值设置为1
    struct SRegInfoList
    {
        /*系统基本状态信息，包含LED，Beep状态*/
        union UBaseStatus s_base_status;

        /*陀螺仪x轴角度*/
        float sensor_angle_x;

        /*陀螺仪y轴角度*/
        float sensor_angle_y;

        /*陀螺仪z轴角度*/
        float sensor_angle_z;

        /*陀螺仪x轴角度*/
        GPS_Data sensor_gps;

        /*温度采样*/
        uint32_t sensor_temp;

        /*湿度采样*/
        uint32_t sensor_humi;

        /*气体浓度采样*/
        uint32_t sensor_gasconcen;
    };
    #pragma pack(pop)


    struct HWCommandInfo{
        quint8 *m_pbuffer;
        quint16 m_nSize;
        quint8 m_nCommand;
        std::function<QString(uint8_t*, int)> pFunc;

        HWCommandInfo(quint8* buff = nullptr,quint16 size = 0,quint8 Cmd = 0,
                        std::function<QString(uint8_t*, int)> Func = NULL){
            m_pbuffer = buff;
            m_nSize = size;
            m_nCommand = Cmd;
            pFunc = Func;
        }
    };

    hardwareInfo(){
        pHwCmd = new HWCommandInfo;
    }
    ~hardwareInfo() {
        delete pHwCmd;
    }

    HWCommandInfo* getHwCmd(hw_cmd Hw,quint8 status = 0);

    static std::function<QString(uint8_t*, int)> GetInfo_pFunc;

    static std::function<QString(uint8_t*, int)> Refresh_pFunc;

    static hardwareInfo* gethardwareInfoptr();

private:

    QString getLEDStatus(uint32_t Statue);

    static hardwareInfo* HWInfoptr;


    HWCommandInfo* pHwCmd;




    //指令格式
    //cmd(1Byte) 0x01 读内部状态 0x02 写内部状态 0x03 上传指令 0x04 上传数据
    //reg(2Byte)
    //size(2Byte)
    //reg_value(size byte) -- 读内部状态时无寄存器值
    QVector<quint8> led_on_cmd = {
        0x02, 0x00, 0x00, 0x00, 0x01
    };
    QVector<quint8> led_off_cmd = {
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00
    };
    QVector<quint8> get_info_cmd = {    //64(0x40)位起是信息寄存器的区域,取92(0x5c)大小的数据
        0x01, 0x00, 0x40, 0x00, 0x5c
    };

};



#endif // HARDWAREINFO_H
