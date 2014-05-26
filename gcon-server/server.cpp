#include "server.h"

Server::Server(Dispatcher *d, int port):
    mServer(), mDispatcher(d)
{
    connect(&mServer, SIGNAL(newConnection()), this, SLOT(gotNewConnection()));

    if (mServer.listen(QHostAddress::Any, port)) {
        qDebug() << QString::fromUtf8("Server is started");
    } else {
        qDebug() <<  QString("Unable to start the server: %1.").arg(mServer.errorString());
    }
}

void Server::gotNewConnection()
{
    qDebug() << QString::fromUtf8("I've got a new connection =)");
    QTcpSocket* clientSocket = mServer.nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void Server::readClient()
{

    QTcpSocket* clientSocket = static_cast<QTcpSocket*>(sender());
    QString s(clientSocket->readAll());
    qDebug() << "I've just recieve new message: "<<s;
    clientSocket->close();
}
