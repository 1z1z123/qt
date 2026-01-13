#include "logindialog.h"
#include "ui_logindialog.h"
#include <QKeyEvent>

const QString LoginDialog::VALID_USERNAME = "zzg666";
const QString LoginDialog::VALID_PASSWORD = "666";

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    
    // 设置窗口属性
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(400, 250);
    
    // 设置按钮样式（在代码中设置，避免UI文件格式问题）
    ui->loginButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #3498db;"
        "    color: white;"
        "    border: none;"
        "    padding: 8px 30px;"
        "    border-radius: 4px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #21618c;"
        "}"
    );
    
    ui->cancelButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #95a5a6;"
        "    color: white;"
        "    border: none;"
        "    padding: 8px 30px;"
        "    border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #7f8c8d;"
        "}"
    );
    
    // 连接信号
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &LoginDialog::reject);
    
    // 设置回车键登录
    ui->passwordEdit->installEventFilter(this);
    
    // 隐藏错误标签
    ui->errorLabel->clear();
    
    // 聚焦到用户名输入框
    ui->usernameEdit->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::accept()
{
    // 重写accept，只有在验证通过时才调用基类的accept
    if (validateLogin()) {
        QDialog::accept();
    }
}

void LoginDialog::onLoginClicked()
{
    if (validateLogin()) {
        QDialog::accept();
    }
}

bool LoginDialog::validateLogin()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    
    // 清除之前的错误信息
    ui->errorLabel->clear();
    
    if (username.isEmpty()) {
        ui->errorLabel->setText("请输入账户名");
        ui->usernameEdit->setFocus();
        return false;
    }
    
    if (password.isEmpty()) {
        ui->errorLabel->setText("请输入密码");
        ui->passwordEdit->setFocus();
        return false;
    }
    
    if (username != VALID_USERNAME || password != VALID_PASSWORD) {
        ui->errorLabel->setText("账户名或密码错误");
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
        return false;
    }
    
    // 登录成功
    return true;
}

bool LoginDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->passwordEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            onLoginClicked();
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

