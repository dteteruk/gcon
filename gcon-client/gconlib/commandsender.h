#ifndef COMMANDSENDER_H
#define COMMANDSENDER_H

#include "gconlib_global.h"
#include <QByteArray>

class GCONLIBSHARED_EXPORT CommandSender
{

public:
    static void Send(QByteArray json);
};

#endif // COMMANDSENDER_H
