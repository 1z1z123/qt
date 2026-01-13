#include "medicinemodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>
#include <QVariant>

MedicineModel::MedicineModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("medicines");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "药品名称");
    setHeaderData(2, Qt::Horizontal, "编码");
    setHeaderData(3, Qt::Horizontal, "规格");
    setHeaderData(4, Qt::Horizontal, "单位");
    setHeaderData(5, Qt::Horizontal, "生产厂家");
    setHeaderData(6, Qt::Horizontal, "价格");
    setHeaderData(7, Qt::Horizontal, "描述");
    
    select();
}

void MedicineModel::refresh()
{
    select();
}

QVariant MedicineModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole) {
        if (index.column() == 0) {
            return QVariant(Qt::AlignCenter);
        } else if (index.column() == 6) {
            return QVariant(Qt::AlignRight | Qt::AlignVCenter);
        }
    }
    return QSqlTableModel::data(index, role);
}

