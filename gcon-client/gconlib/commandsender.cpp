#include "commandsender.h"
#include <QDebug>

void CommandSender::Send(QByteArray json){
    qDebug()<<"Send command"<<json.data();
}
