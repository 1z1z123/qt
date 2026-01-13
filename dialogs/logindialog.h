#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void accept() override;
    void onLoginClicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    bool validateLogin();
    
    Ui::LoginDialog *ui;
    static const QString VALID_USERNAME;
    static const QString VALID_PASSWORD;
};

#endif // LOGINDIALOG_H

