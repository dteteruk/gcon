#ifndef SUSPENDEXECUTOR_H
#define SUSPENDEXECUTOR_H

#include "commandexecutor.h"

class SuspendExecutor : public CommandExecutor
{
public:
    SuspendExecutor();
    void execute(const QJsonObject &jobj);
};

#endif // SUSPENDEXECUTOR_H
