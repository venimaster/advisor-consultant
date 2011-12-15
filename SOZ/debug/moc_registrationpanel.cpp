/****************************************************************************
** Meta object code from reading C++ file 'registrationpanel.h'
**
** Created: Thu 15. Dec 01:22:27 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../leftPanels/registrationpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registrationpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegistrationPanel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      44,   19,   18,   18, 0x05,
      88,   18,   18,   18, 0x05,
     109,  101,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   18,   18,   18, 0x0a,
     149,   18,   18,   18, 0x0a,
     166,   18,   18,   18, 0x0a,
     190,   18,   18,   18, 0x0a,
     206,   18,   18,   18, 0x0a,
     222,   18,   18,   18, 0x0a,
     238,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RegistrationPanel[] = {
    "RegistrationPanel\0\0_log,_pass,_FIO,_Sex,age\0"
    "sendData(QString,QString,QString,QChar,int)\0"
    "checkInput()\0_ErrMsg\0sendError(QString)\0"
    "getNickName(QString)\0getPass(QString)\0"
    "getConfirmPass(QString)\0getFIO(QString)\0"
    "getSex(QString)\0getAge(QString)\0"
    "unlockOK()\0"
};

const QMetaObject RegistrationPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RegistrationPanel,
      qt_meta_data_RegistrationPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegistrationPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegistrationPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegistrationPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegistrationPanel))
        return static_cast<void*>(const_cast< RegistrationPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int RegistrationPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QChar(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5]))); break;
        case 1: checkInput(); break;
        case 2: sendError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: getNickName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: getPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: getConfirmPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: getFIO((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: getSex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: getAge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: unlockOK(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void RegistrationPanel::sendData(const QString & _t1, const QString & _t2, const QString & _t3, const QChar & _t4, const int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RegistrationPanel::checkInput()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RegistrationPanel::sendError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
