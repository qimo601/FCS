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
    QByteArrayData data[21];
    char stringdata[284];
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
QT_MOC_LITERAL(4, 39, 12),
QT_MOC_LITERAL(5, 52, 13),
QT_MOC_LITERAL(6, 66, 25),
QT_MOC_LITERAL(7, 92, 24),
QT_MOC_LITERAL(8, 117, 23),
QT_MOC_LITERAL(9, 141, 13),
QT_MOC_LITERAL(10, 155, 8),
QT_MOC_LITERAL(11, 164, 2),
QT_MOC_LITERAL(12, 167, 13),
QT_MOC_LITERAL(13, 181, 8),
QT_MOC_LITERAL(14, 190, 13),
QT_MOC_LITERAL(15, 204, 8),
QT_MOC_LITERAL(16, 213, 6),
QT_MOC_LITERAL(17, 220, 8),
QT_MOC_LITERAL(18, 229, 6),
QT_MOC_LITERAL(19, 236, 22),
QT_MOC_LITERAL(20, 259, 24)
    },
    "OscWidget\0startOscAcq\0\0propertyClicked\0"
    "updateParams\0updateOscPlot\0"
    "on_startOscAcqBtn_clicked\0"
    "on_stopOscAcqBtn_clicked\0"
    "on_saveCheckBox_clicked\0legendChecked\0"
    "itemInfo\0on\0setXAxisScale\0interval\0"
    "setYAxisScale\0setXMark\0mark_x\0setYMark\0"
    "mark_y\0on_propertyBtn_clicked\0"
    "setVisiblePropertyWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    2,   91,    2, 0x0a /* Public */,
      12,    1,   96,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void,
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
        case 2: _t->updateParams(); break;
        case 3: _t->updateOscPlot(); break;
        case 4: _t->on_startOscAcqBtn_clicked(); break;
        case 5: _t->on_stopOscAcqBtn_clicked(); break;
        case 6: _t->on_saveCheckBox_clicked(); break;
        case 7: _t->legendChecked((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->setXAxisScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setYAxisScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setXMark((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setYMark((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_propertyBtn_clicked(); break;
        case 13: _t->setVisiblePropertyWidget(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
