#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class PatientDialog; }
QT_END_NAMESPACE

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = nullptr);
    explicit PatientDialog(int patientId, QWidget *parent = nullptr);
    ~PatientDialog();

private slots:
    void accept() override;
    void loadPatientData(int patientId);

private:
    Ui::PatientDialog *ui;
    int m_patientId;
};

#endif // PATIENTDIALOG_H

