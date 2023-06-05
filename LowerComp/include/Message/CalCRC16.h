#ifndef _CALCRC16_H
#define _CALCRC16_H

#include <common/Typedef.h>

/*crc16校验运算*/
uint16_t crc16(uint16_t crc, uint8_t const *buffer, uint16_t len);

#endif