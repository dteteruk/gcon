#include "servershutdownexecutor.h"
#include <QCoreApplication>

ServerShutdownExecutor::ServerShutdownExecutor()
{
}

void ServerShutdownExecutor::execute(const QJsonObject &jobj)
{
    qApp->quit();
}
