#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include "dispatcher.h"

class Server: QObject
{
public:
    Server(Dispatcher* d, int port);

private:
    QTcpServer mServer;
    Dispatcher* mDispatcher;
//    QTcpSocket* mClientSocket;
//    int maxClientsCount;

private slots:
    void gotNewConnection();
};

#endif // SERVER_H
