/********************************************************************************
** Form generated from reading UI file 'doctordialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORDIALOG_H
#define UI_DOCTORDIALOG_H

#include <QtCore/QDate>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DoctorDialog
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
    QLabel *label_dept;
    QSpinBox *departmentIdSpin;
    QLabel *label_title;
    QLineEdit *titleEdit;
    QLabel *label_license;
    QLineEdit *licenseNumberEdit;
    QLabel *label_spec;
    QLineEdit *specializationEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DoctorDialog)
    {
        if (DoctorDialog->objectName().isEmpty())
            DoctorDialog->setObjectName("DoctorDialog");
        DoctorDialog->resize(450, 400);
        verticalLayout = new QVBoxLayout(DoctorDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_name = new QLabel(DoctorDialog);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        nameEdit = new QLineEdit(DoctorDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_gender = new QLabel(DoctorDialog);
        label_gender->setObjectName("label_gender");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_gender);

        genderCombo = new QComboBox(DoctorDialog);
        genderCombo->setObjectName("genderCombo");

        formLayout->setWidget(1, QFormLayout::FieldRole, genderCombo);

        label_birth = new QLabel(DoctorDialog);
        label_birth->setObjectName("label_birth");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_birth);

        birthDateEdit = new QDateEdit(DoctorDialog);
        birthDateEdit->setObjectName("birthDateEdit");
        birthDateEdit->setCalendarPopup(true);
        birthDateEdit->setDate(QDate(2000, 1, 1));

        formLayout->setWidget(2, QFormLayout::FieldRole, birthDateEdit);

        label_phone = new QLabel(DoctorDialog);
        label_phone->setObjectName("label_phone");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_phone);

        phoneEdit = new QLineEdit(DoctorDialog);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, phoneEdit);

        label_email = new QLabel(DoctorDialog);
        label_email->setObjectName("label_email");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_email);

        emailEdit = new QLineEdit(DoctorDialog);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, emailEdit);

        label_dept = new QLabel(DoctorDialog);
        label_dept->setObjectName("label_dept");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_dept);

        departmentIdSpin = new QSpinBox(DoctorDialog);
        departmentIdSpin->setObjectName("departmentIdSpin");
        departmentIdSpin->setMinimum(1);

        formLayout->setWidget(5, QFormLayout::FieldRole, departmentIdSpin);

        label_title = new QLabel(DoctorDialog);
        label_title->setObjectName("label_title");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_title);

        titleEdit = new QLineEdit(DoctorDialog);
        titleEdit->setObjectName("titleEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, titleEdit);

        label_license = new QLabel(DoctorDialog);
        label_license->setObjectName("label_license");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_license);

        licenseNumberEdit = new QLineEdit(DoctorDialog);
        licenseNumberEdit->setObjectName("licenseNumberEdit");

        formLayout->setWidget(7, QFormLayout::FieldRole, licenseNumberEdit);

        label_spec = new QLabel(DoctorDialog);
        label_spec->setObjectName("label_spec");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_spec);

        specializationEdit = new QLineEdit(DoctorDialog);
        specializationEdit->setObjectName("specializationEdit");

        formLayout->setWidget(8, QFormLayout::FieldRole, specializationEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DoctorDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DoctorDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DoctorDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DoctorDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *DoctorDialog)
    {
        DoctorDialog->setWindowTitle(QCoreApplication::translate("DoctorDialog", "\345\214\273\347\224\237\344\277\241\346\201\257", nullptr));
        label_name->setText(QCoreApplication::translate("DoctorDialog", "\345\247\223\345\220\215*:", nullptr));
        label_gender->setText(QCoreApplication::translate("DoctorDialog", "\346\200\247\345\210\253:", nullptr));
        label_birth->setText(QCoreApplication::translate("DoctorDialog", "\345\207\272\347\224\237\346\227\245\346\234\237:", nullptr));
        label_phone->setText(QCoreApplication::translate("DoctorDialog", "\347\224\265\350\257\235:", nullptr));
        label_email->setText(QCoreApplication::translate("DoctorDialog", "\351\202\256\347\256\261:", nullptr));
        label_dept->setText(QCoreApplication::translate("DoctorDialog", "\347\247\221\345\256\244ID:", nullptr));
        label_title->setText(QCoreApplication::translate("DoctorDialog", "\350\201\214\347\247\260:", nullptr));
        label_license->setText(QCoreApplication::translate("DoctorDialog", "\346\211\247\344\270\232\350\257\201\345\217\267:", nullptr));
        label_spec->setText(QCoreApplication::translate("DoctorDialog", "\344\270\223\344\270\232:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorDialog: public Ui_DoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORDIALOG_H
