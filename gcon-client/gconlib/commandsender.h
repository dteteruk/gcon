#ifndef COMMANDSENDER_H
#define COMMANDSENDER_H

#include "gconlib_global.h"

class GCONLIBSHARED_EXPORT CommandSender
{

public:
    static void Send(QString cmd);
};

#endif // COMMANDSENDER_H
