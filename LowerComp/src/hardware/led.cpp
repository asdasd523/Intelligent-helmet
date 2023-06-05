#include "hardware/led.h"   


void CLed::HWInit(){
        std::shared_ptr<SystemConfigInfo::SSystemConfig> pSSystemConfig(SystemConfigInfo::pShardSystemConfig);

        fd = open(pSSystemConfig->m_dev_led.c_str(), O_RDWR | O_NDELAY);
        if(fd == -1 || fd == 0){
            printf("Led_Dev Open %s Failed, Error:%s!\n",
                pSSystemConfig->m_dev_led.c_str(), strerror(errno));
        }
        else{
            printf("Led_Dev Open Successfully\n");
        }
}

void CLed::HWRelease(void) {
        close(fd);
}

int CLed::HWread(uint8_t *data) {
        ssize_t nSize;

        if(fd != -1){
            nSize = read(fd, data, 1);
            if(nSize < 0)
                printf("Led Read Failed, Error:%s, nSize:%d\n", strerror(errno), (int)nSize);
        }

        return nSize;
}
int CLed::HWwrite(uint8_t *data) {
        ssize_t nSize;
        assert(data != nullptr);
        uint8_t Data = *data;
        if (fd != -1)
        {
            nSize = write(fd, &Data, sizeof(Data)); //将数据写入LED
            if (nSize < 0)
                    printf("Write Failed, nSize:%d\n", (int)nSize);
            else
                    printf("LED Write Successfully ,write data: %d \r\n", *data);
        }
        else{
            printf("LED Open Error! \r\n");
            return RT_FAIL;
        }

        return nSize;
}