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
    QByteArrayData data[22];
    char stringdata[459];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StackedWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StackedWidget_t qt_meta_stringdata_StackedWidget = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 17),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 21),
QT_MOC_LITERAL(4, 55, 22),
QT_MOC_LITERAL(5, 78, 21),
QT_MOC_LITERAL(6, 100, 22),
QT_MOC_LITERAL(7, 123, 22),
QT_MOC_LITERAL(8, 146, 23),
QT_MOC_LITERAL(9, 170, 28),
QT_MOC_LITERAL(10, 199, 24),
QT_MOC_LITERAL(11, 224, 9),
QT_MOC_LITERAL(12, 234, 25),
QT_MOC_LITERAL(13, 260, 27),
QT_MOC_LITERAL(14, 288, 25),
QT_MOC_LITERAL(15, 314, 30),
QT_MOC_LITERAL(16, 345, 29),
QT_MOC_LITERAL(17, 375, 15),
QT_MOC_LITERAL(18, 391, 7),
QT_MOC_LITERAL(19, 399, 21),
QT_MOC_LITERAL(20, 421, 21),
QT_MOC_LITERAL(21, 443, 15)
    },
    "StackedWidget\0openExpFileSignal\0\0"
    "on_openUsbBtn_clicked\0on_closeUsbBtn_clicked\0"
    "on_loadCmdBtn_clicked\0on_setLaserBtn_clicked\0"
    "on_setFluidBtn_clicked\0on_setSampleBtn_clicked\0"
    "on_setChannelBiasBtn_clicked\0"
    "on_setTriggerBtn_clicked\0oscHandle\0"
    "on_midRadioButton_clicked\0"
    "on_hightRadioButton_clicked\0"
    "on_lowRadioButton_clicked\0"
    "on_startAcquisitionBtn_clicked\0"
    "on_stopAcquisitionBtn_clicked\0"
    "dataAnalyHandle\0sendCmd\0on_newPlotBtn_clicked\0"
    "on_delPlotBtn_clicked\0openExpFileSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StackedWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  115,    2, 0x0a /* Public */,
       4,    0,  116,    2, 0x0a /* Public */,
       5,    0,  117,    2, 0x0a /* Public */,
       6,    0,  118,    2, 0x0a /* Public */,
       7,    0,  119,    2, 0x0a /* Public */,
       8,    0,  120,    2, 0x0a /* Public */,
       9,    0,  121,    2, 0x0a /* Public */,
      10,    0,  122,    2, 0x0a /* Public */,
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    0,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

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
        case 0: _t->openExpFileSignal(); break;
        case 1: _t->on_openUsbBtn_clicked(); break;
        case 2: _t->on_closeUsbBtn_clicked(); break;
        case 3: _t->on_loadCmdBtn_clicked(); break;
        case 4: _t->on_setLaserBtn_clicked(); break;
        case 5: _t->on_setFluidBtn_clicked(); break;
        case 6: _t->on_setSampleBtn_clicked(); break;
        case 7: _t->on_setChannelBiasBtn_clicked(); break;
        case 8: _t->on_setTriggerBtn_clicked(); break;
        case 9: _t->oscHandle(); break;
        case 10: _t->on_midRadioButton_clicked(); break;
        case 11: _t->on_hightRadioButton_clicked(); break;
        case 12: _t->on_lowRadioButton_clicked(); break;
        case 13: _t->on_startAcquisitionBtn_clicked(); break;
        case 14: _t->on_stopAcquisitionBtn_clicked(); break;
        case 15: _t->dataAnalyHandle(); break;
        case 16: _t->sendCmd(); break;
        case 17: _t->on_newPlotBtn_clicked(); break;
        case 18: _t->on_delPlotBtn_clicked(); break;
        case 19: _t->openExpFileSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StackedWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StackedWidget::openExpFileSignal)) {
                *result = 0;
            }
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void StackedWidget::openExpFileSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
