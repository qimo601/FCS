/****************************************************************************
** Meta object code from reading C++ file 'StackedWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ui/Library/StackedWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StackedWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StackedWidget_t {
    QByteArrayData data[18];
    char stringdata[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StackedWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StackedWidget_t qt_meta_stringdata_StackedWidget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 21),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 22),
QT_MOC_LITERAL(4, 60, 21),
QT_MOC_LITERAL(5, 82, 22),
QT_MOC_LITERAL(6, 105, 22),
QT_MOC_LITERAL(7, 128, 23),
QT_MOC_LITERAL(8, 152, 28),
QT_MOC_LITERAL(9, 181, 24),
QT_MOC_LITERAL(10, 206, 9),
QT_MOC_LITERAL(11, 216, 25),
QT_MOC_LITERAL(12, 242, 27),
QT_MOC_LITERAL(13, 270, 25),
QT_MOC_LITERAL(14, 296, 30),
QT_MOC_LITERAL(15, 327, 29),
QT_MOC_LITERAL(16, 357, 15),
QT_MOC_LITERAL(17, 373, 7)
    },
    "StackedWidget\0on_openUsbBtn_clicked\0"
    "\0on_closeUsbBtn_clicked\0on_loadCmdBtn_clicked\0"
    "on_setLaserBtn_clicked\0on_setFluidBtn_clicked\0"
    "on_setSampleBtn_clicked\0"
    "on_setChannelBiasBtn_clicked\0"
    "on_setTriggerBtn_clicked\0oscHandle\0"
    "on_midRadioButton_clicked\0"
    "on_hightRadioButton_clicked\0"
    "on_lowRadioButton_clicked\0"
    "on_startAcquisitionBtn_clicked\0"
    "on_stopAcquisitionBtn_clicked\0"
    "dataAnalyHandle\0sendCmd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StackedWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StackedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StackedWidget *_t = static_cast<StackedWidget *>(_o);
        switch (_id) {
        case 0: _t->on_openUsbBtn_clicked(); break;
        case 1: _t->on_closeUsbBtn_clicked(); break;
        case 2: _t->on_loadCmdBtn_clicked(); break;
        case 3: _t->on_setLaserBtn_clicked(); break;
        case 4: _t->on_setFluidBtn_clicked(); break;
        case 5: _t->on_setSampleBtn_clicked(); break;
        case 6: _t->on_setChannelBiasBtn_clicked(); break;
        case 7: _t->on_setTriggerBtn_clicked(); break;
        case 8: _t->oscHandle(); break;
        case 9: _t->on_midRadioButton_clicked(); break;
        case 10: _t->on_hightRadioButton_clicked(); break;
        case 11: _t->on_lowRadioButton_clicked(); break;
        case 12: _t->on_startAcquisitionBtn_clicked(); break;
        case 13: _t->on_stopAcquisitionBtn_clicked(); break;
        case 14: _t->dataAnalyHandle(); break;
        case 15: _t->sendCmd(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StackedWidget::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_StackedWidget.data,
      qt_meta_data_StackedWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *StackedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StackedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StackedWidget.stringdata))
        return static_cast<void*>(const_cast< StackedWidget*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int StackedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
