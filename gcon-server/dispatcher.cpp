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
        CommandExecutor* cmdExecutor = getCommandExecutor(cmdStr);
        if (cmdExecutor != NULL)
            cmdExecutor->execute(jobj);
            delete cmdExecutor;
    }


}

CmdExecutorMap* Dispatcher::getMap() {
    return &mCmdMap;
}

CommandExecutor* Dispatcher::getCommandExecutor(const QString &s)
{
    if (!s.isEmpty()) {
        CmdExecutorMap::iterator it = mCmdMap.find(s);
        if ((it != mCmdMap.end()) && (it.key() == s)) {
            qWarning()<<"Gonna create "<<s;
            return it.value()();
        }
    }
    qWarning()<<"No such executor:"<<s;
    return NULL;

}
