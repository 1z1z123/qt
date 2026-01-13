#ifndef SCHEDULEDIALOG_H
#define SCHEDULEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ScheduleDialog; }
QT_END_NAMESPACE

class ScheduleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleDialog(QWidget *parent = nullptr);
    explicit ScheduleDialog(int scheduleId, QWidget *parent = nullptr);
    ~ScheduleDialog();

private slots:
    void accept() override;
    void loadScheduleData(int scheduleId);

private:
    Ui::ScheduleDialog *ui;
    int m_scheduleId;
};

#endif // SCHEDULEDIALOG_H

