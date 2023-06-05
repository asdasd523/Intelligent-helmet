/*!
    指令相关的数据存储管理实现
*/
#include "include/hardwareclient.h"
#include <QString>
#include <string>

hardwareInfo* hardwareInfo::HWInfoptr = new hardwareInfo;

hardwareInfo* hardwareInfo::gethardwareInfoptr(){
    return HWInfoptr;
}


QString hardwareInfo::getLEDStatus(uint32_t Statue){
    QString res = "";
    if(!Statue) return QString("OFF");
    if(Statue & 0b01)
        res += QString(" blue ");
    if(Statue & 0b10)
        res += QString(" green ");
    if(Statue & 0b100)
        res += QString(" red ");

    return res;

}

std::function<QString(uint8_t*, int)> hardwareInfo::GetInfo_pFunc = {
        [](uint8_t *pRecvData,int nSize)->QString{
            QString DecodeBuf  = "";
            QString str;

            hardwareInfo::SRegInfoList* pSRegInfo;

            if(nSize > 0){
                pSRegInfo =  reinterpret_cast<hardwareInfo::SRegInfoList *>(pRecvData);

                DecodeBuf  = QString::fromLocal8Bit("LED:")+
                                hardwareInfo::HWInfoptr->getLEDStatus(pSRegInfo->s_base_status.b.led)
                                +QString::fromLocal8Bit("\n");
                DecodeBuf += QString::fromLocal8Bit("beep:%1\n").
                              arg(pSRegInfo->s_base_status.b.beep == 0 ? "OFF":"ON");
                DecodeBuf += QString::fromLocal8Bit("gyro angle x:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_angle_x)); //gyro angle x
                DecodeBuf += QString::fromLocal8Bit("gyro angle y:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_angle_y)); //gyro angle y
                DecodeBuf += QString::fromLocal8Bit("gyro angle z:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_angle_z)); //gyro angle z
                DecodeBuf += QString::fromLocal8Bit("GPS deg_lat:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_gps.deg_lat));
                DecodeBuf += QString::fromLocal8Bit("GPS deg_lon:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_gps.deg_lon));
                DecodeBuf += QString::fromLocal8Bit("Temp:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_temp));
                DecodeBuf += QString::fromLocal8Bit("Humi:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_humi));
                DecodeBuf += QString::fromLocal8Bit("GasConcentration:%1 \n").
                              arg(str.setNum(pSRegInfo->sensor_gasconcen));
            }

            return DecodeBuf;
        }
};


std::function<QString(uint8_t*, int)> hardwareInfo::Refresh_pFunc = {
        [](uint8_t*, int){
            QString str = "Refresh hardward status";
            return str;
        }
};


hardwareInfo::HWCommandInfo* hardwareInfo::getHwCmd(hw_cmd Hw,quint8 status){

    memset(pHwCmd,0,sizeof(HWCommandInfo));

    switch(Hw){
        case LED_ON:
            led_on_cmd.append(status);
            pHwCmd->m_pbuffer = led_on_cmd.data();
            pHwCmd->m_nSize   = led_on_cmd.size();
            pHwCmd->pFunc = nullptr;
            led_on_cmd.pop_back();
            break;
        case LED_OFF:
            pHwCmd->m_pbuffer = led_off_cmd.data();
            pHwCmd->m_nSize   = led_off_cmd.size();
            pHwCmd->pFunc = nullptr;
            break;
        case GET_INFO_CMD:
            pHwCmd->m_pbuffer = get_info_cmd.data();
            pHwCmd->m_nSize   = get_info_cmd.size();
            pHwCmd->pFunc = hardwareInfo::GetInfo_pFunc;
            break;
        case SYSTEM_UPDATE_CMD:
            pHwCmd->m_pbuffer = get_info_cmd.data();
            pHwCmd->m_nSize   = get_info_cmd.size();
            pHwCmd->pFunc = hardwareInfo::Refresh_pFunc;
            break;
        default:

            break;
    }

    return pHwCmd;
}

