/****************************************************************************
** Meta object code from reading C++ file 'FileReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../FileReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Listener_t {
    QByteArrayData data[5];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Listener_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Listener_t qt_meta_stringdata_Listener = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Listener"
QT_MOC_LITERAL(1, 9, 13), // "IncommingFile"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "SOCKET"
QT_MOC_LITERAL(4, 31, 6) // "socket"

    },
    "Listener\0IncommingFile\0\0SOCKET\0socket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Listener[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Listener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Listener *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->IncommingFile((*reinterpret_cast< SOCKET(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SOCKET >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Listener::*)(SOCKET );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Listener::IncommingFile)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Listener::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Listener.data,
    qt_meta_data_Listener,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Listener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Listener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Listener.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Listener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Listener::IncommingFile(SOCKET _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FilesReceiver_t {
    QByteArrayData data[18];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilesReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilesReceiver_t qt_meta_stringdata_FilesReceiver = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FilesReceiver"
QT_MOC_LITERAL(1, 14, 19), // "BeginRecvSingleFile"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "filePath"
QT_MOC_LITERAL(4, 44, 15), // "ReceiveFinished"
QT_MOC_LITERAL(5, 60, 2), // "id"
QT_MOC_LITERAL(6, 63, 3), // "msg"
QT_MOC_LITERAL(7, 67, 14), // "BeginListening"
QT_MOC_LITERAL(8, 82, 13), // "StopListening"
QT_MOC_LITERAL(9, 96, 16), // "process_Finished"
QT_MOC_LITERAL(10, 113, 7), // "success"
QT_MOC_LITERAL(11, 121, 13), // "process_Begin"
QT_MOC_LITERAL(12, 135, 17), // "ReceiveSingleFile"
QT_MOC_LITERAL(13, 153, 6), // "SOCKET"
QT_MOC_LITERAL(14, 160, 6), // "socket"
QT_MOC_LITERAL(15, 167, 13), // "StopReceiving"
QT_MOC_LITERAL(16, 181, 16), // "updateRecvFloder"
QT_MOC_LITERAL(17, 198, 6) // "floder"

    },
    "FilesReceiver\0BeginRecvSingleFile\0\0"
    "filePath\0ReceiveFinished\0id\0msg\0"
    "BeginListening\0StopListening\0"
    "process_Finished\0success\0process_Begin\0"
    "ReceiveSingleFile\0SOCKET\0socket\0"
    "StopReceiving\0updateRecvFloder\0floder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilesReceiver[] = {

 // content:
       8,       // revision
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
       4,    2,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   67,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    3,   69,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,
      15,    0,   82,    2, 0x0a /* Public */,
      16,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UShort, QMetaType::QString,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, QMetaType::Bool, QMetaType::QString,    5,   10,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void FilesReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilesReceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->BeginRecvSingleFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ReceiveFinished((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->BeginListening(); break;
        case 3: _t->StopListening(); break;
        case 4: _t->process_Finished((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->process_Begin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->ReceiveSingleFile((*reinterpret_cast< SOCKET(*)>(_a[1]))); break;
        case 7: _t->StopReceiving(); break;
        case 8: _t->updateRecvFloder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SOCKET >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilesReceiver::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilesReceiver::BeginRecvSingleFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FilesReceiver::*)(unsigned short , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilesReceiver::ReceiveFinished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FilesReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FilesReceiver.data,
    qt_meta_data_FilesReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilesReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilesReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilesReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FilesReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FilesReceiver::BeginRecvSingleFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilesReceiver::ReceiveFinished(unsigned short _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_SingleFileReceiver_t {
    QByteArrayData data[8];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SingleFileReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SingleFileReceiver_t qt_meta_stringdata_SingleFileReceiver = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SingleFileReceiver"
QT_MOC_LITERAL(1, 19, 8), // "finished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "id"
QT_MOC_LITERAL(4, 32, 7), // "success"
QT_MOC_LITERAL(5, 40, 3), // "msg"
QT_MOC_LITERAL(6, 44, 5), // "begin"
QT_MOC_LITERAL(7, 50, 8) // "filePath"

    },
    "SingleFileReceiver\0finished\0\0id\0success\0"
    "msg\0begin\0filePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SingleFileReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,
       6,    1,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::Bool, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void SingleFileReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SingleFileReceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->begin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SingleFileReceiver::*)(unsigned short , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SingleFileReceiver::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SingleFileReceiver::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SingleFileReceiver::begin)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SingleFileReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SingleFileReceiver.data,
    qt_meta_data_SingleFileReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SingleFileReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SingleFileReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SingleFileReceiver.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int SingleFileReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SingleFileReceiver::finished(unsigned short _t1, bool _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SingleFileReceiver::begin(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
