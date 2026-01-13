#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class NetworkManager : public QObject
{
    Q_OBJECT

public:
    static NetworkManager& instance();
    void syncData();
    void backupDatabase(const QString &filePath);

private slots:
    void onSyncFinished(QNetworkReply *reply);
    void onBackupFinished(QNetworkReply *reply);

signals:
    void syncCompleted(bool success);
    void backupCompleted(bool success);

private:
    NetworkManager(QObject *parent = nullptr);
    ~NetworkManager();
    NetworkManager(const NetworkManager&) = delete;
    NetworkManager& operator=(const NetworkManager&) = delete;
    
    QNetworkAccessManager *m_networkManager;
    QString m_syncUrl;
    QString m_backupUrl;
};

#endif // NETWORKMANAGER_H

