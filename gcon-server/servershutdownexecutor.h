#ifndef SERVERSHUTDOWNEXECUTOR_H
#define SERVERSHUTDOWNEXECUTOR_H

#include "commandexecutor.h"

class ServerShutdownExecutor : public CommandExecutor
{
public:
    ServerShutdownExecutor();
    void execute(const QJsonObject &jobj);
};

#endif // SERVERSHUTDOWNEXECUTOR_H
