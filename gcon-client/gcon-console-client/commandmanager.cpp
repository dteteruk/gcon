#include "commandmanager.h"
#include <QDebug>

CmdMap CommandManager::mCmdMap;

CommandManager::CommandManager()
{
}

CtrlCommand* CommandManager::getCommand(QString s)
{
    if (!s.isEmpty()) {
        CmdMap::iterator it = mCmdMap.find(s);
        if ((it != mCmdMap.end()) && (it.key() == s)) {
            qWarning()<<"Gonna create "<<s;
            return it.value()();
        }
    }
    qWarning()<<"No such method:"<<s;
    return NULL;

}
