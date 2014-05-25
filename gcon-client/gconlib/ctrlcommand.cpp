#include "ctrlcommand.h"

CtrlCommand::CtrlCommand(): mCmd()
{
}

QByteArray CtrlCommand::getJson() {
    QJsonDocument doc(mCmd);
    return doc.toJson();
}
