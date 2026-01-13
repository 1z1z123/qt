/********************************************************************************
** Form generated from reading UI file 'medicalrecorddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICALRECORDDIALOG_H
#define UI_MEDICALRECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MedicalRecordDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_patient;
    QSpinBox *patientIdSpin;
    QLabel *label_doctor;
    QSpinBox *doctorIdSpin;
    QLabel *label_dept;
    QSpinBox *departmentIdSpin;
    QLabel *label_date;
    QDateEdit *visitDateEdit;
    QLabel *label_complaint;
    QTextEdit *chiefComplaintEdit;
    QLabel *label_diagnosis;
    QTextEdit *diagnosisEdit;
    QLabel *label_treatment;
    QTextEdit *treatmentEdit;
    QLabel *label_notes;
    QTextEdit *notesEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MedicalRecordDialog)
    {
        if (MedicalRecordDialog->objectName().isEmpty())
            MedicalRecordDialog->setObjectName("MedicalRecordDialog");
        MedicalRecordDialog->resize(550, 600);
        verticalLayout = new QVBoxLayout(MedicalRecordDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_patient = new QLabel(MedicalRecordDialog);
        label_patient->setObjectName("label_patient");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_patient);

        patientIdSpin = new QSpinBox(MedicalRecordDialog);
        patientIdSpin->setObjectName("patientIdSpin");
        patientIdSpin->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, patientIdSpin);

        label_doctor = new QLabel(MedicalRecordDialog);
        label_doctor->setObjectName("label_doctor");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_doctor);

        doctorIdSpin = new QSpinBox(MedicalRecordDialog);
        doctorIdSpin->setObjectName("doctorIdSpin");
        doctorIdSpin->setMinimum(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, doctorIdSpin);

        label_dept = new QLabel(MedicalRecordDialog);
        label_dept->setObjectName("label_dept");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_dept);

        departmentIdSpin = new QSpinBox(MedicalRecordDialog);
        departmentIdSpin->setObjectName("departmentIdSpin");
        departmentIdSpin->setMinimum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, departmentIdSpin);

        label_date = new QLabel(MedicalRecordDialog);
        label_date->setObjectName("label_date");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_date);

        visitDateEdit = new QDateEdit(MedicalRecordDialog);
        visitDateEdit->setObjectName("visitDateEdit");
        visitDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, visitDateEdit);

        label_complaint = new QLabel(MedicalRecordDialog);
        label_complaint->setObjectName("label_complaint");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_complaint);

        chiefComplaintEdit = new QTextEdit(MedicalRecordDialog);
        chiefComplaintEdit->setObjectName("chiefComplaintEdit");
        chiefComplaintEdit->setMaximumHeight(80);

        formLayout->setWidget(4, QFormLayout::FieldRole, chiefComplaintEdit);

        label_diagnosis = new QLabel(MedicalRecordDialog);
        label_diagnosis->setObjectName("label_diagnosis");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_diagnosis);

        diagnosisEdit = new QTextEdit(MedicalRecordDialog);
        diagnosisEdit->setObjectName("diagnosisEdit");
        diagnosisEdit->setMaximumHeight(80);

        formLayout->setWidget(5, QFormLayout::FieldRole, diagnosisEdit);

        label_treatment = new QLabel(MedicalRecordDialog);
        label_treatment->setObjectName("label_treatment");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_treatment);

        treatmentEdit = new QTextEdit(MedicalRecordDialog);
        treatmentEdit->setObjectName("treatmentEdit");
        treatmentEdit->setMaximumHeight(100);

        formLayout->setWidget(6, QFormLayout::FieldRole, treatmentEdit);

        label_notes = new QLabel(MedicalRecordDialog);
        label_notes->setObjectName("label_notes");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_notes);

        notesEdit = new QTextEdit(MedicalRecordDialog);
        notesEdit->setObjectName("notesEdit");
        notesEdit->setMaximumHeight(80);

        formLayout->setWidget(7, QFormLayout::FieldRole, notesEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(MedicalRecordDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MedicalRecordDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MedicalRecordDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MedicalRecordDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MedicalRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *MedicalRecordDialog)
    {
        MedicalRecordDialog->setWindowTitle(QCoreApplication::translate("MedicalRecordDialog", "\345\260\261\350\257\212\350\256\260\345\275\225", nullptr));
        label_patient->setText(QCoreApplication::translate("MedicalRecordDialog", "\347\227\205\344\272\272ID*:", nullptr));
        label_doctor->setText(QCoreApplication::translate("MedicalRecordDialog", "\345\214\273\347\224\237ID*:", nullptr));
        label_dept->setText(QCoreApplication::translate("MedicalRecordDialog", "\347\247\221\345\256\244ID:", nullptr));
        label_date->setText(QCoreApplication::translate("MedicalRecordDialog", "\345\260\261\350\257\212\346\227\245\346\234\237*:", nullptr));
        label_complaint->setText(QCoreApplication::translate("MedicalRecordDialog", "\344\270\273\350\257\211:", nullptr));
        label_diagnosis->setText(QCoreApplication::translate("MedicalRecordDialog", "\350\257\212\346\226\255:", nullptr));
        label_treatment->setText(QCoreApplication::translate("MedicalRecordDialog", "\346\262\273\347\226\227\346\226\271\346\241\210:", nullptr));
        label_notes->setText(QCoreApplication::translate("MedicalRecordDialog", "\345\244\207\346\263\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedicalRecordDialog: public Ui_MedicalRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICALRECORDDIALOG_H
