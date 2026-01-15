/********************************************************************************
** Form generated from reading UI file 'appointmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTDIALOG_H
#define UI_APPOINTMENTDIALOG_H

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

class Ui_AppointmentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_patient;
    QSpinBox *patientIdSpin;
    QLabel *label_doctor;
    QSpinBox *doctorIdSpin;
    QLabel *label_date;
    QDateEdit *appointmentDateEdit;
    QLabel *label_time;
    QTimeEdit *appointmentTimeEdit;
    QLabel *label_status;
    QComboBox *statusCombo;
    QLabel *label_reason;
    QTextEdit *reasonEdit;
    QLabel *label_notes;
    QTextEdit *notesEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AppointmentDialog)
    {
        if (AppointmentDialog->objectName().isEmpty())
            AppointmentDialog->setObjectName("AppointmentDialog");
        AppointmentDialog->resize(450, 450);
        verticalLayout = new QVBoxLayout(AppointmentDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_patient = new QLabel(AppointmentDialog);
        label_patient->setObjectName("label_patient");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_patient);

        patientIdSpin = new QSpinBox(AppointmentDialog);
        patientIdSpin->setObjectName("patientIdSpin");
        patientIdSpin->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, patientIdSpin);

        label_doctor = new QLabel(AppointmentDialog);
        label_doctor->setObjectName("label_doctor");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_doctor);

        doctorIdSpin = new QSpinBox(AppointmentDialog);
        doctorIdSpin->setObjectName("doctorIdSpin");
        doctorIdSpin->setMinimum(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, doctorIdSpin);

        label_date = new QLabel(AppointmentDialog);
        label_date->setObjectName("label_date");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_date);

        appointmentDateEdit = new QDateEdit(AppointmentDialog);
        appointmentDateEdit->setObjectName("appointmentDateEdit");
        appointmentDateEdit->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, appointmentDateEdit);

        label_time = new QLabel(AppointmentDialog);
        label_time->setObjectName("label_time");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_time);

        appointmentTimeEdit = new QTimeEdit(AppointmentDialog);
        appointmentTimeEdit->setObjectName("appointmentTimeEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, appointmentTimeEdit);

        label_status = new QLabel(AppointmentDialog);
        label_status->setObjectName("label_status");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_status);

        statusCombo = new QComboBox(AppointmentDialog);
        statusCombo->setObjectName("statusCombo");

        formLayout->setWidget(4, QFormLayout::FieldRole, statusCombo);

        label_reason = new QLabel(AppointmentDialog);
        label_reason->setObjectName("label_reason");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_reason);

        reasonEdit = new QTextEdit(AppointmentDialog);
        reasonEdit->setObjectName("reasonEdit");
        reasonEdit->setMaximumHeight(80);

        formLayout->setWidget(5, QFormLayout::FieldRole, reasonEdit);

        label_notes = new QLabel(AppointmentDialog);
        label_notes->setObjectName("label_notes");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_notes);

        notesEdit = new QTextEdit(AppointmentDialog);
        notesEdit->setObjectName("notesEdit");
        notesEdit->setMaximumHeight(80);

        formLayout->setWidget(6, QFormLayout::FieldRole, notesEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AppointmentDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AppointmentDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AppointmentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AppointmentDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AppointmentDialog);
    } // setupUi

    void retranslateUi(QDialog *AppointmentDialog)
    {
        AppointmentDialog->setWindowTitle(QCoreApplication::translate("AppointmentDialog", "\351\242\204\347\272\246\344\277\241\346\201\257", nullptr));
        label_patient->setText(QCoreApplication::translate("AppointmentDialog", "\347\227\205\344\272\272ID*:", nullptr));
        label_doctor->setText(QCoreApplication::translate("AppointmentDialog", "\345\214\273\347\224\237ID*:", nullptr));
        label_date->setText(QCoreApplication::translate("AppointmentDialog", "\351\242\204\347\272\246\346\227\245\346\234\237*:", nullptr));
        label_time->setText(QCoreApplication::translate("AppointmentDialog", "\351\242\204\347\272\246\346\227\266\351\227\264*:", nullptr));
        label_status->setText(QCoreApplication::translate("AppointmentDialog", "\347\212\266\346\200\201:", nullptr));
        label_reason->setText(QCoreApplication::translate("AppointmentDialog", "\345\216\237\345\233\240:", nullptr));
        label_notes->setText(QCoreApplication::translate("AppointmentDialog", "\345\244\207\346\263\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppointmentDialog: public Ui_AppointmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTDIALOG_H
