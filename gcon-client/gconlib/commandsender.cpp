#include "commandsender.h"
#include <QDebug>

CommandSender::CommandSender(): mTcpSocket()
{
    connect(&mTcpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(sent()));
    connect(&mTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(gotError(QAbstractSocket::SocketError)));
}

void CommandSender::Send(QByteArray json)
{
    mTcpSocket.connectToHost(QString("localhost"), 7727);
    mTcpSocket.write(json);
    qDebug()<<"Send command"<<json.data();
}

void CommandSender::gotError(QAbstractSocket::SocketError err)
{
    qDebug()<<"Got Socket error: "<<err;
}

void CommandSender::sent()
{
   mTcpSocket.close();
   emit commandSent();
}
