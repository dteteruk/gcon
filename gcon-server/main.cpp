#include <QCoreApplication>

#include "dispatcher.h"
#include "server.h"

#include "muteexecutor.h"
#include "suspendexecutor.h"
#include "servershutdownexecutor.h"
#include "volumeexecutor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Dispatcher d;

    d.addCommand<MuteExecutor>("mute");
    d.addCommand<SuspendExecutor>("suspend");
    d.addCommand<ServerShutdownExecutor>("server-shutdown");
    d.addCommand<VolumeExecutor>("volume");

    Server serv(&d, 7727);

    return a.exec();
}
