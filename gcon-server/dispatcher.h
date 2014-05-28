#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QByteArray>
#include <QMap>
#include <QString>
#include "commandexecutor.h"

typedef QMap<QString, CommandExecutor*(*)()> CmdExecutorMap;
template<typename T> CommandExecutor * createCommanExecutor() { return new T; }

template<typename T>
class RegisterCommandExecutor{
public:
    RegisterCommandExecutor(QString cmdName, CmdExecutorMap *cmdMap) {
        cmdMap->insert(cmdName, &(createCommanExecutor<T>));
    }
};

class Dispatcher
{
public:
    Dispatcher();
    void dispatchCommand(const QByteArray &cmd);
    CmdExecutorMap* getMap();

    template<typename T> void addCommand(QString cmdName){
        RegisterCommandExecutor<T>(cmdName, this->getMap());
    }

private:
    CmdExecutorMap mCmdMap;
    CommandExecutor* getCommandExecutor(const QString &s);

};


#endif // DISPATCHER_H
