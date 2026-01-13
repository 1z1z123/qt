#include "medicinedialog.h"
#include "ui_medicinedialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QVariant>

MedicineDialog::MedicineDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::MedicineDialog), m_medicineId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加药品");
}

MedicineDialog::MedicineDialog(int medicineId, QWidget *parent)
    : QDialog(parent), ui(new Ui::MedicineDialog), m_medicineId(medicineId)
{
    ui->setupUi(this);
    setWindowTitle("编辑药品");
    loadMedicineData(medicineId);
}

MedicineDialog::~MedicineDialog()
{
    delete ui;
}

void MedicineDialog::loadMedicineData(int medicineId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM medicines WHERE id = ?");
    query.addBindValue(medicineId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载药品数据");
        return;
    }
    
    ui->nameEdit->setText(query.value("name").toString());
    ui->codeEdit->setText(query.value("code").toString());
    ui->specificationEdit->setText(query.value("specification").toString());
    ui->unitEdit->setText(query.value("unit").toString());
    ui->manufacturerEdit->setText(query.value("manufacturer").toString());
    ui->priceSpin->setValue(query.value("price").toDouble());
    ui->descriptionEdit->setPlainText(query.value("description").toString());
}

void MedicineDialog::accept()
{
    if (ui->nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "警告", "药品名称不能为空");
        return;
    }
    
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_medicineId == -1) {
        query.prepare(R"(
            INSERT INTO medicines (name, code, specification, unit, manufacturer, price, description)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE medicines SET name=?, code=?, specification=?, unit=?, 
                               manufacturer=?, price=?, description=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->nameEdit->text());
    // 药品编码：如果为空，插入NULL而不是空字符串，避免违反唯一性约束
    query.addBindValue(ui->codeEdit->text().isEmpty() ? QVariant() : ui->codeEdit->text());
    query.addBindValue(ui->specificationEdit->text().isEmpty() ? QVariant() : ui->specificationEdit->text());
    query.addBindValue(ui->unitEdit->text().isEmpty() ? QVariant() : ui->unitEdit->text());
    query.addBindValue(ui->manufacturerEdit->text().isEmpty() ? QVariant() : ui->manufacturerEdit->text());
    query.addBindValue(ui->priceSpin->value());
    query.addBindValue(ui->descriptionEdit->toPlainText().isEmpty() ? QVariant() : ui->descriptionEdit->toPlainText());
    
    if (m_medicineId != -1) {
        query.addBindValue(m_medicineId);
    }
    
    if (!query.exec()) {
        QString errorMsg = query.lastError().text();
        // 改进错误提示
        if (errorMsg.contains("UNIQUE constraint")) {
            if (errorMsg.contains("code")) {
                QMessageBox::critical(this, "错误", 
                                     "保存失败：药品编码已存在，请检查编码是否重复。\n\n"
                                     "提示：如果不需要编码，请留空即可。");
            } else {
                QMessageBox::critical(this, "错误", 
                                     QString("保存失败：数据重复冲突。\n\n详细信息：%1").arg(errorMsg));
            }
        } else {
            QMessageBox::critical(this, "错误", 
                                 QString("保存失败：%1").arg(errorMsg));
        }
        return;
    }
    
    QDialog::accept();
}
