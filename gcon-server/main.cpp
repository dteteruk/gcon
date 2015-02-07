#include <QCoreApplication>

#include "dispatcher.h"
#include "server.h"
#include "serverstate.h"

#include "muteexecutor.h"
#include "suspendexecutor.h"
#include "servershutdownexecutor.h"
#include "volumeexecutor.h"
#include "inhibitexecutor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Dispatcher d;

//    ServerState* st = new ServerState();
//    qDebug()<<st->getVolumeLevel();
    d.addCommand<MuteExecutor>("mute");
    d.addCommand<SuspendExecutor>("suspend");
    d.addCommand<ServerShutdownExecutor>("server-shutdown");
    d.addCommand<VolumeExecutor>("volume");
    d.addCommand<InhibitExecutor>("inhibit");

    Server serv(&d, 7727);

    return a.exec();
}
