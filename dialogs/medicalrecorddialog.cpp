#include "medicalrecorddialog.h"
#include "ui_medicalrecorddialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>

MedicalRecordDialog::MedicalRecordDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::MedicalRecordDialog), m_recordId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加就诊记录");
    ui->visitDateEdit->setDate(QDate::currentDate());
}

MedicalRecordDialog::MedicalRecordDialog(int recordId, QWidget *parent)
    : QDialog(parent), ui(new Ui::MedicalRecordDialog), m_recordId(recordId)
{
    ui->setupUi(this);
    setWindowTitle("编辑就诊记录");
    loadRecordData(recordId);
}

MedicalRecordDialog::~MedicalRecordDialog()
{
    delete ui;
}

void MedicalRecordDialog::loadRecordData(int recordId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM medical_records WHERE id = ?");
    query.addBindValue(recordId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载就诊记录数据");
        return;
    }
    
    ui->patientIdSpin->setValue(query.value("patient_id").toInt());
    ui->doctorIdSpin->setValue(query.value("doctor_id").toInt());
    ui->departmentIdSpin->setValue(query.value("department_id").toInt());
    ui->visitDateEdit->setDate(QDate::fromString(query.value("visit_date").toString(), "yyyy-MM-dd"));
    ui->chiefComplaintEdit->setPlainText(query.value("chief_complaint").toString());
    ui->diagnosisEdit->setPlainText(query.value("diagnosis").toString());
    ui->treatmentEdit->setPlainText(query.value("treatment").toString());
    ui->notesEdit->setPlainText(query.value("notes").toString());
}

void MedicalRecordDialog::accept()
{
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_recordId == -1) {
        query.prepare(R"(
            INSERT INTO medical_records (patient_id, doctor_id, department_id, visit_date,
                                       chief_complaint, diagnosis, treatment, notes)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE medical_records SET patient_id=?, doctor_id=?, department_id=?, 
                                     visit_date=?, chief_complaint=?, diagnosis=?, 
                                     treatment=?, notes=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->patientIdSpin->value());
    query.addBindValue(ui->doctorIdSpin->value());
    query.addBindValue(ui->departmentIdSpin->value());
    query.addBindValue(ui->visitDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->chiefComplaintEdit->toPlainText());
    query.addBindValue(ui->diagnosisEdit->toPlainText());
    query.addBindValue(ui->treatmentEdit->toPlainText());
    query.addBindValue(ui->notesEdit->toPlainText());
    
    if (m_recordId != -1) {
        query.addBindValue(m_recordId);
    }
    
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", 
                             QString("保存失败: %1").arg(query.lastError().text()));
        return;
    }
    
    QDialog::accept();
}
