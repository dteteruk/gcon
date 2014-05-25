#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QMap>
#include <QString>
#include "ctrlcommand.h"
typedef QMap<QString, CtrlCommand*(*)()> CmdMap;

class CommandManager
{
public:
    CommandManager();

    //get command by name, or null if not exist/not registered
    static CtrlCommand* getCommand(QString s);

protected:
    static CmdMap mCmdMap;
};

template<typename T> CtrlCommand * createCommand() { return new T; }

template<typename T>
class RegisterCommand : CommandManager {
public:
    RegisterCommand(QString cmdName) {
        mCmdMap.insert(cmdName, &(createCommand<T>));
    }
};


#endif // COMMANDMANAGER_H
