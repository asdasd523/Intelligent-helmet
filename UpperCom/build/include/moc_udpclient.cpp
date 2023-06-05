/****************************************************************************
** Meta object code from reading C++ file 'udpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/udpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CUdpSocketInfo_t {
    QByteArrayData data[17];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CUdpSocketInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CUdpSocketInfo_t qt_meta_stringdata_CUdpSocketInfo = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CUdpSocketInfo"
QT_MOC_LITERAL(1, 15, 14), // "send_edit_recv"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "send_edit_test"
QT_MOC_LITERAL(4, 46, 20), // "send_hardware_status"
QT_MOC_LITERAL(5, 67, 8), // "uint8_t*"
QT_MOC_LITERAL(6, 76, 10), // "GetUDPOpen"
QT_MOC_LITERAL(7, 87, 16), // "SServerIpAddress"
QT_MOC_LITERAL(8, 104, 15), // "SLocalIpAddress"
QT_MOC_LITERAL(9, 120, 5), // "nPort"
QT_MOC_LITERAL(10, 126, 11), // "GetUDPClose"
QT_MOC_LITERAL(11, 138, 12), // "dataReceived"
QT_MOC_LITERAL(12, 151, 17), // "UdpClientSendFunc"
QT_MOC_LITERAL(13, 169, 12), // "SSendBuffer*"
QT_MOC_LITERAL(14, 182, 11), // "pSendbuffer"
QT_MOC_LITERAL(15, 194, 8), // "GetDevId"
QT_MOC_LITERAL(16, 203, 2) // "Id"

    },
    "CUdpSocketInfo\0send_edit_recv\0\0"
    "send_edit_test\0send_hardware_status\0"
    "uint8_t*\0GetUDPOpen\0SServerIpAddress\0"
    "SLocalIpAddress\0nPort\0GetUDPClose\0"
    "dataReceived\0UdpClientSendFunc\0"
    "SSendBuffer*\0pSendbuffer\0GetDevId\0Id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CUdpSocketInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   63,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      15,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Short,   16,

       0        // eod
};

void CUdpSocketInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CUdpSocketInfo *_t = static_cast<CUdpSocketInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_edit_recv((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->send_edit_test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->send_hardware_status((*reinterpret_cast< uint8_t*(*)>(_a[1]))); break;
        case 3: _t->GetUDPOpen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->GetUDPClose(); break;
        case 5: _t->dataReceived(); break;
        case 6: _t->UdpClientSendFunc((*reinterpret_cast< SSendBuffer*(*)>(_a[1]))); break;
        case 7: _t->GetDevId((*reinterpret_cast< short(*)>(_a[1]))); break;
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
            using _t = void (CUdpSocketInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CUdpSocketInfo::send_edit_recv)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CUdpSocketInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CUdpSocketInfo::send_edit_test)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CUdpSocketInfo::*)(uint8_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CUdpSocketInfo::send_hardware_status)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CUdpSocketInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CUdpSocketInfo.data,
      qt_meta_data_CUdpSocketInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CUdpSocketInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CUdpSocketInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CUdpSocketInfo.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CProtocolInfo"))
        return static_cast< CProtocolInfo*>(this);
    return QObject::qt_metacast(_clname);
}

int CUdpSocketInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CUdpSocketInfo::send_edit_recv(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CUdpSocketInfo::send_edit_test(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CUdpSocketInfo::send_hardware_status(uint8_t * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
