#ifndef MEDICALRECORDMODEL_H
#define MEDICALRECORDMODEL_H

#include <QSqlTableModel>
#include <QObject>

class MedicalRecordModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit MedicalRecordModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // MEDICALRECORDMODEL_H

