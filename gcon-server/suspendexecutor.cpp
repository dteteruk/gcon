#include "suspendexecutor.h"
#include <QDebug>
#include <QtDBus>

SuspendExecutor::SuspendExecutor()
{
}

void SuspendExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Suspend execute";
    QDBusMessage msg = QDBusMessage::createMethodCall("org.freedesktop.UPower",
                                                      "/org/freedesktop/UPower",
                                                      "org.freedesktop.UPower",
                                                      "Suspend");
    bool queued = QDBusConnection::systemBus().send(msg);
}
