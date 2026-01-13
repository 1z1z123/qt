#include "scheduledialog.h"
#include "ui_scheduledialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
#include <QTime>

ScheduleDialog::ScheduleDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ScheduleDialog), m_scheduleId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加排班");
    ui->scheduleDateEdit->setDate(QDate::currentDate());
    ui->startTimeEdit->setTime(QTime(9, 0));
    ui->endTimeEdit->setTime(QTime(17, 0));
    ui->statusCombo->addItems({"available", "full", "closed"});
}

ScheduleDialog::ScheduleDialog(int scheduleId, QWidget *parent)
    : QDialog(parent), ui(new Ui::ScheduleDialog), m_scheduleId(scheduleId)
{
    ui->setupUi(this);
    setWindowTitle("编辑排班");
    ui->statusCombo->addItems({"available", "full", "closed"});
    loadScheduleData(scheduleId);
}

ScheduleDialog::~ScheduleDialog()
{
    delete ui;
}

void ScheduleDialog::loadScheduleData(int scheduleId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM schedules WHERE id = ?");
    query.addBindValue(scheduleId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载排班数据");
        return;
    }
    
    ui->doctorIdSpin->setValue(query.value("doctor_id").toInt());
    ui->scheduleDateEdit->setDate(QDate::fromString(query.value("schedule_date").toString(), "yyyy-MM-dd"));
    ui->startTimeEdit->setTime(QTime::fromString(query.value("start_time").toString(), "hh:mm:ss"));
    ui->endTimeEdit->setTime(QTime::fromString(query.value("end_time").toString(), "hh:mm:ss"));
    ui->maxAppointmentsSpin->setValue(query.value("max_appointments").toInt());
    ui->currentAppointmentsSpin->setValue(query.value("current_appointments").toInt());
    ui->statusCombo->setCurrentText(query.value("status").toString());
    ui->notesEdit->setPlainText(query.value("notes").toString());
}

void ScheduleDialog::accept()
{
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_scheduleId == -1) {
        query.prepare(R"(
            INSERT INTO schedules (doctor_id, schedule_date, start_time, end_time,
                                 max_appointments, current_appointments, status, notes)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?)
        )");
    } else {
        query.prepare(R"(
            UPDATE schedules SET doctor_id=?, schedule_date=?, start_time=?, end_time=?,
                               max_appointments=?, current_appointments=?, status=?, notes=?
            WHERE id=?
        )");
    }
    
    query.addBindValue(ui->doctorIdSpin->value());
    query.addBindValue(ui->scheduleDateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(ui->startTimeEdit->time().toString("hh:mm:ss"));
    query.addBindValue(ui->endTimeEdit->time().toString("hh:mm:ss"));
    query.addBindValue(ui->maxAppointmentsSpin->value());
    query.addBindValue(ui->currentAppointmentsSpin->value());
    query.addBindValue(ui->statusCombo->currentText());
    query.addBindValue(ui->notesEdit->toPlainText());
    
    if (m_scheduleId != -1) {
        query.addBindValue(m_scheduleId);
    }
    
    if (!query.exec()) {
        QMessageBox::critical(this, "错误", 
                             QString("保存失败: %1").arg(query.lastError().text()));
        return;
    }
    
    QDialog::accept();
}
