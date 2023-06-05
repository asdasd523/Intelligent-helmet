#include "hardware/beep.h"

void CBeep::HWInit(){
        std::shared_ptr<SystemConfigInfo::SSystemConfig> pSSystemConfig(SystemConfigInfo::pShardSystemConfig);

        fd = open(pSSystemConfig->m_dev_beep.c_str(), O_RDWR | O_NDELAY);
        if(fd == -1 || fd == 0){
            printf("Beep_Dev Open %s Failed, Error:%s!\n",
                pSSystemConfig->m_dev_beep.c_str(), strerror(errno));
        }
        else{
            printf("Beep_Dev Open Successfully\n");
        }
}

void CBeep::HWRelease(void) {
        close(fd);
}


int CBeep::HWread(uint8_t *data) {
        ssize_t nSize;

        if(fd != -1){
            nSize = read(fd, data, 1);
            if(nSize < 0)
                printf("BEEP Read Failed, Error:%s, nSize:%d\n", strerror(errno), (int)nSize);
        }

        return nSize;
}
int CBeep::HWwrite(uint8_t *data) {
        ssize_t nSize;
        assert(data != nullptr);
        uint8_t Data = *data;
        if (fd != -1)
        {
            nSize = write(fd, &Data, sizeof(Data)); //将数据写入LED
            if (nSize < 0)
                    printf("Write Failed, nSize:%d\n", (int)nSize);
            else
                    printf("Beep Write Successfully ,write data: %d \r\n", *data);
        }
        else{
            printf("BEEP Open Error! \r\n");
            return RT_FAIL;
        }

        return nSize;
}