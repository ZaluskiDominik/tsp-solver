/****************************************************************************
** Meta object code from reading C++ file 'tunerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tuner/tunerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tunerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TunerDialog_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TunerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TunerDialog_t qt_meta_stringdata_TunerDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TunerDialog"
QT_MOC_LITERAL(1, 12, 9), // "stopTimer"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 19), // "on_startBtn_clicked"
QT_MOC_LITERAL(4, 43, 24), // "on_chooseInstBtn_clicked"
QT_MOC_LITERAL(5, 68, 27), // "on_chooseOutFileBtn_clicked"
QT_MOC_LITERAL(6, 96, 12), // "onTimeUpdate"
QT_MOC_LITERAL(7, 109, 11) // "onStopTimer"

    },
    "TunerDialog\0stopTimer\0\0on_startBtn_clicked\0"
    "on_chooseInstBtn_clicked\0"
    "on_chooseOutFileBtn_clicked\0onTimeUpdate\0"
    "onStopTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TunerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TunerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TunerDialog *_t = static_cast<TunerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopTimer(); break;
        case 1: _t->on_startBtn_clicked(); break;
        case 2: _t->on_chooseInstBtn_clicked(); break;
        case 3: _t->on_chooseOutFileBtn_clicked(); break;
        case 4: _t->onTimeUpdate(); break;
        case 5: _t->onStopTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TunerDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TunerDialog::stopTimer)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TunerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TunerDialog.data,
      qt_meta_data_TunerDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TunerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TunerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TunerDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TunerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void TunerDialog::stopTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
