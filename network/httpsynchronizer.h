#ifndef HTTPSYNCHRONIZER_H
#define HTTPSYNCHRONIZER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HttpSynchronizer : public QObject
{
    Q_OBJECT

public:
    explicit HttpSynchronizer(QObject *parent = nullptr);
    
    void syncMedicines(const QString &url);
    void syncDiagnosisReferences(const QString &url);

signals:
    void syncCompleted(bool success, const QString &message);
    void progressChanged(int percentage);

private slots:
    void onMedicineSyncFinished(QNetworkReply *reply);
    void onDiagnosisSyncFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_networkManager;
};

#endif // HTTPSYNCHRONIZER_H

