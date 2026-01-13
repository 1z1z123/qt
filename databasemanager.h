#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QObject>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    static DatabaseManager& instance();
    bool initializeDatabase();
    QSqlDatabase database() const { return m_database; }

private:
    DatabaseManager();
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    void createTables();
    void fixExistingTables();  // 修复已存在表中的数据问题
    bool createPatientsTable();
    bool createDoctorsTable();
    bool createDepartmentsTable();
    bool createMedicalRecordsTable();
    bool createPrescriptionsTable();
    bool createMedicinesTable();
    bool createInventoryTable();
    bool createAppointmentsTable();
    bool createSchedulesTable();

    QSqlDatabase m_database;
    QString m_databasePath;
};

#endif // DATABASEMANAGER_H

