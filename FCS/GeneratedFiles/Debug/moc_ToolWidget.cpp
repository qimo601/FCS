/****************************************************************************
** Meta object code from reading C++ file 'ToolWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ui/Library/ToolWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ToolWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ToolWidget_t {
    QByteArrayData data[8];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolWidget_t qt_meta_stringdata_ToolWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 15),
QT_MOC_LITERAL(4, 42, 16),
QT_MOC_LITERAL(5, 59, 17),
QT_MOC_LITERAL(6, 77, 19),
QT_MOC_LITERAL(7, 97, 20)
    },
    "ToolWidget\0acqBtnClicked\0\0analyBtnClicked\0"
    "oscAcqBtnClicked\0on_acqBtn_clicked\0"
    "on_analyBtn_clicked\0on_oscAcqBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ToolWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolWidget *_t = static_cast<ToolWidget *>(_o);
        switch (_id) {
        case 0: _t->acqBtnClicked(); break;
        case 1: _t->analyBtnClicked(); break;
        case 2: _t->oscAcqBtnClicked(); break;
        case 3: _t->on_acqBtn_clicked(); break;
        case 4: _t->on_analyBtn_clicked(); break;
        case 5: _t->on_oscAcqBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolWidget::acqBtnClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (ToolWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolWidget::analyBtnClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (ToolWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolWidget::oscAcqBtnClicked)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ToolWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToolWidget.data,
      qt_meta_data_ToolWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ToolWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolWidget.stringdata))
        return static_cast<void*>(const_cast< ToolWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ToolWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ToolWidget::acqBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ToolWidget::analyBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ToolWidget::oscAcqBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
