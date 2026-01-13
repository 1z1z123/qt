#include "statisticsthread.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QDebug>

StatisticsThread::StatisticsThread(QObject *parent)
    : QThread(parent)
{
}

void StatisticsThread::run()
{
    QMap<QString, QVariant> stats = calculateStatistics();
    emit statisticsReady(stats);
}

QMap<QString, QVariant> StatisticsThread::calculateStatistics()
{
    QMap<QString, QVariant> stats;
    QSqlDatabase db = DatabaseManager::instance().database();
    QSqlQuery query(db);
    
    // 统计病人数
    query.exec("SELECT COUNT(*) FROM patients");
    if (query.next()) {
        stats["patients"] = query.value(0).toInt();
    }
    
    // 统计医生数
    query.exec("SELECT COUNT(*) FROM doctors");
    if (query.next()) {
        stats["doctors"] = query.value(0).toInt();
    }
    
    // 统计科室数
    query.exec("SELECT COUNT(*) FROM departments");
    if (query.next()) {
        stats["departments"] = query.value(0).toInt();
    }
    
    // 统计就诊记录数
    query.exec("SELECT COUNT(*) FROM medical_records");
    if (query.next()) {
        stats["medical_records"] = query.value(0).toInt();
    }
    
    // 统计处方数
    query.exec("SELECT COUNT(*) FROM prescriptions");
    if (query.next()) {
        stats["prescriptions"] = query.value(0).toInt();
    }
    
    // 统计药品数
    query.exec("SELECT COUNT(*) FROM medicines");
    if (query.next()) {
        stats["medicines"] = query.value(0).toInt();
    }
    
    // 统计预约数
    query.exec("SELECT COUNT(*) FROM appointments");
    if (query.next()) {
        stats["appointments"] = query.value(0).toInt();
    }
    
    // 统计排班数
    query.exec("SELECT COUNT(*) FROM schedules");
    if (query.next()) {
        stats["schedules"] = query.value(0).toInt();
    }
    
    // 统计今日预约数
    query.prepare("SELECT COUNT(*) FROM appointments WHERE appointment_date = date('now')");
    query.exec();
    if (query.next()) {
        stats["today_appointments"] = query.value(0).toInt();
    }
    
    // 统计低库存药品数
    query.prepare(R"(
        SELECT COUNT(*) FROM inventory 
        WHERE quantity <= min_stock
    )");
    query.exec();
    if (query.next()) {
        stats["low_stock_medicines"] = query.value(0).toInt();
    }
    
    return stats;
}

