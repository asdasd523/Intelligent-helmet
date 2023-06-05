#ifndef _MPU6050_H
#define _MPU6050_H

#include "hardware/basehardware.h"
#include "SystemConfig.h"
#include "common/filter.h"
#include <assert.h>
#include <unistd.h>

class CMPU:public BaseHardWare<uint8_t>{
public:
    CMPU(int co):BaseHardWare(),count(co){}
    ~CMPU(){};

    void HWInit() override;
    void HWRelease(void) override;
    int  HWread(uint8_t *data) override;
    int  HWwrite(uint8_t *data) override {return 0;}

    void MPU_Offset();

private:
    int fd;
    int a_offset[3],g_offset[3];
    float a[3],g[3],angle[3];     
    int count;
    Kalman_filter kalmanFlt;
};


#endif