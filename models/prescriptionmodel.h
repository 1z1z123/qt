#ifndef PRESCRIPTIONMODEL_H
#define PRESCRIPTIONMODEL_H

#include <QSqlTableModel>
#include <QObject>

class PrescriptionModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit PrescriptionModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // PRESCRIPTIONMODEL_H

