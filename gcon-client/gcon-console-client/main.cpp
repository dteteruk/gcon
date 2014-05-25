#include "commandsender.h"
#include "commandmanager.h"
#include "mutecmd.h"
#include "suspendcmd.h"
#include <QString>
#include <QDebug>
#include <QCoreApplication>

void printUsage();
void registerCommands() {
    RegisterCommand<MuteCmd>("mute");
    RegisterCommand<SuspendCmd>("suspend");
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
    cmdSender.Send(cmd->getJson());

    app.exec();

    return 0;
}

