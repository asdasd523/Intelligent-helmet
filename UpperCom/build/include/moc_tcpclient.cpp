/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CTcpSocketInfo_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTcpSocketInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTcpSocketInfo_t qt_meta_stringdata_CTcpSocketInfo = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CTcpSocketInfo"
QT_MOC_LITERAL(1, 15, 14), // "send_edit_recv"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "send_edit_test"
QT_MOC_LITERAL(4, 46, 13), // "slotConnected"
QT_MOC_LITERAL(5, 60, 16), // "slotDisconnected"
QT_MOC_LITERAL(6, 77, 12), // "dataReceived"
QT_MOC_LITERAL(7, 90, 8), // "GetDevId"
QT_MOC_LITERAL(8, 99, 2), // "Id"
QT_MOC_LITERAL(9, 102, 10), // "GetTCPOpen"
QT_MOC_LITERAL(10, 113, 7), // "SIpAddr"
QT_MOC_LITERAL(11, 121, 4), // "Port"
QT_MOC_LITERAL(12, 126, 11), // "GetTCPClose"
QT_MOC_LITERAL(13, 138, 17), // "TcpClientSendFunc"
QT_MOC_LITERAL(14, 156, 12), // "SSendBuffer*"
QT_MOC_LITERAL(15, 169, 11) // "pSendbuffer"

    },
    "CTcpSocketInfo\0send_edit_recv\0\0"
    "send_edit_test\0slotConnected\0"
    "slotDisconnected\0dataReceived\0GetDevId\0"
    "Id\0GetTCPOpen\0SIpAddr\0Port\0GetTCPClose\0"
    "TcpClientSendFunc\0SSendBuffer*\0"
    "pSendbuffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTcpSocketInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   65,    2, 0x0a /* Public */,
       5,    0,   66,    2, 0x0a /* Public */,
       6,    0,   67,    2, 0x0a /* Public */,
       7,    1,   68,    2, 0x0a /* Public */,
       9,    2,   71,    2, 0x0a /* Public */,
      12,    0,   76,    2, 0x0a /* Public */,
      13,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void CTcpSocketInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTcpSocketInfo *_t = static_cast<CTcpSocketInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_edit_recv((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->send_edit_test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotConnected(); break;
        case 3: _t->slotDisconnected(); break;
        case 4: _t->dataReceived(); break;
        case 5: _t->GetDevId((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 6: _t->GetTCPOpen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->GetTCPClose(); break;
        case 8: _t->TcpClientSendFunc((*reinterpret_cast< SSendBuffer*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
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
            using _t = void (CTcpSocketInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTcpSocketInfo::send_edit_recv)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CTcpSocketInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CTcpSocketInfo::send_edit_test)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CTcpSocketInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CTcpSocketInfo.data,
      qt_meta_data_CTcpSocketInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CTcpSocketInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTcpSocketInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTcpSocketInfo.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CProtocolInfo"))
        return static_cast< CProtocolInfo*>(this);
    return QObject::qt_metacast(_clname);
}

int CTcpSocketInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CTcpSocketInfo::send_edit_recv(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CTcpSocketInfo::send_edit_test(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
