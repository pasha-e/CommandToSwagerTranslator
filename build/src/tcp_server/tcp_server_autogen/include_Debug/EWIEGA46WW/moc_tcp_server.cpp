/****************************************************************************
** Meta object code from reading C++ file 'tcp_server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/tcp_server/tcp_server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_skif__adapters__azr__tcp__TcpClient_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_skif__adapters__azr__tcp__TcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_skif__adapters__azr__tcp__TcpClient_t qt_meta_stringdata_skif__adapters__azr__tcp__TcpClient = {
    {
QT_MOC_LITERAL(0, 0, 35), // "skif::adapters::azr::tcp::Tcp..."
QT_MOC_LITERAL(1, 36, 9), // "dataReady"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 4), // "data"
QT_MOC_LITERAL(4, 52, 15), // "client_handle_t"
QT_MOC_LITERAL(5, 68, 1), // "h"
QT_MOC_LITERAL(6, 70, 12), // "disconnected"
QT_MOC_LITERAL(7, 83, 5), // "error"
QT_MOC_LITERAL(8, 89, 4) // "read"

    },
    "skif::adapters::azr::tcp::TcpClient\0"
    "dataReady\0\0data\0client_handle_t\0h\0"
    "disconnected\0error\0read"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_skif__adapters__azr__tcp__TcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,
       7,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void skif::adapters::azr::tcp::TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReady((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< client_handle_t(*)>(_a[2]))); break;
        case 1: _t->disconnected((*reinterpret_cast< client_handle_t(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->read(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClient::*)(QByteArray , client_handle_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::dataReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(client_handle_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::error)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject skif::adapters::azr::tcp::TcpClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_skif__adapters__azr__tcp__TcpClient.data,
    qt_meta_data_skif__adapters__azr__tcp__TcpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *skif::adapters::azr::tcp::TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *skif::adapters::azr::tcp::TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_skif__adapters__azr__tcp__TcpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int skif::adapters::azr::tcp::TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void skif::adapters::azr::tcp::TcpClient::dataReady(QByteArray _t1, client_handle_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void skif::adapters::azr::tcp::TcpClient::disconnected(client_handle_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void skif::adapters::azr::tcp::TcpClient::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_skif__adapters__azr__tcp__TcpServer_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_skif__adapters__azr__tcp__TcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_skif__adapters__azr__tcp__TcpServer_t qt_meta_stringdata_skif__adapters__azr__tcp__TcpServer = {
    {
QT_MOC_LITERAL(0, 0, 35), // "skif::adapters::azr::tcp::Tcp..."
QT_MOC_LITERAL(1, 36, 15), // "clientConnected"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 15), // "client_handle_t"
QT_MOC_LITERAL(4, 69, 1), // "h"
QT_MOC_LITERAL(5, 71, 18), // "clientDisconnected"
QT_MOC_LITERAL(6, 90, 5), // "error"
QT_MOC_LITERAL(7, 96, 11), // "dataRecived"
QT_MOC_LITERAL(8, 108, 4), // "data"
QT_MOC_LITERAL(9, 113, 8), // "sendData"
QT_MOC_LITERAL(10, 122, 13) // "handle_accept"

    },
    "skif::adapters::azr::tcp::TcpServer\0"
    "clientConnected\0\0client_handle_t\0h\0"
    "clientDisconnected\0error\0dataRecived\0"
    "data\0sendData\0handle_accept"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_skif__adapters__azr__tcp__TcpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       7,    2,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   58,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3,    8,    4,

 // slots: parameters
    QMetaType::LongLong, QMetaType::QByteArray, 0x80000000 | 3,    8,    4,
    QMetaType::Void,

       0        // eod
};

void skif::adapters::azr::tcp::TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientConnected((*reinterpret_cast< client_handle_t(*)>(_a[1]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< client_handle_t(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->dataRecived((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< client_handle_t(*)>(_a[2]))); break;
        case 4: { qint64 _r = _t->sendData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< client_handle_t(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->handle_accept(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServer::*)(client_handle_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::clientConnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(client_handle_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::clientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QByteArray , client_handle_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::dataRecived)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject skif::adapters::azr::tcp::TcpServer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_skif__adapters__azr__tcp__TcpServer.data,
    qt_meta_data_skif__adapters__azr__tcp__TcpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *skif::adapters::azr::tcp::TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *skif::adapters::azr::tcp::TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_skif__adapters__azr__tcp__TcpServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int skif::adapters::azr::tcp::TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void skif::adapters::azr::tcp::TcpServer::clientConnected(client_handle_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void skif::adapters::azr::tcp::TcpServer::clientDisconnected(client_handle_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void skif::adapters::azr::tcp::TcpServer::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void skif::adapters::azr::tcp::TcpServer::dataRecived(QByteArray _t1, client_handle_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
