#include <hardwareserver.h>
#include <signal.h>

#include "hardware/gps.h"

//HardWare shared Server Init
std::shared_ptr<CHardWareServer> CHardWareServer::pSharedHardWareServ =
       std::make_shared<CHardWareServer>();

//获取消息队列的共享指针
std::shared_ptr<CBaseMessageInfo>  CHardWareServer::pHWMessageInfo = CBaseMessageInfo::pSharedMqMessage;

CHardWareServer::CHardWareServer(){

    memset((char *)m_RegVal, 0, REG_NUM);   /*初始化内部寄存状态*/

}


void CHardWareServer::ThreadRun(){
    m_thread = std::thread(&CHardWareServer::HardWardLoopThread, this);
}
/**
 * 从内部共享数据寄存器中读取数据
 * 
 * @param nRegIndex  待读取寄存器的起始地址
 * @param nRegSize   读取的寄存器的数量
 * @param pDataStart 放置读取数据的首地址
 *  
 * @return 读取寄存器的数量
 */
uint16_t CHardWareServer::GetMultipleReg(uint16_t nRegIndex, uint16_t nRegSize, uint8_t *pDataStart)
{
    uint16_t nIndex;
    assert(pDataStart != nullptr);

    if(nRegSize > REG_NUM)
        nRegSize = REG_NUM;

    m_RegMutex.lock();  //获取互斥锁
    for(nIndex = 0; nIndex < nRegSize; nIndex++)
    {
        *(pDataStart+nIndex) = m_RegVal[nRegIndex+nIndex];
    }
    m_RegMutex.unlock();

    return nRegSize;
}

/**
 * 将数据写入内部共享的数据寄存器
 * 
 * @param nRegIndex 设置寄存器的起始地址
 * @param nRegSize  设置的寄存器的数量
 * @param pDataStart 放置设置数据的首地址
 *  
 * @return NULL
 */

void CHardWareServer::SetMultipleReg(uint16_t nRegIndex, uint16_t nRegSize, uint8_t *pDataStart){
    uint16_t nIndex, nEndRegIndex, modifySize;

    assert(pDataStart != nullptr);

    nEndRegIndex = nRegIndex+nRegSize;
    if(nEndRegIndex>REG_NUM)
    {
        nEndRegIndex = REG_NUM;
    }
    modifySize = nEndRegIndex-nRegIndex;

    m_RegMutex.lock();  //获取互斥锁
    for(nIndex=0; nIndex<modifySize; nIndex++)
    {
        m_RegVal[nRegIndex+nIndex] = *(pDataStart+nIndex);
    }
    m_RegMutex.unlock();  //释放互斥锁

    //m_isModified = true;
}

/**
 * 带判断是否修改的写入寄存器实现，变化了表明了其它线程修改了指令
 * 
 * @param nRegIndex 寄存器的起始地址
 * @param nRegSize 读取的寄存器的数量
 * @param pDataStart 设置数据的地址
 * @param psrc   缓存的原始寄存器数据
 *  
 * @return 寄存器的比较写入处理结果
 */
int CHardWareServer::DiffSetMultipleReg(uint16_t nRegIndex, uint16_t nRegSize, 
                                        uint8_t *pDataStart, uint8_t *pDataCompare){
    
    uint16_t nIndex, nEndRegIndex, modifySize;

    assert(pDataStart != nullptr && pDataCompare != nullptr);

    nEndRegIndex = nRegIndex+nRegSize;
    if(nEndRegIndex>REG_NUM)
        nEndRegIndex = REG_NUM;
    modifySize = nEndRegIndex-nRegIndex;

    m_RegMutex.lock();  //获取互斥锁
    
    if(memcmp((char*)&m_RegVal[nRegIndex],pDataCompare, nRegSize) != 0){   //比较内部寄存器与cache
        m_RegMutex.unlock();
        return RT_FAIL;
    }

    for(nIndex=0; nIndex<modifySize; nIndex++)
    {
        m_RegVal[nIndex] = *(pDataStart+nIndex);
    }
    m_RegMutex.unlock();

    return RT_OK;
    
}


/**
 * 读取硬件状态并更新到寄存器中
 * 
 * @param NULL
 *  
 * @return NULL
 */
void CHardWareServer::ReadDeviceStatus(void){
    uint8_t nRegInfoArray[REG_INFO_NUM];
    uint8_t nRegCacheArray[REG_INFO_NUM];
    SRegInfoList *pRegInfoList;
    uint8_t readflag;
    uint32_t mpu_data[3];
    uint8_t gps_data[sizeof(CGPS::GPS_Data)];
    uint8_t MQ135_data;
    uint8_t DHT11_data[6];

    GetMultipleReg(REG_CONFIG_NUM, REG_INFO_NUM, nRegInfoArray);
    memcpy(nRegCacheArray, nRegInfoArray, REG_INFO_NUM);
    pRegInfoList = reinterpret_cast<SRegInfoList*>(nRegInfoArray);

    //更新led的状态
    led_dev->HWread(&readflag);
    pRegInfoList->s_base_status.b.led  = readflag & 0x07; 

    //更新蜂鸣器的状态
    beep_dev->HWread(&readflag);
    pRegInfoList->s_base_status.b.beep = readflag & 0x01;

    //更新mpu的状态
    if(mpu_dev->HWread((uint8_t*)mpu_data) == -1)
        printf("read hardware error \n");


    pRegInfoList->sensor_angle_x = *((float*)&mpu_data[0]);
    pRegInfoList->sensor_angle_y = *((float*)&mpu_data[1]);
    pRegInfoList->sensor_angle_z = *((float*)&mpu_data[2]);


    gps_dev->HWread((uint8_t*)gps_data);
    memcpy((uint8_t*)&pRegInfoList->sensor_gps,gps_data,sizeof(CGPS::GPS_Data));


    pRegInfoList->sensor_gps.deg_lat   = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)));
    pRegInfoList->sensor_gps.deg_lon   = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 1 * sizeof(float)));
    pRegInfoList->sensor_gps.elv       = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 2 * sizeof(float)));
    pRegInfoList->sensor_gps.speed     = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 3 * sizeof(float)));
    pRegInfoList->sensor_gps.direction = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 4 * sizeof(float)));
    pRegInfoList->sensor_gps.PDOP      = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 5 * sizeof(float)));
    pRegInfoList->sensor_gps.HDOP      = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 6 * sizeof(float)));
    pRegInfoList->sensor_gps.VDOP      = *((float*)(gps_data+sizeof(pRegInfoList->sensor_gps.cur_time)+sizeof(pRegInfoList->sensor_gps.satinfo)  + 7 * sizeof(float)));

    //gps_dev->GPS_InfoShow(&pRegInfoList->sensor_gps);   //Show GPS Information

    mq135_dev->HWread(&MQ135_data);
    pRegInfoList->sensor_gasconcen = (uint32_t)MQ135_data;

    dht11_dev->HWread(DHT11_data);
    pRegInfoList->sensor_temp = (uint32_t)DHT11_data[2];
    pRegInfoList->sensor_humi = (uint32_t)DHT11_data[0];


    // 在读取数据的过程中，如果寄存器库发生变化，那么更新到寄存器中去
    if(memcmp(nRegCacheArray, nRegInfoArray, REG_INFO_NUM) != 0)
    {
        SetMultipleReg(REG_CONFIG_NUM, REG_INFO_NUM, nRegInfoArray);
    }    
}

/**
 * 根据寄存器配置更新硬件状态
 * 
 * @param cmd 执行的读写指令
 * @param pConfig 配置的数据首地址
 * @param size 配置的数据长度
 *  
 * @return NULL
 */
void CHardWareServer::WriteDeviceConfig(uint8_t cmd, uint8_t *pConfig, int size){
    
    assert(pConfig != nullptr);

    switch(cmd){
        case DEVICE_LED:
            led_dev->HWwrite(pConfig);
            break;
        case DEVICE_BEEP:
            break;
        case DEVICE_REBOOT:
            break;
        default:
            USR_DEBUG("error : Invalid Command ! \r\n");
            break;
    }
}


/**
 * 状态更新定时触发的执行函数
 * 
 * @param signo 触发传入的数据
 *  
 * @return NULL
 */
void CHardWareServer::TimerSignalHandler(int signo){
    char buf = 1;
            
    pHWMessageInfo->SendInformation(APP_BASE_MESSAGE, &buf, sizeof(buf), 1);
}

/**
 * 状态更新定时触发源启动
 * 
 * @param NULL
 *  
 * @return NULL
 */
void CHardWareServer::TimerSingalStart(void){
    static struct itimerval tick = {0};

    signal(SIGALRM, &CHardWareServer::TimerSignalHandler);
    
    //初始执行的定时器计数值
    tick.it_value.tv_sec = 2;
    tick.it_value.tv_usec = 0;

    //后续定时器执行的加载值
    tick.it_interval.tv_sec = 2;
    tick.it_interval.tv_usec = 0;

    if(setitimer(ITIMER_REAL, &tick, NULL) < 0)
    {
        USR_DEBUG("Set timer failed!\n");
    }
    USR_DEBUG("Set timer Start!\n");    
}

/**
 * 进行所有硬件的处理, 包含硬件配置和状态读取
 * 
 * @param NULL
 *  
 * @return 硬件处理的执行结果
 */
int CHardWareServer::RefreshAllDevice(void){

    if(m_isModified){
        uint8_t nRegCacheArray[REG_CONFIG_NUM];
        uint8_t nRegValArray[REG_CONFIG_NUM];

        /*读取设置寄存器的值到缓存中*/
        GetMultipleReg(0, REG_CONFIG_NUM, nRegValArray);
        memcpy(nRegCacheArray, nRegValArray, REG_CONFIG_NUM);

        //将上位机传输来的命令写入设备
        WriteDeviceConfig(DEVICE_LED, nRegValArray, REG_CONFIG_NUM);

        /*修改后更新寄存器状态, 确定在函数执行过程中无其它应用修改后才可以真正更新*/
        if(DiffSetMultipleReg(0, REG_CONFIG_NUM, nRegValArray, nRegCacheArray) != RT_OK){
            USR_DEBUG("Modify By Other Application\n");
            return RT_FAIL;
        }

        m_isModified = false;
    }  
    
    /*更新内部硬件状态到信息寄存器*/
    ReadDeviceStatus();
    
    return RT_OK;
}

void CHardWareServer::HardWareInitial(){
    led_dev = std::make_unique<CLed>();
    led_dev->HWInit();

    mpu_dev = std::make_unique<CMPU>(300);
    mpu_dev->HWInit();

    gps_dev = std::make_unique<CGPS>();
    gps_dev->HWInit();

    mq135_dev = std::make_unique<CMQ135>();
    mq135_dev->HWInit();

    dht11_dev = std::make_unique<CDHT11>();
    dht11_dev->HWInit();

    beep_dev = std::make_unique<CBeep>();
    beep_dev->HWInit();
}

void CHardWareServer::HardWareRelease(){
    led_dev->HWRelease();
    mpu_dev->HWRelease();
    gps_dev->HWRelease();
    mq135_dev->HWRelease();
    dht11_dev->HWRelease();
    beep_dev->HWRelease();
}

void CHardWareServer::HardWardLoopThread(){
    char InfoData;
    int Flag;

    USR_DEBUG("HardWard Thread Start \r\n");

    HardWareInitial();

    TimerSingalStart();

    USR_DEBUG("Initialization of all devices completed!\n");

    for (;;){
        Flag = this->pHWMessageInfo->WaitInformation(APP_BASE_MESSAGE, &InfoData, sizeof(InfoData));
        if(Flag > 0){
            this->RefreshAllDevice();
        }
        else{
            USR_DEBUG("HardWare Information Error, HW Tread Stop!\n");
            break;
        }
    }

    pHWMessageInfo->CloseInformation(APP_BASE_MESSAGE);

    HardWareRelease();

    return;
}
