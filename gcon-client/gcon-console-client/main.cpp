#include "commandsender.h"
#include <QString>
#include <QDebug>

void printUsage();

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printUsage();
        return 0;
    }

    CommandSender::Send(QString(argv[1]));
    return 0;
}

void printUsage()
{
    qDebug()<<"Usage:"<<"\n"
            <<"\t suspend   - send suspend command"<<"\n"
            <<"\t mute      - send mute command";

}


