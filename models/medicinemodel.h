#ifndef MEDICINEMODEL_H
#define MEDICINEMODEL_H

#include <QSqlTableModel>
#include <QObject>

class MedicineModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit MedicineModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // MEDICINEMODEL_H

