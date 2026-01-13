#ifndef PRESCRIPTIONDIALOG_H
#define PRESCRIPTIONDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class PrescriptionDialog; }
QT_END_NAMESPACE

class PrescriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrescriptionDialog(QWidget *parent = nullptr);
    explicit PrescriptionDialog(int prescriptionId, QWidget *parent = nullptr);
    ~PrescriptionDialog();

private slots:
    void accept() override;
    void loadPrescriptionData(int prescriptionId);

private:
    Ui::PrescriptionDialog *ui;
    int m_prescriptionId;
};

#endif // PRESCRIPTIONDIALOG_H

