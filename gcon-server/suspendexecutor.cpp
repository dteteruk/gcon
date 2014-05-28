#include "suspendexecutor.h"
#include <QDebug>

SuspendExecutor::SuspendExecutor()
{
}

void SuspendExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Suspend execute";
}
