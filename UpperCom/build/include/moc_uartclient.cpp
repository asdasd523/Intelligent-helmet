/****************************************************************************
** Meta object code from reading C++ file 'uartclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/uartclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uartclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CUartInfo_t {
    QByteArrayData data[13];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CUartInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CUartInfo_t qt_meta_stringdata_CUartInfo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CUartInfo"
QT_MOC_LITERAL(1, 10, 14), // "send_edit_recv"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "send_edit_test"
QT_MOC_LITERAL(4, 41, 11), // "GetUARTOpen"
QT_MOC_LITERAL(5, 53, 22), // "CUartInfo::UartInfo_t*"
QT_MOC_LITERAL(6, 76, 4), // "Info"
QT_MOC_LITERAL(7, 81, 12), // "GetUARTClose"
QT_MOC_LITERAL(8, 94, 12), // "dataReceived"
QT_MOC_LITERAL(9, 107, 8), // "GetDevId"
QT_MOC_LITERAL(10, 116, 2), // "Id"
QT_MOC_LITERAL(11, 119, 18), // "UartClientSendFunc"
QT_MOC_LITERAL(12, 138, 12) // "SSendBuffer*"

    },
    "CUartInfo\0send_edit_recv\0\0send_edit_test\0"
    "GetUARTOpen\0CUartInfo::UartInfo_t*\0"
    "Info\0GetUARTClose\0dataReceived\0GetDevId\0"
    "Id\0UartClientSendFunc\0SSendBuffer*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CUartInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   55,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,   10,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void CUartInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CUartInfo *_t = static_cast<CUartInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_edit_recv((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->send_edit_test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->GetUARTOpen((*reinterpret_cast< CUartInfo::UartInfo_t*(*)>(_a[1]))); break;
        case 3: _t->GetUARTClose(); break;
        case 4: _t->dataReceived(); break;
        case 5: _t->GetDevId((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 6: _t->UartClientSendFunc((*reinterpret_cast< SSendBuffer*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SSendBuffer* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CUartInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CUartInfo::send_edit_recv)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CUartInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CUartInfo::send_edit_test)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CUartInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CUartInfo.data,
      qt_meta_data_CUartInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CUartInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CUartInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CUartInfo.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CProtocolInfo"))
        return static_cast< CProtocolInfo*>(this);
    return QObject::qt_metacast(_clname);
}

int CUartInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CUartInfo::send_edit_recv(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CUartInfo::send_edit_test(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
