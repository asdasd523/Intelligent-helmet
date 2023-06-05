#include "hardware/MQ135.h"


void CMQ135::HWInit(){
    std::shared_ptr<SystemConfigInfo::SSystemConfig> pSSystemConfig(SystemConfigInfo::pShardSystemConfig);

    fd = open(pSSystemConfig->m_dev_mq135.c_str(), O_RDONLY);

    if(fd < 0){
        printf("MQ135_Dev Open %s Failed, Error:%s!\n",
        pSSystemConfig->m_dev_mq135.c_str(), strerror(errno));
    }
    else
        printf("MQ135_Dev Open Successfully\n");
}


int CMQ135::HWread(uint8_t *data){
    int error = -20;
    uint8_t MQ135_status = 0;

    error = read(fd,&MQ135_status, sizeof(MQ135_status));
    if(error < 0){
        printf("read file error! \n ");
        return -1;
    }

    usleep(1000 * 100);   //延时100毫秒

    *data = MQ135_status;

    return 0;
}


void CMQ135::HWRelease() {
    close(fd);
}
