#ifndef _HARDWARESERVER_H
#define _HARDWARESERVER_H

#include <common/Typedef.h>
#include <thread>
#include <mutex>
#include <memory>
#include <Message/MqMessage.h>
#include <sys/time.h>
#include "hardware/led.h"
#include "hardware/mpu6050.h"
#include "hardware/gps.h"
#include "hardware/MQ135.h"
#include "hardware/dht11.h"
#include "hardware/beep.h"

class CMqMessageInfo;


#define REG_NUM                 256
#define REG_CONFIG_NUM          64     //用于写的寄存器区域,上位机传来的指令数据写入
#define REG_INFO_NUM            192    //用于读的寄存器区域,下位机读取传感器得到的数据

/*设备配置信息*/
#define DEVICE_LED              1
#define DEVICE_BEEP             2
#define DEVICE_REBOOT           3
#define DEVICE_GYRO             4

class CHardWareServer{

public:

    union UBaseStatus
    {
        uint32_t d32;

        struct 
        {
            uint8_t  led:3;  //0熄灭  0x001 blue  0x010 green 0x100 red
            uint32_t beep:1;
            uint32_t reserved:28;
        }b;
    };

    #pragma pack(push)
    #pragma pack(1)
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
        CGPS::GPS_Data sensor_gps;

        /*温度采样*/
        uint32_t sensor_temp;

        /*湿度采样*/
        uint32_t sensor_humi;

        /*气体浓度采样*/
        uint32_t sensor_gasconcen;
    };
    #pragma pack(pop)


    CHardWareServer();


    /*状态更新定时触发源启动*/
    void TimerSingalStart(void);

    /*进行所有硬件的处理, 包含硬件配置和状态读取*/
    int RefreshAllDevice(void);

    /*根据寄存器配置更新硬件状态*/
    void WriteDeviceConfig(uint8_t cmd, uint8_t *pRegConfig, int size);

    /*读取硬件状态并更新到寄存器中*/
    void ReadDeviceStatus(void);

    /*将数据写入内部共享的数据寄存器*/
    void SetMultipleReg(uint16_t nRegIndex, uint16_t nRegSize, uint8_t *pDataStart);

    /*从内部共享数据寄存器中读取数据*/
    uint16_t GetMultipleReg(uint16_t nRegIndex, uint16_t nRegSize, uint8_t *pDataStart);

    /*带判断是否修改的写入寄存器实现*/
    int DiffSetMultipleReg(uint16_t nRegIndex, uint16_t nRegSize, uint8_t *pDataStart, uint8_t *pDataCompare);

    void HardWareInitial();

    void HardWareRelease();

    void HardWardLoopThread();

    void ThreadRun();

    void DataModified_fromUpper(){
        m_isModified = true;
    }

    static void TimerSignalHandler(int signo);   //静态成员函数可用做普通函数指针

    static std::shared_ptr<CHardWareServer> pSharedHardWareServ;

private:
    static std::shared_ptr<CBaseMessageInfo> pHWMessageInfo;
    uint8_t m_RegVal[REG_NUM];
    bool m_isModified{false};                   /*上位机发送数据修改*/
    std::thread m_thread;
    std::mutex m_RegMutex;                      /*数据的每次读取都要执行该锁*/
    std::unique_ptr<CLed> led_dev;
    std::unique_ptr<CMPU> mpu_dev;
    std::unique_ptr<CGPS> gps_dev;
    std::unique_ptr<CMQ135> mq135_dev;
    std::unique_ptr<CDHT11> dht11_dev;
    std::unique_ptr<CBeep> beep_dev;
};

#endif