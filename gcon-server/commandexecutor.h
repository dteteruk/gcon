#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <QJsonObject>

class CommandExecutor
{
public:
    CommandExecutor();
    virtual ~CommandExecutor();
    virtual void execute(const QJsonObject &jobj) = 0;
};

#endif // COMMANDEXECUTOR_H
