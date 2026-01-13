#include "appointmentmodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>
#include <QColor>

AppointmentModel::AppointmentModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("appointments");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "病人ID");
    setHeaderData(2, Qt::Horizontal, "医生ID");
    setHeaderData(3, Qt::Horizontal, "预约日期");
    setHeaderData(4, Qt::Horizontal, "预约时间");
    setHeaderData(5, Qt::Horizontal, "状态");
    setHeaderData(6, Qt::Horizontal, "原因");
    
    select();
}

void AppointmentModel::refresh()
{
    select();
}

QVariant AppointmentModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::BackgroundRole && index.column() == 5) {
        QString status = QSqlTableModel::data(index).toString();
        if (status == "completed") {
            return QColor(200, 255, 200);
        } else if (status == "cancelled") {
            return QColor(255, 200, 200);
        }
    }
    
    if (role == Qt::TextAlignmentRole && index.column() == 0) {
        return Qt::AlignCenter;
    }
    
    return QSqlTableModel::data(index, role);
}

