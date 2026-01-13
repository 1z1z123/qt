#include "inventorymodel.h"
#include "../databasemanager.h"
#include <QSqlError>
#include <QDebug>
#include <QColor>
#include <QVariant>

InventoryModel::InventoryModel(QObject *parent)
    : QSqlTableModel(parent, DatabaseManager::instance().database())
{
    setTable("inventory");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "药品ID");
    setHeaderData(2, Qt::Horizontal, "库存数量");
    setHeaderData(3, Qt::Horizontal, "最低库存");
    setHeaderData(4, Qt::Horizontal, "最高库存");
    setHeaderData(5, Qt::Horizontal, "过期日期");
    setHeaderData(6, Qt::Horizontal, "批次号");
    setHeaderData(7, Qt::Horizontal, "供应商");
    setHeaderData(8, Qt::Horizontal, "采购价格");
    
    select();
}

void InventoryModel::refresh()
{
    select();
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::BackgroundRole) {
        // 如果库存低于最低库存，显示红色背景
        if (index.column() == 2) {
            int quantity = QSqlTableModel::data(index).toInt();
            int minStock = QSqlTableModel::data(this->index(index.row(), 3)).toInt();
            if (quantity < minStock) {
                return QColor(255, 200, 200);
            }
        }
    }
    
    if (role == Qt::TextAlignmentRole) {
        if (index.column() == 0) {
            return QVariant(Qt::AlignCenter);
        } else if (index.column() == 2 || index.column() == 3 || 
                   index.column() == 4 || index.column() == 8) {
            return QVariant(Qt::AlignRight | Qt::AlignVCenter);
        }
    }
    
    return QSqlTableModel::data(index, role);
}

