/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onAddPatient",
    "",
    "onEditPatient",
    "onDeletePatient",
    "onAddDoctor",
    "onEditDoctor",
    "onDeleteDoctor",
    "onAddDepartment",
    "onEditDepartment",
    "onDeleteDepartment",
    "onAddMedicalRecord",
    "onEditMedicalRecord",
    "onDeleteMedicalRecord",
    "onAddPrescription",
    "onEditPrescription",
    "onDeletePrescription",
    "onAddMedicine",
    "onEditMedicine",
    "onDeleteMedicine",
    "onAddInventory",
    "onEditInventory",
    "onDeleteInventory",
    "onAddAppointment",
    "onEditAppointment",
    "onDeleteAppointment",
    "onAddSchedule",
    "onEditSchedule",
    "onDeleteSchedule",
    "onGenerateReport",
    "onViewStatistics",
    "onSyncData",
    "onBackupData"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[66];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[12];
    char stringdata6[13];
    char stringdata7[15];
    char stringdata8[16];
    char stringdata9[17];
    char stringdata10[19];
    char stringdata11[19];
    char stringdata12[20];
    char stringdata13[22];
    char stringdata14[18];
    char stringdata15[19];
    char stringdata16[21];
    char stringdata17[14];
    char stringdata18[15];
    char stringdata19[17];
    char stringdata20[15];
    char stringdata21[16];
    char stringdata22[18];
    char stringdata23[17];
    char stringdata24[18];
    char stringdata25[20];
    char stringdata26[14];
    char stringdata27[15];
    char stringdata28[17];
    char stringdata29[17];
    char stringdata30[17];
    char stringdata31[11];
    char stringdata32[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "onAddPatient"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 13),  // "onEditPatient"
        QT_MOC_LITERAL(39, 15),  // "onDeletePatient"
        QT_MOC_LITERAL(55, 11),  // "onAddDoctor"
        QT_MOC_LITERAL(67, 12),  // "onEditDoctor"
        QT_MOC_LITERAL(80, 14),  // "onDeleteDoctor"
        QT_MOC_LITERAL(95, 15),  // "onAddDepartment"
        QT_MOC_LITERAL(111, 16),  // "onEditDepartment"
        QT_MOC_LITERAL(128, 18),  // "onDeleteDepartment"
        QT_MOC_LITERAL(147, 18),  // "onAddMedicalRecord"
        QT_MOC_LITERAL(166, 19),  // "onEditMedicalRecord"
        QT_MOC_LITERAL(186, 21),  // "onDeleteMedicalRecord"
        QT_MOC_LITERAL(208, 17),  // "onAddPrescription"
        QT_MOC_LITERAL(226, 18),  // "onEditPrescription"
        QT_MOC_LITERAL(245, 20),  // "onDeletePrescription"
        QT_MOC_LITERAL(266, 13),  // "onAddMedicine"
        QT_MOC_LITERAL(280, 14),  // "onEditMedicine"
        QT_MOC_LITERAL(295, 16),  // "onDeleteMedicine"
        QT_MOC_LITERAL(312, 14),  // "onAddInventory"
        QT_MOC_LITERAL(327, 15),  // "onEditInventory"
        QT_MOC_LITERAL(343, 17),  // "onDeleteInventory"
        QT_MOC_LITERAL(361, 16),  // "onAddAppointment"
        QT_MOC_LITERAL(378, 17),  // "onEditAppointment"
        QT_MOC_LITERAL(396, 19),  // "onDeleteAppointment"
        QT_MOC_LITERAL(416, 13),  // "onAddSchedule"
        QT_MOC_LITERAL(430, 14),  // "onEditSchedule"
        QT_MOC_LITERAL(445, 16),  // "onDeleteSchedule"
        QT_MOC_LITERAL(462, 16),  // "onGenerateReport"
        QT_MOC_LITERAL(479, 16),  // "onViewStatistics"
        QT_MOC_LITERAL(496, 10),  // "onSyncData"
        QT_MOC_LITERAL(507, 12)   // "onBackupData"
    },
    "MainWindow",
    "onAddPatient",
    "",
    "onEditPatient",
    "onDeletePatient",
    "onAddDoctor",
    "onEditDoctor",
    "onDeleteDoctor",
    "onAddDepartment",
    "onEditDepartment",
    "onDeleteDepartment",
    "onAddMedicalRecord",
    "onEditMedicalRecord",
    "onDeleteMedicalRecord",
    "onAddPrescription",
    "onEditPrescription",
    "onDeletePrescription",
    "onAddMedicine",
    "onEditMedicine",
    "onDeleteMedicine",
    "onAddInventory",
    "onEditInventory",
    "onDeleteInventory",
    "onAddAppointment",
    "onEditAppointment",
    "onDeleteAppointment",
    "onAddSchedule",
    "onEditSchedule",
    "onDeleteSchedule",
    "onGenerateReport",
    "onViewStatistics",
    "onSyncData",
    "onBackupData"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  200,    2, 0x08,    1 /* Private */,
       3,    0,  201,    2, 0x08,    2 /* Private */,
       4,    0,  202,    2, 0x08,    3 /* Private */,
       5,    0,  203,    2, 0x08,    4 /* Private */,
       6,    0,  204,    2, 0x08,    5 /* Private */,
       7,    0,  205,    2, 0x08,    6 /* Private */,
       8,    0,  206,    2, 0x08,    7 /* Private */,
       9,    0,  207,    2, 0x08,    8 /* Private */,
      10,    0,  208,    2, 0x08,    9 /* Private */,
      11,    0,  209,    2, 0x08,   10 /* Private */,
      12,    0,  210,    2, 0x08,   11 /* Private */,
      13,    0,  211,    2, 0x08,   12 /* Private */,
      14,    0,  212,    2, 0x08,   13 /* Private */,
      15,    0,  213,    2, 0x08,   14 /* Private */,
      16,    0,  214,    2, 0x08,   15 /* Private */,
      17,    0,  215,    2, 0x08,   16 /* Private */,
      18,    0,  216,    2, 0x08,   17 /* Private */,
      19,    0,  217,    2, 0x08,   18 /* Private */,
      20,    0,  218,    2, 0x08,   19 /* Private */,
      21,    0,  219,    2, 0x08,   20 /* Private */,
      22,    0,  220,    2, 0x08,   21 /* Private */,
      23,    0,  221,    2, 0x08,   22 /* Private */,
      24,    0,  222,    2, 0x08,   23 /* Private */,
      25,    0,  223,    2, 0x08,   24 /* Private */,
      26,    0,  224,    2, 0x08,   25 /* Private */,
      27,    0,  225,    2, 0x08,   26 /* Private */,
      28,    0,  226,    2, 0x08,   27 /* Private */,
      29,    0,  227,    2, 0x08,   28 /* Private */,
      30,    0,  228,    2, 0x08,   29 /* Private */,
      31,    0,  229,    2, 0x08,   30 /* Private */,
      32,    0,  230,    2, 0x08,   31 /* Private */,

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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onAddPatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditPatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeletePatient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddDoctor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditDoctor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteDoctor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddDepartment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditDepartment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteDepartment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddMedicalRecord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditMedicalRecord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteMedicalRecord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddPrescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditPrescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeletePrescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddMedicine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditMedicine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteMedicine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddInventory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditInventory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteInventory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddAppointment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditAppointment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteAppointment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddSchedule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditSchedule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteSchedule'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGenerateReport'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onViewStatistics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSyncData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onBackupData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onAddPatient(); break;
        case 1: _t->onEditPatient(); break;
        case 2: _t->onDeletePatient(); break;
        case 3: _t->onAddDoctor(); break;
        case 4: _t->onEditDoctor(); break;
        case 5: _t->onDeleteDoctor(); break;
        case 6: _t->onAddDepartment(); break;
        case 7: _t->onEditDepartment(); break;
        case 8: _t->onDeleteDepartment(); break;
        case 9: _t->onAddMedicalRecord(); break;
        case 10: _t->onEditMedicalRecord(); break;
        case 11: _t->onDeleteMedicalRecord(); break;
        case 12: _t->onAddPrescription(); break;
        case 13: _t->onEditPrescription(); break;
        case 14: _t->onDeletePrescription(); break;
        case 15: _t->onAddMedicine(); break;
        case 16: _t->onEditMedicine(); break;
        case 17: _t->onDeleteMedicine(); break;
        case 18: _t->onAddInventory(); break;
        case 19: _t->onEditInventory(); break;
        case 20: _t->onDeleteInventory(); break;
        case 21: _t->onAddAppointment(); break;
        case 22: _t->onEditAppointment(); break;
        case 23: _t->onDeleteAppointment(); break;
        case 24: _t->onAddSchedule(); break;
        case 25: _t->onEditSchedule(); break;
        case 26: _t->onDeleteSchedule(); break;
        case 27: _t->onGenerateReport(); break;
        case 28: _t->onViewStatistics(); break;
        case 29: _t->onSyncData(); break;
        case 30: _t->onBackupData(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP
