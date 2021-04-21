#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H


#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QObject>
#include <iostream>
#include <QtCore/QCoreApplication>
#include <QThread>

class WebSocketServer;



class WebSocketServer: public QObject{
    Q_OBJECT

public:
    explicit WebSocketServer(QString targetDir);
    ~WebSocketServer() override;

signals:
    void closed();

private slots:
    void NewConnection();
    void ProcessTextMessage(const QString& message);
    void RecieveFile(const QByteArray& message);
    void SocketDisconnected();

private:
    QString targetDir;
    QWebSocketServer *Web_socket_server;
    QList<QWebSocket *> clients;
    QWebSocket *aSocket;
    QString token;
    QString filename;
    QString hash;
    QString funHash; // хэш получаемый из хэш функции
    bool disconnect = false;
    int i = 0;
    int j = 1;
};

#endif // WEBSOCKETSERVER_H
