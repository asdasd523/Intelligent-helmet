#ifndef _INCLUDE_BASE_HARDWARD_H
#define _INCLUDE_BASE_HARDWARD_H

#include "common/Typedef.h"

template<class T>
class BaseHardWare{
public:
    BaseHardWare() {};
    ~BaseHardWare() {};

    virtual void HWInit(void) = 0;
    virtual void HWRelease(void) = 0;
    virtual int HWread(T *data) = 0;
    virtual int HWwrite(T *data) = 0;
};

#endif