#ifndef VOLUMEEXECUTOR_H
#define VOLUMEEXECUTOR_H

#include "commandexecutor.h"

class VolumeExecutor : public CommandExecutor
{
public:
    VolumeExecutor();
    void execute(const QJsonObject &jobj);
};

#endif // VOLUMEEXECUTOR_H
