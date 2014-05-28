#ifndef MUTEEXECUTOR_H
#define MUTEEXECUTOR_H

#include "commandexecutor.h"

class MuteExecutor : public CommandExecutor
{
public:
    MuteExecutor();
    void execute(const QJsonObject &jobj);
};

#endif // MUTEEXECUTOR_H
