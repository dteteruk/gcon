#ifndef COMMANDSENDER_H
#define COMMANDSENDER_H

#include "gconlib_global.h"
#include <QByteArray>
#include <QtNetwork/QTcpSocket>
#include <QObject>

class GCONLIBSHARED_EXPORT CommandSender: public QObject
{
    Q_OBJECT
public:
    CommandSender();
    void Send(QByteArray json);

private:
    QTcpSocket mTcpSocket;

private slots:
    void gotError(QAbstractSocket::SocketError err);
};

#endif // COMMANDSENDER_H
