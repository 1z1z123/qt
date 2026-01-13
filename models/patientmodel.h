#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QSqlTableModel>
#include <QObject>

class PatientModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit PatientModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // PATIENTMODEL_H

