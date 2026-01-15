/********************************************************************************
** Form generated from reading UI file 'scheduledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULEDIALOG_H
#define UI_SCHEDULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScheduleDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_doctor;
    QSpinBox *doctorIdSpin;
    QLabel *label_date;
    QDateEdit *scheduleDateEdit;
    QLabel *label_start;
    QTimeEdit *startTimeEdit;
    QLabel *label_end;
    QTimeEdit *endTimeEdit;
    QLabel *label_max;
    QSpinBox *maxAppointmentsSpin;
    QLabel *label_current;
    QSpinBox *currentAppointmentsSpin;
    QLabel *label_status;
    QComboBox *statusCombo;
    QLabel *label_notes;
    QTextEdit *notesEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScheduleDialog)
    {
        if (ScheduleDialog->objectName().isEmpty())
            ScheduleDialog->setObjectName("ScheduleDialog");
        ScheduleDialog->resize(450, 450);
        verticalLayout = new QVBoxLayout(ScheduleDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_doctor = new QLabel(ScheduleDialog);
        label_doctor->setObjectName("label_doctor");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_doctor);

        doctorIdSpin = new QSpinBox(ScheduleDialog);
        doctorIdSpin->setObjectName("doctorIdSpin");
        doctorIdSpin->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, doctorIdSpin);

        label_date = new QLabel(ScheduleDialog);
        label_date->setObjectName("label_date");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_date);

        scheduleDateEdit = new QDateEdit(ScheduleDialog);
        scheduleDateEdit->setObjectName("scheduleDateEdit");
        scheduleDateEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, scheduleDateEdit);

        label_start = new QLabel(ScheduleDialog);
        label_start->setObjectName("label_start");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_start);

        startTimeEdit = new QTimeEdit(ScheduleDialog);
        startTimeEdit->setObjectName("startTimeEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, startTimeEdit);

        label_end = new QLabel(ScheduleDialog);
        label_end->setObjectName("label_end");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_end);

        endTimeEdit = new QTimeEdit(ScheduleDialog);
        endTimeEdit->setObjectName("endTimeEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, endTimeEdit);

        label_max = new QLabel(ScheduleDialog);
        label_max->setObjectName("label_max");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_max);

        maxAppointmentsSpin = new QSpinBox(ScheduleDialog);
        maxAppointmentsSpin->setObjectName("maxAppointmentsSpin");
        maxAppointmentsSpin->setMinimum(1);
        maxAppointmentsSpin->setMaximum(100);
        maxAppointmentsSpin->setValue(20);

        formLayout->setWidget(4, QFormLayout::FieldRole, maxAppointmentsSpin);

        label_current = new QLabel(ScheduleDialog);
        label_current->setObjectName("label_current");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_current);

        currentAppointmentsSpin = new QSpinBox(ScheduleDialog);
        currentAppointmentsSpin->setObjectName("currentAppointmentsSpin");
        currentAppointmentsSpin->setMinimum(0);

        formLayout->setWidget(5, QFormLayout::FieldRole, currentAppointmentsSpin);

        label_status = new QLabel(ScheduleDialog);
        label_status->setObjectName("label_status");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_status);

        statusCombo = new QComboBox(ScheduleDialog);
        statusCombo->setObjectName("statusCombo");

        formLayout->setWidget(6, QFormLayout::FieldRole, statusCombo);

        label_notes = new QLabel(ScheduleDialog);
        label_notes->setObjectName("label_notes");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_notes);

        notesEdit = new QTextEdit(ScheduleDialog);
        notesEdit->setObjectName("notesEdit");
        notesEdit->setMaximumHeight(80);

        formLayout->setWidget(7, QFormLayout::FieldRole, notesEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ScheduleDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ScheduleDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ScheduleDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ScheduleDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ScheduleDialog);
    } // setupUi

    void retranslateUi(QDialog *ScheduleDialog)
    {
        ScheduleDialog->setWindowTitle(QCoreApplication::translate("ScheduleDialog", "\346\216\222\347\217\255\344\277\241\346\201\257", nullptr));
        label_doctor->setText(QCoreApplication::translate("ScheduleDialog", "\345\214\273\347\224\237ID*:", nullptr));
        label_date->setText(QCoreApplication::translate("ScheduleDialog", "\346\216\222\347\217\255\346\227\245\346\234\237*:", nullptr));
        label_start->setText(QCoreApplication::translate("ScheduleDialog", "\345\274\200\345\247\213\346\227\266\351\227\264*:", nullptr));
        label_end->setText(QCoreApplication::translate("ScheduleDialog", "\347\273\223\346\235\237\346\227\266\351\227\264*:", nullptr));
        label_max->setText(QCoreApplication::translate("ScheduleDialog", "\346\234\200\345\244\247\351\242\204\347\272\246\346\225\260:", nullptr));
        label_current->setText(QCoreApplication::translate("ScheduleDialog", "\345\275\223\345\211\215\351\242\204\347\272\246\346\225\260:", nullptr));
        label_status->setText(QCoreApplication::translate("ScheduleDialog", "\347\212\266\346\200\201:", nullptr));
        label_notes->setText(QCoreApplication::translate("ScheduleDialog", "\345\244\207\346\263\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScheduleDialog: public Ui_ScheduleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULEDIALOG_H
