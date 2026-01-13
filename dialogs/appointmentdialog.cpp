#include "appointmentdialog.h"
#include "ui_appointmentdialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
#include <QTime>

AppointmentDialog::AppointmentDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AppointmentDialog), m_appointmentId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加预约");
    ui->appointmentDateEdit->setDate(QDate::currentDate());
    ui->appointmentTimeEdit->setTime(QTime::currentTime());
    ui->statusCombo->addItems({"pending", "confirmed", "completed", "cancelled"});
}

AppointmentDialog::AppointmentDialog(int appointmentId, QWidget *parent)
    : QDialog(parent), ui(new Ui::AppointmentDialog), m_appointmentId(appointmentId)
{
    ui->setupUi(this);
    setWindowTitle("编辑预约");
    ui->statusCombo->addItems({"pending", "confirmed", "completed", "cancelled"});
    loadAppointmentData(appointmentId);
}

AppointmentDialog::~AppointmentDialog()
{
    delete ui;
}

void AppointmentDialog::loadAppointmentData(int appointmentId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM appointments WHERE id = ?");
    query.addBindValue(appointmentId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载预约数据");
        return;
    }
    
    ui->patientIdSpin->setValue(query.value("patient_id").toInt());
    ui->doctorIdSpin->setValue(query.value("doctor_id").toInt());
    ui->appointmentDateEdit->setDate(QDate::fromString(query.value("appointment_date").toString(), "yyyy-MM-dd"));
    ui->appointmentTimeEdit->setTime(QTime::fromString(query.value("appointment_time").toString(), "hh:mm:ss"));
    ui->statusCombo->setCurrentText(query.value("status").toString());
    ui->reasonEdit->setPlainText(query.value("reason").toString());
    ui->notesEdit->setPlainText(query.value("notes").toString());
}

void AppointmentDialog::accept()
{
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_appointmentId == -1) {
        query.prepare(R"(
            INSERT INTO appointments (patient_id, doctor_id, appointment_date, appointment_time,
                                    status, reason, notes)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE appointments SET patient_id=?, doctor_id=?, appointment_date=?, 
                                  appointment_time=?, status=?, reason=?, notes=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->patientIdSpin->value());
    query.addBindValue(ui->doctorIdSpin->value());
    query.addBindValue(ui->appointmentDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->appointmentTimeEdit->time().toString("hh:mm:ss"));
    query.addBindValue(ui->statusCombo->currentText());
    query.addBindValue(ui->reasonEdit->toPlainText());
    query.addBindValue(ui->notesEdit->toPlainText());
    
    if (m_appointmentId != -1) {
        query.addBindValue(m_appointmentId);
    }
    
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", 
                             QString("保存失败: %1").arg(query.lastError().text()));
        return;
    }
    
    QDialog::accept();
}
