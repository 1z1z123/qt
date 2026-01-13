#include "databasemanager.h"
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QApplication>

DatabaseManager::DatabaseManager()
{
    // 设置数据库路径，存储在应用程序数据目录
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir;
    if (!dir.exists(dataPath)) {
        dir.mkpath(dataPath);
    }
    m_databasePath = dataPath + "/medical_system.db";
}

DatabaseManager::~DatabaseManager()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::initializeDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(m_databasePath);

    if (!m_database.open()) {
        qDebug() << "无法打开数据库:" << m_database.lastError().text();
        return false;
    }

    createTables();
    return true;
}

void DatabaseManager::createTables()
{
    // 首先尝试修复已存在的表（如果需要）
    fixExistingTables();
    
    createDepartmentsTable();
    createDoctorsTable();
    createPatientsTable();
    createMedicinesTable();
    createInventoryTable();
    createMedicalRecordsTable();
    createPrescriptionsTable();
    createAppointmentsTable();
    createSchedulesTable();
}

void DatabaseManager::fixExistingTables()
{
    // 修复已存在的表，将空字符串的唯一性字段更新为NULL
    QSqlQuery query(m_database);
    
    // 修复病人表中的空身份证号
    query.exec("UPDATE patients SET id_card = NULL WHERE id_card = ''");
    
    // 修复医生表中的空执业证号
    query.exec("UPDATE doctors SET license_number = NULL WHERE license_number = ''");
    
    // 修复药品表中的空编码
    query.exec("UPDATE medicines SET code = NULL WHERE code = ''");
}

bool DatabaseManager::createDepartmentsTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS departments (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL UNIQUE,
            description TEXT,
            location TEXT,
            phone TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime'))
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建科室表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "科室表创建成功";
    return true;
}

bool DatabaseManager::createDoctorsTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS doctors (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            gender TEXT,
            birth_date TEXT,
            phone TEXT,
            email TEXT,
            department_id INTEGER,
            title TEXT,
            license_number TEXT UNIQUE,
            specialization TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime')),
            FOREIGN KEY (department_id) REFERENCES departments(id)
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建医生表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "医生表创建成功";
    return true;
}

bool DatabaseManager::createPatientsTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS patients (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            gender TEXT,
            birth_date TEXT,
            phone TEXT,
            email TEXT,
            address TEXT,
            id_card TEXT UNIQUE,
            medical_history TEXT,
            allergy_info TEXT,
            emergency_contact TEXT,
            emergency_phone TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime'))
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建病人表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "病人表创建成功";
    return true;
}

bool DatabaseManager::createMedicinesTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS medicines (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            code TEXT UNIQUE,
            specification TEXT,
            unit TEXT,
            manufacturer TEXT,
            price REAL DEFAULT 0.0,
            description TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime'))
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建药品表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "药品表创建成功";
    return true;
}

bool DatabaseManager::createInventoryTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS inventory (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            medicine_id INTEGER NOT NULL,
            quantity INTEGER DEFAULT 0,
            min_stock INTEGER DEFAULT 0,
            max_stock INTEGER DEFAULT 0,
            expiry_date TEXT,
            batch_number TEXT,
            supplier TEXT,
            purchase_price REAL,
            last_updated TEXT DEFAULT (datetime('now', 'localtime')),
            FOREIGN KEY (medicine_id) REFERENCES medicines(id)
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建库存表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "库存表创建成功";
    return true;
}

bool DatabaseManager::createMedicalRecordsTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS medical_records (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            patient_id INTEGER NOT NULL,
            doctor_id INTEGER NOT NULL,
            department_id INTEGER,
            visit_date TEXT NOT NULL,
            chief_complaint TEXT,
            diagnosis TEXT,
            treatment TEXT,
            notes TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime')),
            FOREIGN KEY (patient_id) REFERENCES patients(id),
            FOREIGN KEY (doctor_id) REFERENCES doctors(id),
            FOREIGN KEY (department_id) REFERENCES departments(id)
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建就诊记录表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "就诊记录表创建成功";
    return true;
}

bool DatabaseManager::createPrescriptionsTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS prescriptions (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            medical_record_id INTEGER NOT NULL,
            medicine_id INTEGER NOT NULL,
            quantity INTEGER NOT NULL,
            dosage TEXT,
            frequency TEXT,
            duration TEXT,
            instructions TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime')),
            FOREIGN KEY (medical_record_id) REFERENCES medical_records(id),
            FOREIGN KEY (medicine_id) REFERENCES medicines(id)
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建处方表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "处方表创建成功";
    return true;
}

bool DatabaseManager::createAppointmentsTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS appointments (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            patient_id INTEGER NOT NULL,
            doctor_id INTEGER NOT NULL,
            appointment_date TEXT NOT NULL,
            appointment_time TEXT NOT NULL,
            status TEXT DEFAULT 'pending',
            reason TEXT,
            notes TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime')),
            FOREIGN KEY (patient_id) REFERENCES patients(id),
            FOREIGN KEY (doctor_id) REFERENCES doctors(id)
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建预约表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "预约表创建成功";
    return true;
}

bool DatabaseManager::createSchedulesTable()
{
    QSqlQuery query(m_database);
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS schedules (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            doctor_id INTEGER NOT NULL,
            schedule_date TEXT NOT NULL,
            start_time TEXT NOT NULL,
            end_time TEXT NOT NULL,
            max_appointments INTEGER DEFAULT 20,
            current_appointments INTEGER DEFAULT 0,
            status TEXT DEFAULT 'available',
            notes TEXT,
            created_at TEXT DEFAULT (datetime('now', 'localtime')),
            FOREIGN KEY (doctor_id) REFERENCES doctors(id),
            UNIQUE(doctor_id, schedule_date, start_time)
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "创建排班表失败:" << query.lastError().text();
        return false;
    }
    qDebug() << "排班表创建成功";
    return true;
}

