#include "schedulemodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>
#include <QColor>

ScheduleModel::ScheduleModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("schedules");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "医生ID");
    setHeaderData(2, Qt::Horizontal, "排班日期");
    setHeaderData(3, Qt::Horizontal, "开始时间");
    setHeaderData(4, Qt::Horizontal, "结束时间");
    setHeaderData(5, Qt::Horizontal, "最大预约数");
    setHeaderData(6, Qt::Horizontal, "当前预约数");
    setHeaderData(7, Qt::Horizontal, "状态");
    
    select();
}

void ScheduleModel::refresh()
{
    select();
}

QVariant ScheduleModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::BackgroundRole && index.column() == 7) {
        QString status = QSqlTableModel::data(index).toString();
        if (status == "available") {
            return QColor(200, 255, 200);
        } else if (status == "full") {
            return QColor(255, 200, 200);
        }
    }
    
    if (role == Qt::TextAlignmentRole) {
        if (index.column() == 0 || index.column() == 1 || index.column() == 5 || index.column() == 6) {
            return Qt::AlignCenter;
        }
    }
    
    return QSqlTableModel::data(index, role);
}

