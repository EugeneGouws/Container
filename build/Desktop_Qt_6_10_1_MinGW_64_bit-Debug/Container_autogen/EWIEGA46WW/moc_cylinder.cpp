/****************************************************************************
** Meta object code from reading C++ file 'cylinder.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cylinder.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cylinder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8CylinderE_t {};
} // unnamed namespace

template <> constexpr inline auto Cylinder::qt_create_metaobjectdata<qt_meta_tag_ZN8CylinderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Cylinder",
        "code",
        "weight",
        "diameter",
        "height"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'code'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'weight'
        QtMocHelpers::PropertyData<int>(2, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'diameter'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'height'
        QtMocHelpers::PropertyData<int>(4, QMetaType::Int, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Cylinder, qt_meta_tag_ZN8CylinderE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Cylinder::staticMetaObject = { {
    QMetaObject::SuperData::link<Container::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CylinderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CylinderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8CylinderE_t>.metaTypes,
    nullptr
} };

void Cylinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Cylinder *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->getCode(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->getWeight(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->getDiameter(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->getHeight(); break;
        default: break;
        }
    }
}

const QMetaObject *Cylinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cylinder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CylinderE_t>.strings))
        return static_cast<void*>(this);
    return Container::qt_metacast(_clname);
}

int Cylinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Container::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
