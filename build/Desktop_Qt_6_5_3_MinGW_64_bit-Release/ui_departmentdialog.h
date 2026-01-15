/********************************************************************************
** Form generated from reading UI file 'departmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTDIALOG_H
#define UI_DEPARTMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DepartmentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QLabel *label_desc;
    QTextEdit *descriptionEdit;
    QLabel *label_location;
    QLineEdit *locationEdit;
    QLabel *label_phone;
    QLineEdit *phoneEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DepartmentDialog)
    {
        if (DepartmentDialog->objectName().isEmpty())
            DepartmentDialog->setObjectName("DepartmentDialog");
        DepartmentDialog->resize(450, 320);
        verticalLayout = new QVBoxLayout(DepartmentDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_name = new QLabel(DepartmentDialog);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        nameEdit = new QLineEdit(DepartmentDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_desc = new QLabel(DepartmentDialog);
        label_desc->setObjectName("label_desc");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_desc);

        descriptionEdit = new QTextEdit(DepartmentDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMaximumHeight(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, descriptionEdit);

        label_location = new QLabel(DepartmentDialog);
        label_location->setObjectName("label_location");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_location);

        locationEdit = new QLineEdit(DepartmentDialog);
        locationEdit->setObjectName("locationEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, locationEdit);

        label_phone = new QLabel(DepartmentDialog);
        label_phone->setObjectName("label_phone");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_phone);

        phoneEdit = new QLineEdit(DepartmentDialog);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, phoneEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DepartmentDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DepartmentDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DepartmentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DepartmentDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DepartmentDialog);
    } // setupUi

    void retranslateUi(QDialog *DepartmentDialog)
    {
        DepartmentDialog->setWindowTitle(QCoreApplication::translate("DepartmentDialog", "\347\247\221\345\256\244\344\277\241\346\201\257", nullptr));
        label_name->setText(QCoreApplication::translate("DepartmentDialog", "\347\247\221\345\256\244\345\220\215\347\247\260*:", nullptr));
        label_desc->setText(QCoreApplication::translate("DepartmentDialog", "\346\217\217\350\277\260:", nullptr));
        label_location->setText(QCoreApplication::translate("DepartmentDialog", "\344\275\215\347\275\256:", nullptr));
        label_phone->setText(QCoreApplication::translate("DepartmentDialog", "\347\224\265\350\257\235:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartmentDialog: public Ui_DepartmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTDIALOG_H
