#ifndef DOCTORMODEL_H
#define DOCTORMODEL_H

#include <QSqlTableModel>
#include <QObject>

class DoctorModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit DoctorModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // DOCTORMODEL_H

