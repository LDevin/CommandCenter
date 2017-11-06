/****************************************************************************
** Meta object code from reading C++ file 'httpconfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CommandCenter/Link/httpconfiguration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpconfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpConfiguration_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpConfiguration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpConfiguration_t qt_meta_stringdata_HttpConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HttpConfiguration"
QT_MOC_LITERAL(1, 18, 11), // "RequestType"
QT_MOC_LITERAL(2, 30, 3), // "GET"
QT_MOC_LITERAL(3, 34, 4), // "POST"
QT_MOC_LITERAL(4, 39, 18), // "RequestContentType"
QT_MOC_LITERAL(5, 58, 8) // "JsonType"

    },
    "HttpConfiguration\0RequestType\0GET\0"
    "POST\0RequestContentType\0JsonType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpConfiguration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    2,   22,
       4, 0x0,    1,   26,

 // enum data: key, value
       2, uint(HttpConfiguration::GET),
       3, uint(HttpConfiguration::POST),
       5, uint(HttpConfiguration::JsonType),

       0        // eod
};

void HttpConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject HttpConfiguration::staticMetaObject = {
    { &LinkConfiguration::staticMetaObject, qt_meta_stringdata_HttpConfiguration.data,
      qt_meta_data_HttpConfiguration,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HttpConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpConfiguration.stringdata0))
        return static_cast<void*>(const_cast< HttpConfiguration*>(this));
    return LinkConfiguration::qt_metacast(_clname);
}

int HttpConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LinkConfiguration::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
