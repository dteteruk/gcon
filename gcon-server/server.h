#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include "dispatcher.h"

class Server: public QObject
{
    Q_OBJECT
public:
    Server(Dispatcher* d, int port);

private:
    QTcpServer mServer;
    Dispatcher* mDispatcher;
//    QTcpSocket* mClientSocket;
//    int maxClientsCount;

private slots:
    void gotNewConnection();
    void readClient();
};

#endif // SERVER_H
