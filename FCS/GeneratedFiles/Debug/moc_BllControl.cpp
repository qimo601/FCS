/****************************************************************************
** Meta object code from reading C++ file 'BllControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Bll/Control/BllControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BllControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BllControl_t {
    QByteArrayData data[25];
    char stringdata[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BllControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BllControl_t qt_meta_stringdata_BllControl = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 14),
QT_MOC_LITERAL(4, 42, 14),
QT_MOC_LITERAL(5, 57, 8),
QT_MOC_LITERAL(6, 66, 8),
QT_MOC_LITERAL(7, 75, 2),
QT_MOC_LITERAL(8, 78, 8),
QT_MOC_LITERAL(9, 87, 8),
QT_MOC_LITERAL(10, 96, 9),
QT_MOC_LITERAL(11, 106, 9),
QT_MOC_LITERAL(12, 116, 14),
QT_MOC_LITERAL(13, 131, 14),
QT_MOC_LITERAL(14, 146, 10),
QT_MOC_LITERAL(15, 157, 10),
QT_MOC_LITERAL(16, 168, 7),
QT_MOC_LITERAL(17, 176, 6),
QT_MOC_LITERAL(18, 183, 10),
QT_MOC_LITERAL(19, 194, 5),
QT_MOC_LITERAL(20, 200, 9),
QT_MOC_LITERAL(21, 210, 14),
QT_MOC_LITERAL(22, 225, 5),
QT_MOC_LITERAL(23, 231, 7),
QT_MOC_LITERAL(24, 239, 7)
    },
    "BllControl\0initUSBControl\0\0openUSBControl\0"
    "startListening\0setLaser\0VoLaser&\0vo\0"
    "setFluid\0VoFluid&\0setSample\0VoSample&\0"
    "setChannelBias\0VoChannelBias&\0setTrigger\0"
    "VoTrigger&\0sendCmd\0VoCmd&\0getHighInt\0"
    "value\0getLowInt\0getChannelBias\0char&\0"
    "buffer2\0buffer3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BllControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
      10,    1,   83,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,
      16,    1,   92,    2, 0x0a /* Public */,
      18,    1,   95,    2, 0x0a /* Public */,
      20,    1,   98,    2, 0x0a /* Public */,
      21,    3,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 6,    7,
    QMetaType::Bool, 0x80000000 | 9,    7,
    QMetaType::Bool, 0x80000000 | 11,    7,
    QMetaType::Bool, 0x80000000 | 13,    7,
    QMetaType::Bool, 0x80000000 | 15,    7,
    QMetaType::Bool, 0x80000000 | 17,    7,
    QMetaType::UChar, QMetaType::Int,   19,
    QMetaType::UChar, QMetaType::Int,   19,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 22, 0x80000000 | 22,    7,   23,   24,

       0        // eod
};

void BllControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BllControl *_t = static_cast<BllControl *>(_o);
        switch (_id) {
        case 0: _t->initUSBControl(); break;
        case 1: _t->openUSBControl(); break;
        case 2: _t->startListening(); break;
        case 3: { bool _r = _t->setLaser((*reinterpret_cast< VoLaser(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->setFluid((*reinterpret_cast< VoFluid(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->setSample((*reinterpret_cast< VoSample(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->setChannelBias((*reinterpret_cast< VoChannelBias(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->setTrigger((*reinterpret_cast< VoTrigger(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->sendCmd((*reinterpret_cast< VoCmd(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { uchar _r = _t->getHighInt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 10: { uchar _r = _t->getLowInt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 11: _t->getChannelBias((*reinterpret_cast< VoChannelBias(*)>(_a[1])),(*reinterpret_cast< char(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject BllControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BllControl.data,
      qt_meta_data_BllControl,  qt_static_metacall, 0, 0}
};


const QMetaObject *BllControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BllControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BllControl.stringdata))
        return static_cast<void*>(const_cast< BllControl*>(this));
    return QObject::qt_metacast(_clname);
}

int BllControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
