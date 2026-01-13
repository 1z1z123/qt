#ifndef MEDICALRECORDDIALOG_H
#define MEDICALRECORDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MedicalRecordDialog; }
QT_END_NAMESPACE

class MedicalRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MedicalRecordDialog(QWidget *parent = nullptr);
    explicit MedicalRecordDialog(int recordId, QWidget *parent = nullptr);
    ~MedicalRecordDialog();

private slots:
    void accept() override;
    void loadRecordData(int recordId);

private:
    Ui::MedicalRecordDialog *ui;
    int m_recordId;
};

#endif // MEDICALRECORDDIALOG_H

