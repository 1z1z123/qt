#ifndef APPOINTMENTDIALOG_H
#define APPOINTMENTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AppointmentDialog; }
QT_END_NAMESPACE

class AppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppointmentDialog(QWidget *parent = nullptr);
    explicit AppointmentDialog(int appointmentId, QWidget *parent = nullptr);
    ~AppointmentDialog();

private slots:
    void accept() override;
    void loadAppointmentData(int appointmentId);

private:
    Ui::AppointmentDialog *ui;
    int m_appointmentId;
};

#endif // APPOINTMENTDIALOG_H

