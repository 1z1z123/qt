#include "departmentmodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>

DepartmentModel::DepartmentModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("departments");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "科室名称");
    setHeaderData(2, Qt::Horizontal, "描述");
    setHeaderData(3, Qt::Horizontal, "位置");
    setHeaderData(4, Qt::Horizontal, "电话");
    
    select();
}

void DepartmentModel::refresh()
{
    select();
}

QVariant DepartmentModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole && index.column() == 0) {
        return Qt::AlignCenter;
    }
    return QSqlTableModel::data(index, role);
}

