#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
#include <QVariant>

PatientDialog::PatientDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::PatientDialog), m_patientId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加病人");
    
    ui->genderCombo->addItems({"男", "女"});
    ui->birthDateEdit->setDate(QDate::currentDate());
}

PatientDialog::PatientDialog(int patientId, QWidget *parent)
    : QDialog(parent), ui(new Ui::PatientDialog), m_patientId(patientId)
{
    ui->setupUi(this);
    setWindowTitle("编辑病人");
    
    ui->genderCombo->addItems({"男", "女"});
    loadPatientData(patientId);
}

PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::loadPatientData(int patientId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM patients WHERE id = ?");
    query.addBindValue(patientId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载病人数据");
        return;
    }
    
    ui->nameEdit->setText(query.value("name").toString());
    ui->genderCombo->setCurrentText(query.value("gender").toString());
    ui->birthDateEdit->setDate(QDate::fromString(query.value("birth_date").toString(), "yyyy-MM-dd"));
    ui->phoneEdit->setText(query.value("phone").toString());
    ui->emailEdit->setText(query.value("email").toString());
    ui->addressEdit->setText(query.value("address").toString());
    ui->idCardEdit->setText(query.value("id_card").toString());
    ui->medicalHistoryEdit->setPlainText(query.value("medical_history").toString());
    ui->allergyInfoEdit->setPlainText(query.value("allergy_info").toString());
    ui->emergencyContactEdit->setText(query.value("emergency_contact").toString());
    ui->emergencyPhoneEdit->setText(query.value("emergency_phone").toString());
}

void PatientDialog::accept()
{
    if (ui->nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "警告", "姓名不能为空");
        return;
    }
    
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_patientId == -1) {
        query.prepare(R"(
            INSERT INTO patients (name, gender, birth_date, phone, email, address, 
                                id_card, medical_history, allergy_info, 
                                emergency_contact, emergency_phone)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE patients SET name=?, gender=?, birth_date=?, phone=?, email=?, 
                               address=?, id_card=?, medical_history=?, allergy_info=?,
                               emergency_contact=?, emergency_phone=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->nameEdit->text());
    query.addBindValue(ui->genderCombo->currentText().isEmpty() ? QVariant() : ui->genderCombo->currentText());
    query.addBindValue(ui->birthDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->phoneEdit->text().isEmpty() ? QVariant() : ui->phoneEdit->text());
    query.addBindValue(ui->emailEdit->text().isEmpty() ? QVariant() : ui->emailEdit->text());
    query.addBindValue(ui->addressEdit->text().isEmpty() ? QVariant() : ui->addressEdit->text());
    // 身份证号：如果为空，插入NULL而不是空字符串，避免违反唯一性约束
    query.addBindValue(ui->idCardEdit->text().isEmpty() ? QVariant() : ui->idCardEdit->text());
    query.addBindValue(ui->medicalHistoryEdit->toPlainText().isEmpty() ? QVariant() : ui->medicalHistoryEdit->toPlainText());
    query.addBindValue(ui->allergyInfoEdit->toPlainText().isEmpty() ? QVariant() : ui->allergyInfoEdit->toPlainText());
    query.addBindValue(ui->emergencyContactEdit->text().isEmpty() ? QVariant() : ui->emergencyContactEdit->text());
    query.addBindValue(ui->emergencyPhoneEdit->text().isEmpty() ? QVariant() : ui->emergencyPhoneEdit->text());
    
    if (m_patientId != -1) {
        query.addBindValue(m_patientId);
    }
    
    if (!query.exec()) {
        QString errorMsg = query.lastError().text();
        // 改进错误提示
        if (errorMsg.contains("UNIQUE constraint")) {
            if (errorMsg.contains("id_card")) {
                QMessageBox::critical(this, "错误", 
                                     "保存失败：身份证号已存在，请检查身份证号是否重复或已录入。\n\n"
                                     "提示：如果不需要身份证号，请留空即可。");
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
