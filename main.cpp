#include "mainwindow.h"
#include "databasemanager.h"
#include "dialogs/logindialog.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Qt 6默认使用UTF-8编码，无需额外设置
    
    // 显示登录对话框
    LoginDialog loginDialog;
    if (loginDialog.exec() != QDialog::Accepted) {
        // 用户取消登录，退出程序
        return 0;
    }
    
    // 登录成功后，初始化数据库
    if (!DatabaseManager::instance().initializeDatabase()) {
        QMessageBox::critical(nullptr, "数据库错误", 
                              "无法初始化数据库。程序将退出。");
        return -1;
    }
    
    // 创建并显示主窗口
    MainWindow window;
    window.show();
    
    return app.exec();
}

