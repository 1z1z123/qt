#ifndef INVENTORYDIALOG_H
#define INVENTORYDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class InventoryDialog; }
QT_END_NAMESPACE

class InventoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryDialog(QWidget *parent = nullptr);
    explicit InventoryDialog(int inventoryId, QWidget *parent = nullptr);
    ~InventoryDialog();

private slots:
    void accept() override;
    void loadInventoryData(int inventoryId);

private:
    Ui::InventoryDialog *ui;
    int m_inventoryId;
};

#endif // INVENTORYDIALOG_H

