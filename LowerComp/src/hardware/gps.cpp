#include "hardware/gps.h"


//error func
void error(const char *str,int str_size){
    printf("Error: ");
    write(1, str, str_size);
    printf("\n");
}

void CGPS::HWInit(){
    std::shared_ptr<SystemConfigInfo::SSystemConfig> pSSystemConfig(SystemConfigInfo::pShardSystemConfig);

    fd = open(pSSystemConfig->m_dev_gps.c_str(), O_RDONLY);

    if(fd < 0){
        printf("GPS_Dev Open %s Failed, Error:%s!\n",
        pSSystemConfig->m_dev_gps.c_str(), strerror(errno));
    }
    else
        printf("GPS_Dev Open Successfully\n");

    nmea_property()->error_func = &error;

    nmea_zero_INFO(&_info);
    nmea_parser_init(&_parser);
}
void CGPS::HWRelease(){
    nmea_parser_destroy(&_parser);
    close(fd);
}
int  CGPS::HWread(uint8_t *data){

    GPS_Data _GPS_Data;
    int _size = 0,_len = 0;

    for(int it = 0; it < 32; it++) {
        memset(_tmp_buf, 0, 100);
        _size = (int)read(fd, _tmp_buf, 100);
        
        if (_size > 1) {
            //USR_DEBUG("buff:%d len:%d tmp:%d size:%d \n",sizeof(_buff),_len,sizeof(_tmp_buf),_size);
            if(_len >= sizeof(_buff))
                break;

            if((sizeof(_buff) - _len) > _size)
                _size = sizeof(_buff) - _len;

            memcpy(_buff + _len, _tmp_buf, _size);
            _len += _size;
            memcpy(_buff + _len - 1, "\r\n", 2);   //情况数据
            _len += 1;
        }
    }

    nmea_parse(&_parser, _buff, _len, &_info);

    // info.lat lon中的格式为[degree][min].[sec/60]，使用以下函数转换成[degree].[degree]格式
    _deg_lat = nmea_ndeg2degree(_info.lat);
    _deg_lon = nmea_ndeg2degree(_info.lon);

    GMTconvert(&_info.utc,&_beiJingTime,8,1);

    _GPS_Data.cur_time.year = _beiJingTime.year+1900;
    _GPS_Data.cur_time.mon  = _beiJingTime.mon;
    _GPS_Data.cur_time.day  = _beiJingTime.day;
    _GPS_Data.cur_time.hour = _beiJingTime.hour;
    _GPS_Data.cur_time.min  = _beiJingTime.min;
    _GPS_Data.cur_time.sec  = _beiJingTime.sec;

    _GPS_Data.deg_lat = _deg_lat;
    _GPS_Data.deg_lon = _deg_lon;

    _GPS_Data.elv       = _info.elv;
    _GPS_Data.speed     = _info.speed;
    _GPS_Data.direction = _info.direction;

    _GPS_Data.satinfo.inuse  = _info.satinfo.inuse;
    _GPS_Data.satinfo.inview = _info.satinfo.inview;

    _GPS_Data.PDOP = _info.PDOP;
    _GPS_Data.HDOP = _info.HDOP;
    _GPS_Data.VDOP = _info.VDOP;

    memcpy( data,(uint8_t*)&_GPS_Data,sizeof(GPS_Data));

    return 0;
}

void CGPS::GPS_InfoShow(GPS_Data* data)
{
    printf("\r\n时间:%d-%02d-%02d,%d:%d:%d\r\n", data->cur_time.year, 
                                                data->cur_time.mon,
                                                data->cur_time.day,
                                                data->cur_time.hour,
                                                data->cur_time.min,
                                                data->cur_time.sec);

    printf("\r\n正在使用的北斗卫星:%d,可见北斗卫星：%d",data->satinfo.inuse,
                                                   data->satinfo.inview);

    printf("\r\n纬度:%f,经度%f\r\n",data->deg_lat,
                                   data->deg_lon);
    printf("\r\n海拔高度:%f 米 ", data->elv);
    printf("\r\n速度:%f km/h ",  data->speed);
    printf("\r\n航向:%f 度",     data->direction);

    printf("\r\nPDOP:%f,HDOP:%f,VDOP:%f\n", data->PDOP,
                                            data->HDOP,
                                            data->VDOP);
}