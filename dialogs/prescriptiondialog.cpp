#include "prescriptiondialog.h"
#include "ui_prescriptiondialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>

PrescriptionDialog::PrescriptionDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::PrescriptionDialog), m_prescriptionId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加处方");
}

PrescriptionDialog::PrescriptionDialog(int prescriptionId, QWidget *parent)
    : QDialog(parent), ui(new Ui::PrescriptionDialog), m_prescriptionId(prescriptionId)
{
    ui->setupUi(this);
    setWindowTitle("编辑处方");
    loadPrescriptionData(prescriptionId);
}

PrescriptionDialog::~PrescriptionDialog()
{
    delete ui;
}

void PrescriptionDialog::loadPrescriptionData(int prescriptionId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM prescriptions WHERE id = ?");
    query.addBindValue(prescriptionId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载处方数据");
        return;
    }
    
    ui->medicalRecordIdSpin->setValue(query.value("medical_record_id").toInt());
    ui->medicineIdSpin->setValue(query.value("medicine_id").toInt());
    ui->quantitySpin->setValue(query.value("quantity").toInt());
    ui->dosageEdit->setText(query.value("dosage").toString());
    ui->frequencyEdit->setText(query.value("frequency").toString());
    ui->durationEdit->setText(query.value("duration").toString());
    ui->instructionsEdit->setPlainText(query.value("instructions").toString());
}

void PrescriptionDialog::accept()
{
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_prescriptionId == -1) {
        query.prepare(R"(
            INSERT INTO prescriptions (medical_record_id, medicine_id, quantity,
                                     dosage, frequency, duration, instructions)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE prescriptions SET medical_record_id=?, medicine_id=?, quantity=?,
                                   dosage=?, frequency=?, duration=?, instructions=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->medicalRecordIdSpin->value());
    query.addBindValue(ui->medicineIdSpin->value());
    query.addBindValue(ui->quantitySpin->value());
    query.addBindValue(ui->dosageEdit->text());
    query.addBindValue(ui->frequencyEdit->text());
    query.addBindValue(ui->durationEdit->text());
    query.addBindValue(ui->instructionsEdit->toPlainText());
    
    if (m_prescriptionId != -1) {
        query.addBindValue(m_prescriptionId);
    }
    
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", 
                             QString("保存失败: %1").arg(query.lastError().text()));
        return;
    }
    
    QDialog::accept();
}
