#ifndef _GPS_H
#define _GPS_H

#include "hardware/basehardware.h"
#include "SystemConfig.h"
#include "common/Typedef.h"

extern "C"
{
#include "nmea/nmea.h"
}


class CGPS:public BaseHardWare<uint8_t>{
public:
    CGPS():BaseHardWare() { }
    ~CGPS() { }

    void HWInit() override;
    void HWRelease(void) override;
    int  HWread(uint8_t *data) override;
    int  HWwrite(uint8_t *data) override { return -1;}


    /******************************************************************************************************** 
    **    函数名称:            bit        IsLeapYear(uint8_t    iYear) 
    **    功能描述:            判断闰年(仅针对于2000以后的年份) 
    **    入口参数：            iYear    两位年数 
    **    出口参数:            uint8_t        1:为闰年    0:为平年 
    ********************************************************************************************************/ 
    static uint8_t IsLeapYear(uint8_t iYear) 
    { 
        uint16_t    Year; 
        Year    =    2000+iYear; 
        if((Year&3)==0) 
        { 
            return ((Year%400==0) || (Year%100!=0)); 
        } 
            return 0; 
    } 

/******************************************************************************************************** 
**     函数名称:            void    GMTconvert(uint8_t *DT,uint8_t GMT,uint8_t AREA) 
**    功能描述:            格林尼治时间换算世界各时区时间 
**    入口参数：            *DT:    表示日期时间的数组 格式 YY,MM,DD,HH,MM,SS 
**                        GMT:    时区数 
**                        AREA:    1(+)东区 W0(-)西区 
********************************************************************************************************/ 
    void GMTconvert(nmeaTIME *SourceTime, nmeaTIME *ConvertTime, uint8_t GMT,uint8_t AREA) 
    { 
        uint32_t    YY,MM,DD,hh,mm,ss;        //年月日时分秒暂存变量 
        
        if(GMT==0)    return;                //如果处于0时区直接返回 
        if(GMT>12)    return;                //时区最大为12 超过则返回         

        YY    =    SourceTime->year;                //获取年 
        MM    =    SourceTime->mon;                 //获取月 
        DD    =    SourceTime->day;                 //获取日 
        hh    =    SourceTime->hour;                //获取时 
        mm    =    SourceTime->min;                 //获取分 
        ss    =    SourceTime->sec;                 //获取秒 

        if(AREA)                        //东(+)时区处理 
        { 
            if(hh+GMT<24)    hh += GMT; //如果与格林尼治时间处于同一天则仅加小时即可 
            else                        //如果已经晚于格林尼治时间1天则进行日期处理 
            { 
                hh = hh+GMT-24;        //先得出时间 
                if(MM==1 || MM==3 || MM==5 || MM==7 || MM==8 || MM==10)    //大月份(12月单独处理) 
                { 
                    if(DD<31)    DD++; 
                    else 
                    { 
                        DD = 1; 
                        MM++; 
                    } 
                } 
                else if(MM==4 || MM==6 || MM==9 || MM==11)                //小月份2月单独处理) 
                { 
                    if(DD<30)    DD++; 
                    else 
                    { 
                        DD    =    1; 
                        MM    ++; 
                    } 
                } 
                else if(MM==2)    //处理2月份 
                { 
                    if((DD==29) || (DD==28 && IsLeapYear(YY)==0))        //本来是闰年且是2月29日 或者不是闰年且是2月28日 
                    { 
                        DD    =    1; 
                        MM    ++; 
                    } 
                    else    DD++; 
                } 
                else if(MM==12)    //处理12月份 
                { 
                    if(DD<31)    DD++; 
                    else        //跨年最后一天 
                    {               
                        DD    =    1; 
                        MM    =    1; 
                        YY    ++; 
                    } 
                } 
            } 
        } 
        else 
        {     
            if(hh>=GMT)    hh    -=    GMT;    //如果与格林尼治时间处于同一天则仅减小时即可 
            else                        //如果已经早于格林尼治时间1天则进行日期处理 
            { 
                hh    =    hh+24-GMT;        //先得出时间 
                if(MM==2 || MM==4 || MM==6 || MM==8 || MM==9 || MM==11)    //上月是大月份(1月单独处理) 
                { 
                    if(DD>1)    DD--; 
                    else 
                    { 
                        DD    =    31; 
                        MM    --; 
                    } 
                } 
                else if(MM==5 || MM==7 || MM==10 || MM==12)                //上月是小月份2月单独处理) 
                { 
                    if(DD>1)    DD--; 
                    else 
                    { 
                        DD    =    30; 
                        MM    --; 
                    } 
                } 
                else if(MM==3)    //处理上个月是2月份 
                { 
                    if((DD==1) && IsLeapYear(YY)==0)                    //不是闰年 
                    { 
                        DD    =    28; 
                        MM    --; 
                    } 
                    else    DD--; 
                } 
                else if(MM==1)    //处理1月份 
                { 
                    if(DD>1)    DD--; 
                    else        //新年第一天 
                    {               
                        DD    =    31; 
                        MM    =    12; 
                        YY    --; 
                    } 
                } 
            } 
        }         

        ConvertTime->year   =    YY;                //更新年 
        ConvertTime->mon    =    MM;                //更新月 
        ConvertTime->day    =    DD;                //更新日 
        ConvertTime->hour   =    hh;                //更新时 
        ConvertTime->min    =    mm;                //更新分 
        ConvertTime->sec    =    ss;                //更新秒 
    }  

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


    void GPS_InfoShow(GPS_Data* data);

private:

    int fd;
    nmeaPOS _dpos;
    nmeaINFO _info;
    nmeaPARSER _parser;
    nmeaTIME _beiJingTime;   //北京时间
    double _deg_lat;         //转换成[degree].[degree]格式的纬度
    double _deg_lon;         //转换成[degree].[degree]格式的经度

    char _tmp_buf[200];
    char _buff[4096];
};

#endif  // GPS