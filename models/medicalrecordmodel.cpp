#include "medicalrecordmodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>

MedicalRecordModel::MedicalRecordModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("medical_records");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "病人ID");
    setHeaderData(2, Qt::Horizontal, "医生ID");
    setHeaderData(3, Qt::Horizontal, "科室ID");
    setHeaderData(4, Qt::Horizontal, "就诊日期");
    setHeaderData(5, Qt::Horizontal, "主诉");
    setHeaderData(6, Qt::Horizontal, "诊断");
    setHeaderData(7, Qt::Horizontal, "治疗方案");
    
    select();
}

void MedicalRecordModel::refresh()
{
    select();
}

QVariant MedicalRecordModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole && index.column() == 0) {
        return Qt::AlignCenter;
    }
    return QSqlTableModel::data(index, role);
}

