#include "hardware/dht11.h"


void CDHT11::HWInit(){

    std::shared_ptr<SystemConfigInfo::SSystemConfig> pSSystemConfig(SystemConfigInfo::pShardSystemConfig);

    fd = open(pSSystemConfig->m_dev_dht11.c_str(), O_RDONLY);

    if(fd < 0){
        printf("DHT11_Dev Open %s Failed, Error:%s!\n",
        pSSystemConfig->m_dev_dht11.c_str(), strerror(errno));
    }
    else
        printf("DHT11_Dev Open Successfully\n");

}


int CDHT11::HWread(uint8_t *data){
    uint8_t buf[6];
    int length;

    length = read(fd, buf, 6);
    if(length == -1){
        printf("dht11 read error! \n");
        return -1;
    }

    memcpy(data,buf,sizeof(buf));

    return 0;
}


void CDHT11::HWRelease() {
    close(fd);
}
