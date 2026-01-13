#ifndef DEPARTMENTDIALOG_H
#define DEPARTMENTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentDialog; }
QT_END_NAMESPACE

class DepartmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepartmentDialog(QWidget *parent = nullptr);
    explicit DepartmentDialog(int departmentId, QWidget *parent = nullptr);
    ~DepartmentDialog();

private slots:
    void accept() override;
    void loadDepartmentData(int departmentId);

private:
    Ui::DepartmentDialog *ui;
    int m_departmentId;
};

#endif // DEPARTMENTDIALOG_H

