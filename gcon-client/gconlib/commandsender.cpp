#include "commandsender.h"
#include <QDebug>

void CommandSender::Send(QString cmd){
    qDebug()<<"Send command"<<cmd;
}
