#include "networkmanager.h"
#include "../databasemanager.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent)
{
    m_networkManager = new QNetworkAccessManager(this);
    m_syncUrl = "http://localhost:8080/api/sync";
    m_backupUrl = "http://localhost:8080/api/backup";
}

NetworkManager::~NetworkManager()
{
}

NetworkManager& NetworkManager::instance()
{
    static NetworkManager instance;
    return instance;
}

void NetworkManager::syncData()
{
    QUrl syncUrl(m_syncUrl);
    QNetworkRequest request(syncUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QJsonObject json;
    json["action"] = "sync";
    json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    
    QJsonDocument doc(json);
    QNetworkReply *reply = m_networkManager->post(request, doc.toJson());
    
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        onSyncFinished(reply);
        reply->deleteLater();
    });
}

void NetworkManager::onSyncFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "同步失败:" << reply->errorString();
        emit syncCompleted(false);
        return;
    }
    
    QByteArray data = reply->readAll();
    qDebug() << "同步完成:" << data;
    emit syncCompleted(true);
}

void NetworkManager::backupDatabase(const QString &filePath)
{
    // 在实际应用中，这里应该上传数据库文件到服务器
    // 这里简化处理，仅做本地备份
    QFile dbFile(DatabaseManager::instance().database().databaseName());
    if (dbFile.exists()) {
        QFile::copy(dbFile.fileName(), filePath);
        emit backupCompleted(true);
    } else {
        emit backupCompleted(false);
    }
}

void NetworkManager::onBackupFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "备份失败:" << reply->errorString();
        emit backupCompleted(false);
        return;
    }
    
    qDebug() << "备份完成";
    emit backupCompleted(true);
}

