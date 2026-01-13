#ifndef MEDICINEDIALOG_H
#define MEDICINEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MedicineDialog; }
QT_END_NAMESPACE

class MedicineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MedicineDialog(QWidget *parent = nullptr);
    explicit MedicineDialog(int medicineId, QWidget *parent = nullptr);
    ~MedicineDialog();

private slots:
    void accept() override;
    void loadMedicineData(int medicineId);

private:
    Ui::MedicineDialog *ui;
    int m_medicineId;
};

#endif // MEDICINEDIALOG_H

