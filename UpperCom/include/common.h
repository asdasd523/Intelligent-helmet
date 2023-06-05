#ifndef COMMON_H
#define COMMON_H

#include <include/typedef.h>
#include <functional>
#include <QString>

using std::unary_function;

template <class _Ret, class _Tp>
class mem_fun_t : public unary_function<_Tp* , _Ret> {
public:
  explicit mem_fun_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}
  _Ret operator()(_Tp* __p) const {
           return (__p->*_M_f)();
}

private:
  _Ret (_Tp::*_M_f)();

};


template <class _Ret, class _Tp>
inline mem_fun_t<_Ret,_Tp> mem_fun(_Ret (_Tp::*__f)()){
     return mem_fun_t<_Ret,_Tp>(__f);
}


QString byteArrayToHexString(QString head, const uint8_t* str, uint16_t size, QString tail);

#endif // COMMON_H
