#include <QString>
#include <QDebug>
#include <QCoreApplication>

#include "commandsender.h"
#include "commandmanager.h"
#include "mutecmd.h"
#include "suspendcmd.h"
#include "servershutdowncmd.h"

void printUsage();
void registerCommands() {
    RegisterCommand<MuteCmd>("mute");
    RegisterCommand<SuspendCmd>("suspend");
    RegisterCommand<ServerShutdownCmd>("exit");
}

void printUsage()
{
    qDebug()<<"Usage:"<<"\n"
            <<"\t suspend   - send suspend command"<<"\n"
            <<"\t mute      - send mute command";

}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    if (argc <= 1) {
        printUsage();
        return 0;
    }

    registerCommands();

    CtrlCommand* cmd = CommandManager::getCommand(QString(argv[1]));
    if (cmd == NULL) {
        printUsage();
        return -1;
    }

    CommandSender cmdSender;
    QObject::connect(&cmdSender, SIGNAL(commandSent()), &app, SLOT(quit()));
    cmdSender.Send(cmd->getJson());
    delete cmd;

    app.exec();

    return 0;
}

