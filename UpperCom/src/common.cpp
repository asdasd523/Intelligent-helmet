#include "include/common.h"


/*!
    将数组转成字符串数据
*/
QString byteArrayToHexString(QString head, const uint8_t* str, uint16_t size, QString tail)
{
    QString result = head;
    QString s;

    for(int i = 0; i < size; ++i)
    {
        s = QString("%1").arg(*(str+i), 0, 16);  //str[] -> *(str+i)
        if(s.length() == 1)
            result.append("0x0");
        else
            result.append("0x");
        result.append(s.toUpper());
        result.append(' ');
    }
    result += tail;
    result.chop(1);
    return result;
}
