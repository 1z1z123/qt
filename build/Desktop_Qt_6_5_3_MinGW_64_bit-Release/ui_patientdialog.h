/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QLabel *label_gender;
    QComboBox *genderCombo;
    QLabel *label_birth;
    QDateEdit *birthDateEdit;
    QLabel *label_phone;
    QLineEdit *phoneEdit;
    QLabel *label_email;
    QLineEdit *emailEdit;
    QLabel *label_address;
    QLineEdit *addressEdit;
    QLabel *label_idcard;
    QLineEdit *idCardEdit;
    QLabel *label_history;
    QTextEdit *medicalHistoryEdit;
    QLabel *label_allergy;
    QTextEdit *allergyInfoEdit;
    QLabel *label_emergency;
    QLineEdit *emergencyContactEdit;
    QLabel *label_emergency_phone;
    QLineEdit *emergencyPhoneEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName("PatientDialog");
        PatientDialog->resize(550, 650);
        verticalLayout = new QVBoxLayout(PatientDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_name = new QLabel(PatientDialog);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        nameEdit = new QLineEdit(PatientDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_gender = new QLabel(PatientDialog);
        label_gender->setObjectName("label_gender");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_gender);

        genderCombo = new QComboBox(PatientDialog);
        genderCombo->setObjectName("genderCombo");

        formLayout->setWidget(1, QFormLayout::FieldRole, genderCombo);

        label_birth = new QLabel(PatientDialog);
        label_birth->setObjectName("label_birth");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_birth);

        birthDateEdit = new QDateEdit(PatientDialog);
        birthDateEdit->setObjectName("birthDateEdit");
        birthDateEdit->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, birthDateEdit);

        label_phone = new QLabel(PatientDialog);
        label_phone->setObjectName("label_phone");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_phone);

        phoneEdit = new QLineEdit(PatientDialog);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, phoneEdit);

        label_email = new QLabel(PatientDialog);
        label_email->setObjectName("label_email");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_email);

        emailEdit = new QLineEdit(PatientDialog);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, emailEdit);

        label_address = new QLabel(PatientDialog);
        label_address->setObjectName("label_address");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_address);

        addressEdit = new QLineEdit(PatientDialog);
        addressEdit->setObjectName("addressEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, addressEdit);

        label_idcard = new QLabel(PatientDialog);
        label_idcard->setObjectName("label_idcard");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_idcard);

        idCardEdit = new QLineEdit(PatientDialog);
        idCardEdit->setObjectName("idCardEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, idCardEdit);

        label_history = new QLabel(PatientDialog);
        label_history->setObjectName("label_history");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_history);

        medicalHistoryEdit = new QTextEdit(PatientDialog);
        medicalHistoryEdit->setObjectName("medicalHistoryEdit");
        medicalHistoryEdit->setMaximumHeight(80);

        formLayout->setWidget(7, QFormLayout::FieldRole, medicalHistoryEdit);

        label_allergy = new QLabel(PatientDialog);
        label_allergy->setObjectName("label_allergy");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_allergy);

        allergyInfoEdit = new QTextEdit(PatientDialog);
        allergyInfoEdit->setObjectName("allergyInfoEdit");
        allergyInfoEdit->setMaximumHeight(80);

        formLayout->setWidget(8, QFormLayout::FieldRole, allergyInfoEdit);

        label_emergency = new QLabel(PatientDialog);
        label_emergency->setObjectName("label_emergency");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_emergency);

        emergencyContactEdit = new QLineEdit(PatientDialog);
        emergencyContactEdit->setObjectName("emergencyContactEdit");

        formLayout->setWidget(9, QFormLayout::FieldRole, emergencyContactEdit);

        label_emergency_phone = new QLabel(PatientDialog);
        label_emergency_phone->setObjectName("label_emergency_phone");

        formLayout->setWidget(10, QFormLayout::LabelRole, label_emergency_phone);

        emergencyPhoneEdit = new QLineEdit(PatientDialog);
        emergencyPhoneEdit->setObjectName("emergencyPhoneEdit");

        formLayout->setWidget(10, QFormLayout::FieldRole, emergencyPhoneEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(PatientDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PatientDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PatientDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PatientDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDialog)
    {
        PatientDialog->setWindowTitle(QCoreApplication::translate("PatientDialog", "\347\227\205\344\272\272\344\277\241\346\201\257", nullptr));
        label_name->setText(QCoreApplication::translate("PatientDialog", "\345\247\223\345\220\215*:", nullptr));
        label_gender->setText(QCoreApplication::translate("PatientDialog", "\346\200\247\345\210\253:", nullptr));
        label_birth->setText(QCoreApplication::translate("PatientDialog", "\345\207\272\347\224\237\346\227\245\346\234\237:", nullptr));
        label_phone->setText(QCoreApplication::translate("PatientDialog", "\347\224\265\350\257\235:", nullptr));
        label_email->setText(QCoreApplication::translate("PatientDialog", "\351\202\256\347\256\261:", nullptr));
        label_address->setText(QCoreApplication::translate("PatientDialog", "\345\234\260\345\235\200:", nullptr));
        label_idcard->setText(QCoreApplication::translate("PatientDialog", "\350\272\253\344\273\275\350\257\201\345\217\267:", nullptr));
        label_history->setText(QCoreApplication::translate("PatientDialog", "\347\227\205\345\217\262:", nullptr));
        label_allergy->setText(QCoreApplication::translate("PatientDialog", "\350\277\207\346\225\217\344\277\241\346\201\257:", nullptr));
        label_emergency->setText(QCoreApplication::translate("PatientDialog", "\347\264\247\346\200\245\350\201\224\347\263\273\344\272\272:", nullptr));
        label_emergency_phone->setText(QCoreApplication::translate("PatientDialog", "\347\264\247\346\200\245\350\201\224\347\263\273\347\224\265\350\257\235:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
