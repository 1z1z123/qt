#ifndef TCPSYNCSERVER_H
#define TCPSYNCSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class TcpSyncServer : public QObject
{
    Q_OBJECT

public:
    explicit TcpSyncServer(QObject *parent = nullptr);
    bool startServer(quint16 port = 8888);
    void stopServer();

signals:
    void clientConnected();
    void dataReceived(const QByteArray &data);
    void errorOccurred(const QString &error);

private slots:
    void onNewConnection();
    void onClientDisconnected();
    void onDataReceived();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
};

#endif // TCPSYNCSERVER_H

