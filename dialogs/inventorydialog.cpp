#include "inventorydialog.h"
#include "ui_inventorydialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>

InventoryDialog::InventoryDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::InventoryDialog), m_inventoryId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加库存");
    ui->expiryDateEdit->setDate(QDate::currentDate());
}

InventoryDialog::InventoryDialog(int inventoryId, QWidget *parent)
    : QDialog(parent), ui(new Ui::InventoryDialog), m_inventoryId(inventoryId)
{
    ui->setupUi(this);
    setWindowTitle("编辑库存");
    loadInventoryData(inventoryId);
}

InventoryDialog::~InventoryDialog()
{
    delete ui;
}

void InventoryDialog::loadInventoryData(int inventoryId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM inventory WHERE id = ?");
    query.addBindValue(inventoryId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载库存数据");
        return;
    }
    
    ui->medicineIdSpin->setValue(query.value("medicine_id").toInt());
    ui->quantitySpin->setValue(query.value("quantity").toInt());
    ui->minStockSpin->setValue(query.value("min_stock").toInt());
    ui->maxStockSpin->setValue(query.value("max_stock").toInt());
    ui->expiryDateEdit->setDate(QDate::fromString(query.value("expiry_date").toString(), "yyyy-MM-dd"));
    ui->batchNumberEdit->setText(query.value("batch_number").toString());
    ui->supplierEdit->setText(query.value("supplier").toString());
    ui->purchasePriceSpin->setValue(query.value("purchase_price").toDouble());
}

void InventoryDialog::accept()
{
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_inventoryId == -1) {
        query.prepare(R"(
            INSERT INTO inventory (medicine_id, quantity, min_stock, max_stock,
                                 expiry_date, batch_number, supplier, purchase_price)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE inventory SET medicine_id=?, quantity=?, min_stock=?, max_stock=?,
                               expiry_date=?, batch_number=?, supplier=?, purchase_price=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->medicineIdSpin->value());
    query.addBindValue(ui->quantitySpin->value());
    query.addBindValue(ui->minStockSpin->value());
    query.addBindValue(ui->maxStockSpin->value());
    query.addBindValue(ui->expiryDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->batchNumberEdit->text());
    query.addBindValue(ui->supplierEdit->text());
    query.addBindValue(ui->purchasePriceSpin->value());
    
    if (m_inventoryId != -1) {
        query.addBindValue(m_inventoryId);
    }
    
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", 
                             QString("保存失败: %1").arg(query.lastError().text()));
        return;
    }
    
    QDialog::accept();
}
