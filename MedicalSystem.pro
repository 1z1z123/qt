QT += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = MedicalSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    databasemanager.cpp \
    models/patientmodel.cpp \
    models/doctormodel.cpp \
    models/departmentmodel.cpp \
    models/medicalrecordmodel.cpp \
    models/prescriptionmodel.cpp \
    models/medicinemodel.cpp \
    models/inventorymodel.cpp \
    models/appointmentmodel.cpp \
    models/schedulemodel.cpp \
    dialogs/patientdialog.cpp \
    dialogs/doctordialog.cpp \
    dialogs/departmentdialog.cpp \
    dialogs/medicalrecorddialog.cpp \
    dialogs/prescriptiondialog.cpp \
    dialogs/medicinedialog.cpp \
    dialogs/inventorydialog.cpp \
    dialogs/appointmentdialog.cpp \
    dialogs/scheduledialog.cpp \
    dialogs/logindialog.cpp \
    network/networkmanager.cpp \
    network/httpsynchronizer.cpp \
    network/tcpsyncserver.cpp \
    threads/reportgenerator.cpp \
    threads/statisticsthread.cpp \
    utils/excelreport.cpp

HEADERS += \
    mainwindow.h \
    databasemanager.h \
    models/patientmodel.h \
    models/doctormodel.h \
    models/departmentmodel.h \
    models/medicalrecordmodel.h \
    models/prescriptionmodel.h \
    models/medicinemodel.h \
    models/inventorymodel.h \
    models/appointmentmodel.h \
    models/schedulemodel.h \
    dialogs/patientdialog.h \
    dialogs/doctordialog.h \
    dialogs/departmentdialog.h \
    dialogs/medicalrecorddialog.h \
    dialogs/prescriptiondialog.h \
    dialogs/medicinedialog.h \
    dialogs/inventorydialog.h \
    dialogs/appointmentdialog.h \
    dialogs/scheduledialog.h \
    dialogs/logindialog.h \
    network/networkmanager.h \
    network/httpsynchronizer.h \
    network/tcpsyncserver.h \
    threads/reportgenerator.h \
    threads/statisticsthread.h \
    utils/excelreport.h

FORMS += \
    mainwindow.ui \
    dialogs/patientdialog.ui \
    dialogs/doctordialog.ui \
    dialogs/departmentdialog.ui \
    dialogs/medicalrecorddialog.ui \
    dialogs/prescriptiondialog.ui \
    dialogs/medicinedialog.ui \
    dialogs/inventorydialog.ui \
    dialogs/appointmentdialog.ui \
    dialogs/scheduledialog.ui \
    dialogs/logindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 资源文件（当前为空，可取消注释后添加资源）
# RESOURCES += \
#     resources/resources.qrc

