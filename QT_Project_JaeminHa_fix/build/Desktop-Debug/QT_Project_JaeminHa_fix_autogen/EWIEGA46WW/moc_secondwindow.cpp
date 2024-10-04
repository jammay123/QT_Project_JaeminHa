/****************************************************************************
** Meta object code from reading C++ file 'secondwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../QT_Project_JaeminHa/secondwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secondwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_secondwindow_t {
    QByteArrayData data[11];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_secondwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_secondwindow_t qt_meta_stringdata_secondwindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "secondwindow"
QT_MOC_LITERAL(1, 13, 20), // "on_shoot_btn_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "opponentTurn"
QT_MOC_LITERAL(4, 48, 19), // "on_turn_btn_clicked"
QT_MOC_LITERAL(5, 68, 21), // "on_cookie_btn_clicked"
QT_MOC_LITERAL(6, 90, 21), // "on_reload_btn_clicked"
QT_MOC_LITERAL(7, 112, 23), // "on_critical_btn_clicked"
QT_MOC_LITERAL(8, 136, 22), // "on_insight_btn_clicked"
QT_MOC_LITERAL(9, 159, 20), // "on_flash_btn_clicked"
QT_MOC_LITERAL(10, 180, 24) // "on_inventory_btn_clicked"

    },
    "secondwindow\0on_shoot_btn_clicked\0\0"
    "opponentTurn\0on_turn_btn_clicked\0"
    "on_cookie_btn_clicked\0on_reload_btn_clicked\0"
    "on_critical_btn_clicked\0on_insight_btn_clicked\0"
    "on_flash_btn_clicked\0on_inventory_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_secondwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void secondwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<secondwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_shoot_btn_clicked(); break;
        case 1: _t->opponentTurn(); break;
        case 2: _t->on_turn_btn_clicked(); break;
        case 3: _t->on_cookie_btn_clicked(); break;
        case 4: _t->on_reload_btn_clicked(); break;
        case 5: _t->on_critical_btn_clicked(); break;
        case 6: _t->on_insight_btn_clicked(); break;
        case 7: _t->on_flash_btn_clicked(); break;
        case 8: _t->on_inventory_btn_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject secondwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_secondwindow.data,
    qt_meta_data_secondwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *secondwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *secondwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_secondwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int secondwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
