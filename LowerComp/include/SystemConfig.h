#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include <fstream>
#include <iostream>
#include "json/json.h"
#include <string>
#include "common/Typedef.h"
#include <memory>

#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>


class SystemConfigInfo{

public:
   SystemConfigInfo(std::string  *Configfile):pConfigfile(Configfile){}
   ~SystemConfigInfo(){
     //delete SystemConfigInfo::pSSystemConfig;
     delete pConfigfile;
    };
   int ConfigInitilize();
   void ShowSSystemConfigInfo(void);


struct SSystemConfig{
     /*串口配置*/
     int m_baud;
     int m_data_bits;
     int m_stop_bits;
     std::string m_parity;

     /*TCP Socket 配置*/
     std::string m_tcp_ipaddr;
     int m_tcp_net_port;

     /*UDP Socket配置*/
     std::string m_udp_ipaddr;
     int m_udp_net_port;

     /*硬件的初始化状态*/
     int m_led0_status;
     int m_beep0_status;

     /*Device 配置信息*/
     std::string m_dev_led;
     std::string m_dev_beep;
     std::string m_dev_serial;
     std::string m_dev_icm_spi;
     std::string m_dev_rtc;
     std::string m_dev_ap_i2c;
     std::string m_dev_mpu;
     std::string m_dev_gps;   
     std::string m_dev_mq135;
     std::string m_dev_dht11;

     /*文件更新的下载地址*/
     std::string m_file_path;

SSystemConfig(     
     int baud,
     int data_bits,
     int stop_bits,
     std::string parity,

     /*TCP Socket 配置*/
     std::string tcp_ipaddr,
     int tcp_net_port,

     /*UDP Socket配置*/
     std::string udp_ipaddr,
     int udp_net_port,

     /*硬件的初始化状态*/
     int led0_status,
     int beep0_status,

     /*Device 配置信息*/
     std::string dev_led,
     std::string dev_beep,
     std::string dev_serial,
     std::string dev_icm_spi,
     std::string dev_rtc,
     std::string dev_ap_i2c,
     std::string dev_mpu, 
     std::string dev_gps,
     std::string dev_mq135,
     std::string dev_dht11,  

     /*文件更新的下载地址*/
     std::string file_path
):m_baud(baud),m_beep0_status(beep0_status),m_data_bits(data_bits),m_dev_ap_i2c(dev_ap_i2c),
  m_dev_beep{dev_beep},m_dev_icm_spi(dev_icm_spi),m_dev_led(dev_led),m_dev_rtc(dev_rtc),
  m_dev_serial(dev_serial),m_file_path(file_path),m_led0_status(led0_status),m_parity(parity),
  m_stop_bits(stop_bits),m_tcp_ipaddr(tcp_ipaddr),m_tcp_net_port(tcp_net_port),
  m_udp_ipaddr(udp_ipaddr),m_udp_net_port(udp_net_port),m_dev_mpu(dev_mpu),m_dev_gps(dev_gps),
  m_dev_mq135(dev_mq135),m_dev_dht11(dev_dht11)
  {};
};

static std::shared_ptr<SystemConfigInfo::SSystemConfig> pShardSystemConfig;

private:
   
   std::string   *pConfigfile;
};





#endif