/********************************************************************************
** Form generated from reading UI file 'inventorydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYDIALOG_H
#define UI_INVENTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InventoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_medicine;
    QSpinBox *medicineIdSpin;
    QLabel *label_quantity;
    QSpinBox *quantitySpin;
    QLabel *label_min;
    QSpinBox *minStockSpin;
    QLabel *label_max;
    QSpinBox *maxStockSpin;
    QLabel *label_expiry;
    QDateEdit *expiryDateEdit;
    QLabel *label_batch;
    QLineEdit *batchNumberEdit;
    QLabel *label_supplier;
    QLineEdit *supplierEdit;
    QLabel *label_price;
    QDoubleSpinBox *purchasePriceSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InventoryDialog)
    {
        if (InventoryDialog->objectName().isEmpty())
            InventoryDialog->setObjectName("InventoryDialog");
        InventoryDialog->resize(450, 450);
        verticalLayout = new QVBoxLayout(InventoryDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_medicine = new QLabel(InventoryDialog);
        label_medicine->setObjectName("label_medicine");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_medicine);

        medicineIdSpin = new QSpinBox(InventoryDialog);
        medicineIdSpin->setObjectName("medicineIdSpin");
        medicineIdSpin->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, medicineIdSpin);

        label_quantity = new QLabel(InventoryDialog);
        label_quantity->setObjectName("label_quantity");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_quantity);

        quantitySpin = new QSpinBox(InventoryDialog);
        quantitySpin->setObjectName("quantitySpin");
        quantitySpin->setMinimum(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, quantitySpin);

        label_min = new QLabel(InventoryDialog);
        label_min->setObjectName("label_min");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_min);

        minStockSpin = new QSpinBox(InventoryDialog);
        minStockSpin->setObjectName("minStockSpin");
        minStockSpin->setMinimum(0);

        formLayout->setWidget(2, QFormLayout::FieldRole, minStockSpin);

        label_max = new QLabel(InventoryDialog);
        label_max->setObjectName("label_max");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_max);

        maxStockSpin = new QSpinBox(InventoryDialog);
        maxStockSpin->setObjectName("maxStockSpin");
        maxStockSpin->setMinimum(0);

        formLayout->setWidget(3, QFormLayout::FieldRole, maxStockSpin);

        label_expiry = new QLabel(InventoryDialog);
        label_expiry->setObjectName("label_expiry");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_expiry);

        expiryDateEdit = new QDateEdit(InventoryDialog);
        expiryDateEdit->setObjectName("expiryDateEdit");
        expiryDateEdit->setCalendarPopup(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, expiryDateEdit);

        label_batch = new QLabel(InventoryDialog);
        label_batch->setObjectName("label_batch");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_batch);

        batchNumberEdit = new QLineEdit(InventoryDialog);
        batchNumberEdit->setObjectName("batchNumberEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, batchNumberEdit);

        label_supplier = new QLabel(InventoryDialog);
        label_supplier->setObjectName("label_supplier");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_supplier);

        supplierEdit = new QLineEdit(InventoryDialog);
        supplierEdit->setObjectName("supplierEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, supplierEdit);

        label_price = new QLabel(InventoryDialog);
        label_price->setObjectName("label_price");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_price);

        purchasePriceSpin = new QDoubleSpinBox(InventoryDialog);
        purchasePriceSpin->setObjectName("purchasePriceSpin");
        purchasePriceSpin->setMinimum(0.000000000000000);
        purchasePriceSpin->setDecimals(2);

        formLayout->setWidget(7, QFormLayout::FieldRole, purchasePriceSpin);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(InventoryDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InventoryDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, InventoryDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, InventoryDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(InventoryDialog);
    } // setupUi

    void retranslateUi(QDialog *InventoryDialog)
    {
        InventoryDialog->setWindowTitle(QCoreApplication::translate("InventoryDialog", "\345\272\223\345\255\230\344\277\241\346\201\257", nullptr));
        label_medicine->setText(QCoreApplication::translate("InventoryDialog", "\350\215\257\345\223\201ID*:", nullptr));
        label_quantity->setText(QCoreApplication::translate("InventoryDialog", "\345\272\223\345\255\230\346\225\260\351\207\217:", nullptr));
        label_min->setText(QCoreApplication::translate("InventoryDialog", "\346\234\200\344\275\216\345\272\223\345\255\230:", nullptr));
        label_max->setText(QCoreApplication::translate("InventoryDialog", "\346\234\200\351\253\230\345\272\223\345\255\230:", nullptr));
        label_expiry->setText(QCoreApplication::translate("InventoryDialog", "\350\277\207\346\234\237\346\227\245\346\234\237:", nullptr));
        label_batch->setText(QCoreApplication::translate("InventoryDialog", "\346\211\271\346\254\241\345\217\267:", nullptr));
        label_supplier->setText(QCoreApplication::translate("InventoryDialog", "\344\276\233\345\272\224\345\225\206:", nullptr));
        label_price->setText(QCoreApplication::translate("InventoryDialog", "\351\207\207\350\264\255\344\273\267\346\240\274:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InventoryDialog: public Ui_InventoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYDIALOG_H
