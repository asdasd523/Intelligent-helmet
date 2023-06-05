#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <errno.h>
#include <memory>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>


/**************************************************************************
* Global Macro Definition
***************************************************************************/
#define DEVICE_VERSION          "version 0.0.7 20200724"

#define UART_MODULE_ON          1
#define SOCKET_TCP_MODULE_ON    1
#define SOCKET_UDP_MODULE_ON    1

/*自定义协议应用测试*/
#define __SYSTEM_DEBUG          0
#define __WORK_IN_WSL           1  //在WSL中，Posix Mq不支持，改为FIFO方案

/*调试打印口显示*/
#define __DEBUG_PRINTF			1
#define __DRIVER_DEBUG          1
#define __SOCKET_DEBUG          1

/*返回状态*/
#define RT_INVALID_MQ_SIZE      -4
#define RT_INVALID_BUF_SIZE     -3
#define RT_INVALID_MQ           -2
#define RT_OK               	0
#define RT_FAIL             	1
#define RT_EMPTY            	2
#define RT_TIMEOUT              3
#define RT_INVALID              4

//默认设备信息   need to modefy
#define TTY_DEVICE              "/dev/ttymxc1"
#define LED_DEVICE              "/dev/led"
#define BEEP_DEVICE             "/dev/beep"
#define ICM_SPI_DEVICE          "/dev/icm20608"
#define RTC_DEVICE              "/dev/rtc0"
#define AP_I2C_DEVICE           "/dev/ap3216"
#define MPU_DEVICE              "/dev/I2C1_mpu6050"
#define GPS_DEVICE              "/dev/ttymxc2"
#define MQ135_DEVICE            "/dev/MQ135"
#define DHT11_DEVICE            "/dev/dht11"

//默认下载路径
#define UPDATE_FILE_PATH        "/usr/download/"

//默认IP地址和端口
#define IP_ADDR                 "127.0.0.1"
#define TCP_PORT                8000
#define UDP_PORT                8001

//默认串口配置信息
#define BAUD                    115200
#define DATABITS                8
#define STOPBITS                1
#define PARITY                  "n"

//默认设备ID
#define DEVICE_ID               0x01


/**************************************************************************
* Global Type Definition
***************************************************************************/
typedef signed char    int8_t;
typedef signed short   int16_t;
typedef signed int     int32_t;
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

/**************************************************************************
* Global Functon Declaration
***************************************************************************/
/*调试接口*/
#if __DEBUG_PRINTF	== 1
#define USR_DEBUG		printf
#else
static int USR_DEBUG(const char *format, ...){}
#endif

#if __DRIVER_DEBUG == 1
#define DRIVER_DEBUG		USR_DEBUG
#else
static int DRIVER_DEBUG(const char *format, ...){}
#endif

#if __SOCKET_DEBUG == 1
#define SOCKET_DEBUG        USR_DEBUG
#else
static int SOCKET_DEBUG(const char *format, ...){}
#endif

void SystemLogArray(uint8_t *pArrayBuffer, uint16_t nArraySize);


#endif