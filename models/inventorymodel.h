#ifndef INVENTORYMODEL_H
#define INVENTORYMODEL_H

#include <QSqlTableModel>
#include <QObject>

class InventoryModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit InventoryModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // INVENTORYMODEL_H

