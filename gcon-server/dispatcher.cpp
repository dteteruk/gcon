#include "dispatcher.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Dispatcher::Dispatcher()
{
}

void Dispatcher::dispatchCommand(const QByteArray &cmd)
{
    QJsonDocument jdoc = QJsonDocument::fromJson(cmd);
    if (jdoc.isObject()) {
        QJsonObject jobj = jdoc.object();
        QString cmdStr = jobj["cmd"].toString();
        qDebug()<<"Dispatcher get command"<<cmdStr;
    }


}

CmdExecutorMap* Dispatcher::getMap() {
    return &mCmdMap;
}
