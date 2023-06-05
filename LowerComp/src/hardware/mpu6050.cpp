#include "hardware/mpu6050.h"

void CMPU::HWInit()
{
    std::shared_ptr<SystemConfigInfo::SSystemConfig> pSSystemConfig(SystemConfigInfo::pShardSystemConfig);


    fd = open(pSSystemConfig->m_dev_mpu.c_str(), O_RDWR | O_NDELAY);
    if(fd < 0){
        printf("MPU_Dev Open %s Failed, Error:%s!\n",
        pSSystemConfig->m_dev_mpu.c_str(), strerror(errno));
    }
    else
        printf("MPU_Dev Open Successfully\n");

    MPU_Offset();
}

void CMPU::HWRelease()
{
    close(fd);
}



int CMPU::HWread(uint8_t *data)
{
    short resive_data[6];
    int error;
    uint8_t* pdata;

    error = read(fd,resive_data,12);

    if(error < 0){
        printf("read MPU error \n");
        close(fd);
        return -1;
    }

    for(int i = 0;i < 3;i++){
        a[i] = resive_data[i]  - a_offset[i];
        g[i] = resive_data[i+3]- g_offset[i];
        g[i] = -g[i];
        kalmanFlt.set_value(a[i],g[i]);
        kalmanFlt.filter();
        angle[i] = kalmanFlt.get_value();
    }

    pdata = (uint8_t*)angle;
    for(int i = 0;i < sizeof(angle);i++){
        data[i] = pdata[i];
    }

    return 0;
}

void CMPU::MPU_Offset()
{
    short resive_data[6];
    int error;

    for(int i = 0;i < count;i++){
        error = read(fd,resive_data,12);

        if(error < 0){
            printf("read MPU error \n");
            close(fd);
            return;
        }

        for(int j = 0;j < 3;j++){
            a_offset[j] += (int)resive_data[j];
            g_offset[j] += (int)resive_data[j+3]; 
        }

        usleep(5);
    }

    for(int j = 0;j < 3;j++){
        a_offset[j] /= count;
        g_offset[j] /= count;
    }
}