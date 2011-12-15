/****************************************************************************
** Meta object code from reading C++ file 'leftpanel.h'
**
** Created: Thu 15. Dec 01:22:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../leftpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leftpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LeftPanel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   10,   10,   10, 0x0a,
      66,   55,   10,   10, 0x0a,
     104,   96,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LeftPanel[] = {
    "LeftPanel\0\0EtapButtonPressed(int)\0"
    "EtapButtonCalls(int)\0_log,_pass\0"
    "RegDataCatch(QString,QString)\0_errMsg\0"
    "catchError(QString)\0"
};

const QMetaObject LeftPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LeftPanel,
      qt_meta_data_LeftPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LeftPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LeftPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LeftPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LeftPanel))
        return static_cast<void*>(const_cast< LeftPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int LeftPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: EtapButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: EtapButtonCalls((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: RegDataCatch((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: catchError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LeftPanel::EtapButtonPressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
