#ifndef UNLOCKEXECUTOR_H
#define UNLOCKEXECUTOR_H

#include "commandexecutor.h"

class InhibitExecutor: public CommandExecutor
{
public:
    InhibitExecutor();
    void execute(const QJsonObject &jobj);
};

#endif // UNLOCKEXECUTOR_H
