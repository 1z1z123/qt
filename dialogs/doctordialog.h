#ifndef DOCTORDIALOG_H
#define DOCTORDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DoctorDialog; }
QT_END_NAMESPACE

class DoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorDialog(QWidget *parent = nullptr);
    explicit DoctorDialog(int doctorId, QWidget *parent = nullptr);
    ~DoctorDialog();

private slots:
    void accept() override;
    void loadDoctorData(int doctorId);

private:
    Ui::DoctorDialog *ui;
    int m_doctorId;
};

#endif // DOCTORDIALOG_H

