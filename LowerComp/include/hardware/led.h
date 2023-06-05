#ifndef _LED_H
#define _LED_H

#include "hardware/basehardware.h"
#include "SystemConfig.h"
#include <assert.h>
#include <unistd.h>

class CLed:public BaseHardWare<uint8_t>{
public:
    CLed():BaseHardWare(){}
    ~CLed(){}

    void HWInit() override;
    void HWRelease(void) override;
    int  HWread(uint8_t *data) override;
    int  HWwrite(uint8_t *data) override;

private:
    int fd;
};


#endif