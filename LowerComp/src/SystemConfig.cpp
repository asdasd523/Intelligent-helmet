#include "SystemConfig.h"
//设置共享智能指针
std::shared_ptr<SystemConfigInfo::SSystemConfig> SystemConfigInfo::pShardSystemConfig
        = std::make_shared<SystemConfigInfo::SSystemConfig>(
    //串口配置
    BAUD,
    DATABITS,
    STOPBITS,
    std::string(PARITY),

    //TCP网络设置
    std::string(IP_ADDR),
    TCP_PORT,

    //UDP网络设置
    std::string(IP_ADDR),
    UDP_PORT,

    //硬件状态
    0,
    0,

    //设备名称
    std::string(TTY_DEVICE),
    std::string(LED_DEVICE),
    std::string(BEEP_DEVICE),
    std::string(ICM_SPI_DEVICE),
    std::string(RTC_DEVICE),
    std::string(AP_I2C_DEVICE),
    std::string(MPU_DEVICE),
    std::string(GPS_DEVICE),
    std::string(MQ135_DEVICE),
    std::string(DHT11_DEVICE),

    //下载文件的路径
    std::string(UPDATE_FILE_PATH)
);
/**
 * 系统配置信息初始化
 * 
 * @param sConfigfile 传入的系统配置信息文件
 *  
 * @return 硬件配置处理的结果
 */
int SystemConfigInfo::ConfigInitilize(){
   if(pConfigfile && this->pShardSystemConfig.get()){
        Json::Value root;
        std::ifstream ifs;
        ifs.open(pConfigfile->c_str());

        Json::CharReaderBuilder builder;
        builder["collectComments"] = true;
        JSONCPP_STRING errs;
        if (!parseFromStream(builder, ifs, &root, &errs)) {
            std::cout << errs << std::endl;
            return EXIT_FAILURE;
        }
        std::cout << root << std::endl;

        //串口状态
        this->pShardSystemConfig->m_baud = root["Uart"]["Baud"].asInt();
        this->pShardSystemConfig->m_data_bits = root["Uart"]["DataBits"].asInt();
        this->pShardSystemConfig->m_stop_bits = root["Uart"]["StopBits"].asInt();
        this->pShardSystemConfig->m_parity = std::string(root["Uart"]["Parity"].asString());

        //sokcet TCP状态
        this->pShardSystemConfig->m_tcp_ipaddr = std::string(root["SocketTcp"]["ipaddr"].asString());
        this->pShardSystemConfig->m_tcp_net_port = root["SocketTcp"]["net_port"].asInt();

        //sokcet UDP状态
        this->pShardSystemConfig->m_udp_ipaddr = std::string(root["SocketUdp"]["ipaddr"].asString());
        this->pShardSystemConfig->m_udp_net_port = root["SocketUdp"]["net_port"].asInt();

        /* get ip addr */
        // {
        //     struct ifaddrs * ifAddrStruct=NULL;
        //     void * tmpAddrPtr=NULL;

        //     getifaddrs(&ifAddrStruct);

        //     char ifaname[] = "wlan0";

        //     while(ifAddrStruct != NULL){
        //         if (ifAddrStruct->ifa_addr->sa_family==AF_INET) { // check it is IP4
        //         // is a valid IP4 Address
        //         char addressBuffer[INET_ADDRSTRLEN];
        //         tmpAddrPtr=&((struct sockaddr_in*)ifAddrStruct->ifa_addr)->sin_addr;
        //         inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
        //         if(!strncmp(ifAddrStruct->ifa_name,ifaname,strlen(ifaname)))
        //             //printf("%s IP Address %s \n", ifAddrStruct->ifa_name, addressBuffer);
        //             this->pShardSystemConfig->m_tcp_ipaddr = addressBuffer;
        //             this->pShardSystemConfig->m_udp_ipaddr = addressBuffer;
        //         }
        //         ifAddrStruct=ifAddrStruct->ifa_next; 
        //     }
        // }

        //硬件状态
        // this->pShardSystemConfig->m_led0_status = root["Led"].asInt();
        // this->pShardSystemConfig->m_beep0_status = root["Beep"].asInt();

        //设备名称
        this->pShardSystemConfig->m_dev_led = root["Device"]["Led"].asString();
        this->pShardSystemConfig->m_dev_beep = root["Device"]["Beep"].asString();
        this->pShardSystemConfig->m_dev_serial = root["Device"]["Serial"].asString();
        this->pShardSystemConfig->m_dev_icm_spi = root["Device"]["IcmSpi"].asString();
        this->pShardSystemConfig->m_dev_rtc = root["Device"]["Rtc"].asString();
        this->pShardSystemConfig->m_dev_ap_i2c = root["Device"]["ApI2c"].asString();
        this->pShardSystemConfig->m_dev_mpu = root["Device"]["MPU"].asString();
        this->pShardSystemConfig->m_dev_gps = root["Device"]["GPS"].asString();
        this->pShardSystemConfig->m_dev_mq135 = root["Device"]["MQ135"].asString();
        this->pShardSystemConfig->m_dev_dht11 = root["Device"]["DHT11"].asString();

        //下载路径
        this->pShardSystemConfig->m_file_path = std::string(root["FilePath"].asString());
        ifs.close();
        return EXIT_SUCCESS;
    
   }
   else{
      std::cout << "empty pointer!" << std::endl;
      return EXIT_FAILURE;
   }
}

/**
 * 显示系统的配置信息
 * 
 * @param NULL
 *  
 * @return NULL
 */
void SystemConfigInfo::ShowSSystemConfigInfo(void)
{
    //Serial
    std::cout<<"Baud:"<<this->pShardSystemConfig->m_baud<<std::endl;
    std::cout<<"DataBits:"<<this->pShardSystemConfig->m_data_bits<<std::endl;
    std::cout<<"StopBits:"<<this->pShardSystemConfig->m_stop_bits<<std::endl;
    std::cout<<"Parity:"<<this->pShardSystemConfig->m_parity<<std::endl;

    //Tcp
    std::cout<<"Tcp Ipaddr:"<<this->pShardSystemConfig->m_tcp_ipaddr<<std::endl;
    std::cout<<"Tcp Port:"<<this->pShardSystemConfig->m_tcp_net_port<<std::endl;

    //Udp
    std::cout<<"Udp Ipaddr:"<<this->pShardSystemConfig->m_udp_ipaddr<<std::endl;
    std::cout<<"Udp port:"<<this->pShardSystemConfig->m_udp_net_port<<std::endl;

    //Hardwart Status
    std::cout<<"led status:"<<this->pShardSystemConfig->m_led0_status<<std::endl;
    std::cout<<"beep status:"<<this->pShardSystemConfig->m_beep0_status<<std::endl;

    //Device Name
    std::cout<<"tty dev:"<<this->pShardSystemConfig->m_dev_serial<<std::endl;
    std::cout<<"led dev:"<<this->pShardSystemConfig->m_dev_led<<std::endl;
    std::cout<<"beep dev:"<<this->pShardSystemConfig->m_dev_beep<<std::endl;
    std::cout<<"mpu dev:"<<this->pShardSystemConfig->m_dev_mpu<<std::endl;
    std::cout<<"gps dev:"<<this->pShardSystemConfig->m_dev_gps<<std::endl;
    std::cout<<"mq135 dev:"<<this->pShardSystemConfig->m_dev_mq135<<std::endl;
    std::cout<<"dht11 dev:"<<this->pShardSystemConfig->m_dev_dht11<<std::endl;

    //Download Directory
    std::cout<<"Download:"<<this->pShardSystemConfig->m_file_path<<std::endl;
}