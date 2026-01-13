#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QSqlTableModel>
#include <QObject>

class ScheduleModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit ScheduleModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // SCHEDULEMODEL_H

