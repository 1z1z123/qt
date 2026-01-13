#include "patientmodel.h"
#include "../databasemanager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

PatientModel::PatientModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("patients");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "姓名");
    setHeaderData(2, Qt::Horizontal, "性别");
    setHeaderData(3, Qt::Horizontal, "出生日期");
    setHeaderData(4, Qt::Horizontal, "电话");
    setHeaderData(5, Qt::Horizontal, "邮箱");
    setHeaderData(6, Qt::Horizontal, "地址");
    setHeaderData(7, Qt::Horizontal, "身份证号");
    setHeaderData(8, Qt::Horizontal, "病史");
    setHeaderData(9, Qt::Horizontal, "过敏信息");
    
    select();
}

void PatientModel::refresh()
{
    select();
}

QVariant PatientModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole && index.column() == 0) {
        return Qt::AlignCenter;
    }
    return QSqlTableModel::data(index, role);
}

