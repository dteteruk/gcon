#include "suspendexecutor.h"
#include <QDebug>
#include <QtDBus>

SuspendExecutor::SuspendExecutor()
{
}

void SuspendExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Suspend execute";
    QDBusMessage msg = QDBusMessage::createMethodCall("org.freedesktop.login1",
                                                      "/org/freedesktop/login1",
                                                      "org.freedesktop.login1.Manager",
                                                      "Suspend");
    QList<QVariant> args;
    args.append(true);
    msg.setArguments(args);
    QDBusMessage repl = QDBusConnection::systemBus().call(msg);
    qDebug()<<"Error"<<repl.errorMessage();
}
