/****************************************************************************
** Meta object code from reading C++ file 'OscWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ui/Library/OscWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OscWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OscWidget_t {
    QByteArrayData data[14];
    char stringdata[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OscWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OscWidget_t qt_meta_stringdata_OscWidget = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 11),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 15),
QT_MOC_LITERAL(4, 39, 13),
QT_MOC_LITERAL(5, 53, 25),
QT_MOC_LITERAL(6, 79, 24),
QT_MOC_LITERAL(7, 104, 13),
QT_MOC_LITERAL(8, 118, 8),
QT_MOC_LITERAL(9, 127, 2),
QT_MOC_LITERAL(10, 130, 13),
QT_MOC_LITERAL(11, 144, 8),
QT_MOC_LITERAL(12, 153, 13),
QT_MOC_LITERAL(13, 167, 22)
    },
    "OscWidget\0startOscAcq\0\0propertyClicked\0"
    "updateOscPlot\0on_startOscAcqBtn_clicked\0"
    "on_stopOscAcqBtn_clicked\0legendChecked\0"
    "itemInfo\0on\0setXAxisScale\0interval\0"
    "setYAxisScale\0on_propertyBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscWidget[] = {

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
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    2,   64,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      13,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void,

       0        // eod
};

void OscWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OscWidget *_t = static_cast<OscWidget *>(_o);
        switch (_id) {
        case 0: _t->startOscAcq(); break;
        case 1: _t->propertyClicked(); break;
        case 2: _t->updateOscPlot(); break;
        case 3: _t->on_startOscAcqBtn_clicked(); break;
        case 4: _t->on_stopOscAcqBtn_clicked(); break;
        case 5: _t->legendChecked((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->setXAxisScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setYAxisScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_propertyBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OscWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OscWidget::startOscAcq)) {
                *result = 0;
            }
        }
        {
            typedef void (OscWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OscWidget::propertyClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject OscWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OscWidget.data,
      qt_meta_data_OscWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *OscWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OscWidget.stringdata))
        return static_cast<void*>(const_cast< OscWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OscWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void OscWidget::startOscAcq()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void OscWidget::propertyClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
