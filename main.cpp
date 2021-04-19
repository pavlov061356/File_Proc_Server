#include <QCoreApplication>
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QThread>
#include <QObject>

#include <iostream>
#include <string>
#include "websocketserver.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //qDebug()<< "io";
    QString targetDir = argv[1];
    WebSocketServer server(targetDir);
    return a.exec();

}
