#ifndef APPOINTMENTMODEL_H
#define APPOINTMENTMODEL_H

#include <QSqlTableModel>
#include <QObject>

class AppointmentModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit AppointmentModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // APPOINTMENTMODEL_H

