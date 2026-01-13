#include "doctormodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>

DoctorModel::DoctorModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("doctors");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "姓名");
    setHeaderData(2, Qt::Horizontal, "性别");
    setHeaderData(3, Qt::Horizontal, "出生日期");
    setHeaderData(4, Qt::Horizontal, "电话");
    setHeaderData(5, Qt::Horizontal, "邮箱");
    setHeaderData(6, Qt::Horizontal, "科室ID");
    setHeaderData(7, Qt::Horizontal, "职称");
    setHeaderData(8, Qt::Horizontal, "执业证号");
    setHeaderData(9, Qt::Horizontal, "专业");
    
    select();
}

void DoctorModel::refresh()
{
    select();
}

QVariant DoctorModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole && index.column() == 0) {
        return Qt::AlignCenter;
    }
    return QSqlTableModel::data(index, role);
}

