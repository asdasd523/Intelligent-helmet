#ifndef _DHT11_H
#define _DHT11_H

#include "hardware/basehardware.h"
#include "SystemConfig.h"
#include "common/Typedef.h"


class CDHT11:public BaseHardWare<uint8_t>{
public:
    CDHT11():BaseHardWare()  {}
    ~CDHT11()   {}

    void HWInit() override;
    void HWRelease(void) override;
    int  HWread(uint8_t *data) override;
    int  HWwrite(uint8_t *data) override { return -1; }

private:
    int fd;

};


#endif