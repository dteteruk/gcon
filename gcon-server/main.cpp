#include <QCoreApplication>

#include "dispatcher.h"
#include "server.h"

#include "muteexecutor.h"
#include "suspendexecutor.h"
#include "servershutdownexecutor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Dispatcher d;

    d.addCommand<MuteExecutor>("mute");
    d.addCommand<SuspendExecutor>("suspend");
    d.addCommand<ServerShutdownExecutor>("server-shutdown");

    Server serv(&d, 7727);

    return a.exec();
}
