#include "departmentdialog.h"
#include "ui_departmentdialog.h"
#include "../databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QVariant>

DepartmentDialog::DepartmentDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::DepartmentDialog), m_departmentId(-1)
{
    ui->setupUi(this);
    setWindowTitle("添加科室");
}

DepartmentDialog::DepartmentDialog(int departmentId, QWidget *parent)
    : QDialog(parent), ui(new Ui::DepartmentDialog), m_departmentId(departmentId)
{
    ui->setupUi(this);
    setWindowTitle("编辑科室");
    loadDepartmentData(departmentId);
}

DepartmentDialog::~DepartmentDialog()
{
    delete ui;
}

void DepartmentDialog::loadDepartmentData(int departmentId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM departments WHERE id = ?");
    query.addBindValue(departmentId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "无法加载科室数据");
        return;
    }
    
    ui->nameEdit->setText(query.value("name").toString());
    ui->descriptionEdit->setPlainText(query.value("description").toString());
    ui->locationEdit->setText(query.value("location").toString());
    ui->phoneEdit->setText(query.value("phone").toString());
}

void DepartmentDialog::accept()
{
    if (ui->nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "警告", "科室名称不能为空");
        return;
    }
    
    QSqlQuery query(DatabaseManager::instance().database());
    
    if (m_departmentId == -1) {
        query.prepare("INSERT INTO departments (name, description, location, phone) VALUES (?, ?, ?, ?)");
    } else {
        query.prepare("UPDATE departments SET name=?, description=?, location=?, phone=? WHERE id=?");
    }
    
    query.addBindValue(ui->nameEdit->text());
    query.addBindValue(ui->descriptionEdit->toPlainText().isEmpty() ? QVariant() : ui->descriptionEdit->toPlainText());
    query.addBindValue(ui->locationEdit->text().isEmpty() ? QVariant() : ui->locationEdit->text());
    query.addBindValue(ui->phoneEdit->text().isEmpty() ? QVariant() : ui->phoneEdit->text());
    
    if (m_departmentId != -1) {
        query.addBindValue(m_departmentId);
    }
    
    if (!query.exec()) {
        QString errorMsg = query.lastError().text();
        // 改进错误提示
        if (errorMsg.contains("UNIQUE constraint")) {
            if (errorMsg.contains("name")) {
                QMessageBox::critical(this, "错误", 
                                     "保存失败：科室名称已存在，请使用不同的名称。");
            } else {
                QMessageBox::critical(this, "错误", 
                                     QString("保存失败：数据重复冲突。\n\n详细信息：%1").arg(errorMsg));
            }
        } else {
            QMessageBox::critical(this, "错误", 
                                 QString("保存失败：%1").arg(errorMsg));
        }
        return;
    }
    
    QDialog::accept();
}
