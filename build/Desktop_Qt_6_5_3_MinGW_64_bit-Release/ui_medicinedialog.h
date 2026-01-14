/********************************************************************************
** Form generated from reading UI file 'medicinedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICINEDIALOG_H
#define UI_MEDICINEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MedicineDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QLabel *label_code;
    QLineEdit *codeEdit;
    QLabel *label_spec;
    QLineEdit *specificationEdit;
    QLabel *label_unit;
    QLineEdit *unitEdit;
    QLabel *label_manufacturer;
    QLineEdit *manufacturerEdit;
    QLabel *label_price;
    QDoubleSpinBox *priceSpin;
    QLabel *label_desc;
    QTextEdit *descriptionEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MedicineDialog)
    {
        if (MedicineDialog->objectName().isEmpty())
            MedicineDialog->setObjectName("MedicineDialog");
        MedicineDialog->resize(450, 400);
        verticalLayout = new QVBoxLayout(MedicineDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_name = new QLabel(MedicineDialog);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        nameEdit = new QLineEdit(MedicineDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_code = new QLabel(MedicineDialog);
        label_code->setObjectName("label_code");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_code);

        codeEdit = new QLineEdit(MedicineDialog);
        codeEdit->setObjectName("codeEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, codeEdit);

        label_spec = new QLabel(MedicineDialog);
        label_spec->setObjectName("label_spec");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_spec);

        specificationEdit = new QLineEdit(MedicineDialog);
        specificationEdit->setObjectName("specificationEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, specificationEdit);

        label_unit = new QLabel(MedicineDialog);
        label_unit->setObjectName("label_unit");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_unit);

        unitEdit = new QLineEdit(MedicineDialog);
        unitEdit->setObjectName("unitEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, unitEdit);

        label_manufacturer = new QLabel(MedicineDialog);
        label_manufacturer->setObjectName("label_manufacturer");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_manufacturer);

        manufacturerEdit = new QLineEdit(MedicineDialog);
        manufacturerEdit->setObjectName("manufacturerEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, manufacturerEdit);

        label_price = new QLabel(MedicineDialog);
        label_price->setObjectName("label_price");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_price);

        priceSpin = new QDoubleSpinBox(MedicineDialog);
        priceSpin->setObjectName("priceSpin");
        priceSpin->setMinimum(0.000000000000000);
        priceSpin->setMaximum(999999.000000000000000);
        priceSpin->setDecimals(2);

        formLayout->setWidget(5, QFormLayout::FieldRole, priceSpin);

        label_desc = new QLabel(MedicineDialog);
        label_desc->setObjectName("label_desc");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_desc);

        descriptionEdit = new QTextEdit(MedicineDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMaximumHeight(100);

        formLayout->setWidget(6, QFormLayout::FieldRole, descriptionEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(MedicineDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MedicineDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MedicineDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MedicineDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MedicineDialog);
    } // setupUi

    void retranslateUi(QDialog *MedicineDialog)
    {
        MedicineDialog->setWindowTitle(QCoreApplication::translate("MedicineDialog", "\350\215\257\345\223\201\344\277\241\346\201\257", nullptr));
        label_name->setText(QCoreApplication::translate("MedicineDialog", "\350\215\257\345\223\201\345\220\215\347\247\260*:", nullptr));
        label_code->setText(QCoreApplication::translate("MedicineDialog", "\347\274\226\347\240\201:", nullptr));
        label_spec->setText(QCoreApplication::translate("MedicineDialog", "\350\247\204\346\240\274:", nullptr));
        label_unit->setText(QCoreApplication::translate("MedicineDialog", "\345\215\225\344\275\215:", nullptr));
        label_manufacturer->setText(QCoreApplication::translate("MedicineDialog", "\347\224\237\344\272\247\345\216\202\345\256\266:", nullptr));
        label_price->setText(QCoreApplication::translate("MedicineDialog", "\344\273\267\346\240\274:", nullptr));
        label_desc->setText(QCoreApplication::translate("MedicineDialog", "\346\217\217\350\277\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedicineDialog: public Ui_MedicineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICINEDIALOG_H
