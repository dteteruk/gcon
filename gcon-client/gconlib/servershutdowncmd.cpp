#include "servershutdowncmd.h"

ServerShutdownCmd::ServerShutdownCmd()
{
    mCmd["cmd"] = QString("server-shutdown");
}
