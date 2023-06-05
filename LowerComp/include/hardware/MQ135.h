#ifndef _MQ135_H
#define _MQ135_H

#include "hardware/basehardware.h"
#include "SystemConfig.h"
#include "common/Typedef.h"


class CMQ135:public BaseHardWare<uint8_t>{
public:
    CMQ135():BaseHardWare(){}
    ~CMQ135(){}

    void HWInit() override;
    void HWRelease(void) override;
    int  HWread(uint8_t *data) override;
    int  HWwrite(uint8_t *data) override { return -1; }

private:
    int fd;

};



#endif