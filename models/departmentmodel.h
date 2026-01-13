#ifndef DEPARTMENTMODEL_H
#define DEPARTMENTMODEL_H

#include <QSqlTableModel>
#include <QObject>

class DepartmentModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit DepartmentModel(QObject *parent = nullptr);
    void refresh();
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // DEPARTMENTMODEL_H

