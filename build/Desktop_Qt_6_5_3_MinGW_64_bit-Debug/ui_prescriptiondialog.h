/********************************************************************************
** Form generated from reading UI file 'prescriptiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESCRIPTIONDIALOG_H
#define UI_PRESCRIPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PrescriptionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_record;
    QSpinBox *medicalRecordIdSpin;
    QLabel *label_medicine;
    QSpinBox *medicineIdSpin;
    QLabel *label_quantity;
    QSpinBox *quantitySpin;
    QLabel *label_dosage;
    QLineEdit *dosageEdit;
    QLabel *label_frequency;
    QLineEdit *frequencyEdit;
    QLabel *label_duration;
    QLineEdit *durationEdit;
    QLabel *label_instructions;
    QTextEdit *instructionsEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PrescriptionDialog)
    {
        if (PrescriptionDialog->objectName().isEmpty())
            PrescriptionDialog->setObjectName("PrescriptionDialog");
        PrescriptionDialog->resize(450, 400);
        verticalLayout = new QVBoxLayout(PrescriptionDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_record = new QLabel(PrescriptionDialog);
        label_record->setObjectName("label_record");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_record);

        medicalRecordIdSpin = new QSpinBox(PrescriptionDialog);
        medicalRecordIdSpin->setObjectName("medicalRecordIdSpin");
        medicalRecordIdSpin->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, medicalRecordIdSpin);

        label_medicine = new QLabel(PrescriptionDialog);
        label_medicine->setObjectName("label_medicine");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_medicine);

        medicineIdSpin = new QSpinBox(PrescriptionDialog);
        medicineIdSpin->setObjectName("medicineIdSpin");
        medicineIdSpin->setMinimum(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, medicineIdSpin);

        label_quantity = new QLabel(PrescriptionDialog);
        label_quantity->setObjectName("label_quantity");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_quantity);

        quantitySpin = new QSpinBox(PrescriptionDialog);
        quantitySpin->setObjectName("quantitySpin");
        quantitySpin->setMinimum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, quantitySpin);

        label_dosage = new QLabel(PrescriptionDialog);
        label_dosage->setObjectName("label_dosage");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_dosage);

        dosageEdit = new QLineEdit(PrescriptionDialog);
        dosageEdit->setObjectName("dosageEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, dosageEdit);

        label_frequency = new QLabel(PrescriptionDialog);
        label_frequency->setObjectName("label_frequency");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_frequency);

        frequencyEdit = new QLineEdit(PrescriptionDialog);
        frequencyEdit->setObjectName("frequencyEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, frequencyEdit);

        label_duration = new QLabel(PrescriptionDialog);
        label_duration->setObjectName("label_duration");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_duration);

        durationEdit = new QLineEdit(PrescriptionDialog);
        durationEdit->setObjectName("durationEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, durationEdit);

        label_instructions = new QLabel(PrescriptionDialog);
        label_instructions->setObjectName("label_instructions");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_instructions);

        instructionsEdit = new QTextEdit(PrescriptionDialog);
        instructionsEdit->setObjectName("instructionsEdit");
        instructionsEdit->setMaximumHeight(100);

        formLayout->setWidget(6, QFormLayout::FieldRole, instructionsEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(PrescriptionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PrescriptionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PrescriptionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PrescriptionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PrescriptionDialog);
    } // setupUi

    void retranslateUi(QDialog *PrescriptionDialog)
    {
        PrescriptionDialog->setWindowTitle(QCoreApplication::translate("PrescriptionDialog", "\345\244\204\346\226\271\344\277\241\346\201\257", nullptr));
        label_record->setText(QCoreApplication::translate("PrescriptionDialog", "\345\260\261\350\257\212\350\256\260\345\275\225ID*:", nullptr));
        label_medicine->setText(QCoreApplication::translate("PrescriptionDialog", "\350\215\257\345\223\201ID*:", nullptr));
        label_quantity->setText(QCoreApplication::translate("PrescriptionDialog", "\346\225\260\351\207\217*:", nullptr));
        label_dosage->setText(QCoreApplication::translate("PrescriptionDialog", "\347\224\250\346\263\225:", nullptr));
        label_frequency->setText(QCoreApplication::translate("PrescriptionDialog", "\351\242\221\346\254\241:", nullptr));
        label_duration->setText(QCoreApplication::translate("PrescriptionDialog", "\347\226\227\347\250\213:", nullptr));
        label_instructions->setText(QCoreApplication::translate("PrescriptionDialog", "\350\257\264\346\230\216:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrescriptionDialog: public Ui_PrescriptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESCRIPTIONDIALOG_H
