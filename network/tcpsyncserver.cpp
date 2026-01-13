#include "tcpsyncserver.h"
#include <QDebug>

TcpSyncServer::TcpSyncServer(QObject *parent)
    : QObject(parent)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &TcpSyncServer::onNewConnection);
}

bool TcpSyncServer::startServer(quint16 port)
{
    if (m_server->isListening()) {
        return true;
    }
    
    if (!m_server->listen(QHostAddress::Any, port)) {
        qDebug() << "无法启动TCP服务器:" << m_server->errorString();
        emit errorOccurred(m_server->errorString());
        return false;
    }
    
    qDebug() << "TCP服务器已启动，监听端口:" << port;
    return true;
}

void TcpSyncServer::stopServer()
{
    if (m_server->isListening()) {
        m_server->close();
        for (QTcpSocket *client : m_clients) {
            client->close();
        }
        m_clients.clear();
    }
}

void TcpSyncServer::onNewConnection()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    if (!client) {
        return;
    }
    
    m_clients.append(client);
    connect(client, &QTcpSocket::readyRead, this, &TcpSyncServer::onDataReceived);
    connect(client, &QTcpSocket::disconnected, this, &TcpSyncServer::onClientDisconnected);
    
    qDebug() << "新客户端连接:" << client->peerAddress().toString();
    emit clientConnected();
}

void TcpSyncServer::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (client) {
        m_clients.removeAll(client);
        client->deleteLater();
        qDebug() << "客户端断开连接";
    }
}

void TcpSyncServer::onDataReceived()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client) {
        return;
    }
    
    QByteArray data = client->readAll();
    qDebug() << "接收到数据:" << data.size() << "字节";
    emit dataReceived(data);
    
    // 可以在这里处理接收到的数据，比如同步数据库等
    // 这里简化处理，只回显
    client->write("Data received");
}

