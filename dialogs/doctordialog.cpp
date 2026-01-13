#include "doctordialog.h"
#include "ui_doctordialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QVariant>

DoctorDialog::DoctorDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::DoctorDialog), m_doctorId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加医生");
    
    // 初始化性别选项
    ui->genderCombo->addItems({"男", "女"});
    
    // 设置日期编辑器
    ui->birthDateEdit->setDate(QDate::currentDate());
}

DoctorDialog::DoctorDialog(int doctorId, QWidget *parent)
    : QDialog(parent), ui(new Ui::DoctorDialog), m_doctorId(doctorId)
{
    ui->setupUi(this);
    setWindowTitle("编辑医生");
    
    // 初始化性别选项
    ui->genderCombo->addItems({"男", "女"});
    
    loadDoctorData(doctorId);
}

DoctorDialog::~DoctorDialog()
{
    delete ui;
}

void DoctorDialog::loadDoctorData(int doctorId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM doctors WHERE id = ?");
    query.addBindValue(doctorId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载医生数据");
        return;
    }
    
    ui->nameEdit->setText(query.value("name").toString());
    ui->genderCombo->setCurrentText(query.value("gender").toString());
    ui->birthDateEdit->setDate(QDate::fromString(query.value("birth_date").toString(), "yyyy-MM-dd"));
    ui->phoneEdit->setText(query.value("phone").toString());
    ui->emailEdit->setText(query.value("email").toString());
    ui->departmentIdSpin->setValue(query.value("department_id").toInt());
    ui->titleEdit->setText(query.value("title").toString());
    ui->licenseNumberEdit->setText(query.value("license_number").toString());
    ui->specializationEdit->setText(query.value("specialization").toString());
}

void DoctorDialog::accept()
{
    if (ui->nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "警告", "姓名不能为空");
        return;
    }
    
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_doctorId == -1) {
        query.prepare(R"(
            INSERT INTO doctors (name, gender, birth_date, phone, email, 
                               department_id, title, license_number, specialization)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE doctors SET name=?, gender=?, birth_date=?, phone=?, email=?,
                              department_id=?, title=?, license_number=?, specialization=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->nameEdit->text());
    query.addBindValue(ui->genderCombo->currentText().isEmpty() ? QVariant() : ui->genderCombo->currentText());
    query.addBindValue(ui->birthDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->phoneEdit->text().isEmpty() ? QVariant() : ui->phoneEdit->text());
    query.addBindValue(ui->emailEdit->text().isEmpty() ? QVariant() : ui->emailEdit->text());
    query.addBindValue(ui->departmentIdSpin->value() > 0 ? ui->departmentIdSpin->value() : QVariant());
    query.addBindValue(ui->titleEdit->text().isEmpty() ? QVariant() : ui->titleEdit->text());
    // 执业证号：如果为空，插入NULL而不是空字符串，避免违反唯一性约束
    query.addBindValue(ui->licenseNumberEdit->text().isEmpty() ? QVariant() : ui->licenseNumberEdit->text());
    query.addBindValue(ui->specializationEdit->text().isEmpty() ? QVariant() : ui->specializationEdit->text());
    
    if (m_doctorId != -1) {
        query.addBindValue(m_doctorId);
    }
    
    if (!query.exec()) {
        QString errorMsg = query.lastError().text();
        // 改进错误提示
        if (errorMsg.contains("UNIQUE constraint")) {
            if (errorMsg.contains("license_number")) {
                QMessageBox::critical(this, "错误", 
                                     "保存失败：执业证号已存在，请检查执业证号是否重复或已录入。\n\n"
                                     "提示：如果不需要执业证号，请留空即可。");
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

