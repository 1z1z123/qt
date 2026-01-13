#include "prescriptionmodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>

PrescriptionModel::PrescriptionModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("prescriptions");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "就诊记录ID");
    setHeaderData(2, Qt::Horizontal, "药品ID");
    setHeaderData(3, Qt::Horizontal, "数量");
    setHeaderData(4, Qt::Horizontal, "用法");
    setHeaderData(5, Qt::Horizontal, "频次");
    setHeaderData(6, Qt::Horizontal, "疗程");
    setHeaderData(7, Qt::Horizontal, "说明");
    
    select();
}

void PrescriptionModel::refresh()
{
    select();
}

QVariant PrescriptionModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole && (index.column() == 0 || index.column() == 3)) {
        return Qt::AlignCenter;
    }
    return QSqlTableModel::data(index, role);
}

