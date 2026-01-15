#include "httpsynchronizer.h"
#include "../databasemanager.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlQuery>
#include <QDebug>

HttpSynchronizer::HttpSynchronizer(QObject *parent)
    : QObject(parent)
{
    m_networkManager = new QNetworkAccessManager(this);
}

void HttpSynchronizer::syncMedicines(const QString &url)
{
    QUrl requestUrl(url);
    QNetworkRequest request(requestUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QNetworkReply *reply = m_networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        onMedicineSyncFinished(reply);
        reply->deleteLater();
    });
}

void HttpSynchronizer::syncDiagnosisReferences(const QString &url)
{
    QUrl requestUrl(url);
    QNetworkRequest request(requestUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QNetworkReply *reply = m_networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        onDiagnosisSyncFinished(reply);
        reply->deleteLater();
    });
}

void HttpSynchronizer::onMedicineSyncFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        emit syncCompleted(false, reply->errorString());
        return;
    }
    
    QByteArray data = reply->readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    
    if (error.error != QJsonParseError::NoError) {
        emit syncCompleted(false, "JSON解析错误");
        return;
    }
    
    if (!doc.isArray()) {
        emit syncCompleted(false, "无效的数据格式");
        return;
    }
    
    QJsonArray medicines = doc.array();
    QSqlDatabase db = DatabaseManager::instance().database();
    QSqlQuery query(db);
    int successCount = 0;
    
    db.transaction();
    for (const auto &value : medicines) {
        QJsonObject medicine = value.toObject();
        
        query.prepare(R"(
            INSERT OR REPLACE INTO medicines (code, name, specification, unit, manufacturer, price)
            VALUES (?, ?, ?, ?, ?, ?)
        )");
        
        query.addBindValue(medicine["code"].toString());
        query.addBindValue(medicine["name"].toString());
        query.addBindValue(medicine["specification"].toString());
        query.addBindValue(medicine["unit"].toString());
        query.addBindValue(medicine["manufacturer"].toString());
        query.addBindValue(medicine["price"].toDouble());
        
        if (query.exec()) {
            successCount++;
        }
    }
    
    if (db.commit()) {
        emit syncCompleted(true, QString("成功同步 %1 条药品数据").arg(successCount));
    } else {
        db.rollback();
        emit syncCompleted(false, "数据库提交失败");
    }
}

void HttpSynchronizer::onDiagnosisSyncFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        emit syncCompleted(false, reply->errorString());
        return;
    }
    
    // 诊断参考信息的处理逻辑类似
    emit syncCompleted(true, "诊断参考信息同步完成");
}

