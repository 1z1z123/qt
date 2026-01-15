#include "reportgenerator.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>

ReportGenerator::ReportGenerator(QObject *parent)
    : QObject(parent)
{
}

void ReportGenerator::generateReport(const QString &filePath)
{
    QString error;
    
    if (filePath.endsWith(".csv", Qt::CaseInsensitive)) {
        QString result = generateCSVReport(filePath);
        if (result.isEmpty()) {
            emit reportGenerated(filePath);
        } else {
            emit reportError(result);
        }
    } else {
        emit reportError("不支持的文件格式");
    }
}

QString ReportGenerator::generateCSVReport(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return QString("无法创建文件: %1").arg(filePath);
    }
    
    QTextStream out(&file);
    // Qt 6 默认使用 UTF-8 编码
    
    QSqlDatabase db = DatabaseManager::instance().database();
    
    // 写入报表头
    out << "社区医疗信息管理系统 - 数据报表\n";
    out << "生成日期: " << QDate::currentDate().toString("yyyy-MM-dd") << "\n\n";
    
    // 统计信息
    emit progressChanged(10);
    
    QSqlQuery query(db);
    int patientCount = 0, doctorCount = 0, recordCount = 0;
    
    query.exec("SELECT COUNT(*) FROM patients");
    if (query.next()) patientCount = query.value(0).toInt();
    
    query.exec("SELECT COUNT(*) FROM doctors");
    if (query.next()) doctorCount = query.value(0).toInt();
    
    query.exec("SELECT COUNT(*) FROM medical_records");
    if (query.next()) recordCount = query.value(0).toInt();
    
    out << "统计信息:\n";
    out << "病人总数," << patientCount << "\n";
    out << "医生总数," << doctorCount << "\n";
    out << "就诊记录总数," << recordCount << "\n\n";
    
    emit progressChanged(30);
    
    // 病人信息
    out << "病人信息:\n";
    out << "ID,姓名,性别,出生日期,电话,身份证号\n";
    query.exec("SELECT id, name, gender, birth_date, phone, id_card FROM patients");
    while (query.next()) {
        out << query.value(0).toString() << ","
            << query.value(1).toString() << ","
            << query.value(2).toString() << ","
            << query.value(3).toString() << ","
            << query.value(4).toString() << ","
            << query.value(5).toString() << "\n";
    }
    out << "\n";
    
    emit progressChanged(50);
    
    // 医生信息
    out << "医生信息:\n";
    out << "ID,姓名,性别,职称,专业\n";
    query.exec("SELECT id, name, gender, title, specialization FROM doctors");
    while (query.next()) {
        out << query.value(0).toString() << ","
            << query.value(1).toString() << ","
            << query.value(2).toString() << ","
            << query.value(3).toString() << ","
            << query.value(4).toString() << "\n";
    }
    out << "\n";
    
    emit progressChanged(70);
    
    // 就诊记录
    out << "就诊记录:\n";
    out << "ID,病人ID,医生ID,就诊日期,诊断\n";
    query.exec("SELECT id, patient_id, doctor_id, visit_date, diagnosis FROM medical_records");
    while (query.next()) {
        out << query.value(0).toString() << ","
            << query.value(1).toString() << ","
            << query.value(2).toString() << ","
            << query.value(3).toString() << ","
            << query.value(4).toString() << "\n";
    }
    out << "\n";
    
    emit progressChanged(90);
    
    // 药品库存预警
    out << "库存预警:\n";
    out << "药品ID,药品名称,当前库存,最低库存\n";
    query.prepare(R"(
        SELECT i.medicine_id, m.name, i.quantity, i.min_stock
        FROM inventory i
        JOIN medicines m ON i.medicine_id = m.id
        WHERE i.quantity <= i.min_stock
    )");
    query.exec();
    while (query.next()) {
        out << query.value(0).toString() << ","
            << query.value(1).toString() << ","
            << query.value(2).toString() << ","
            << query.value(3).toString() << "\n";
    }
    
    emit progressChanged(100);
    
    file.close();
    return QString();
}

