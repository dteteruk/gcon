#include "ctrlcommand.h"

CtrlCommand::CtrlCommand(): mCmd()
{
}

CtrlCommand::~CtrlCommand()
{

}

QByteArray CtrlCommand::getJson() {
    QJsonDocument doc(mCmd);
    return doc.toJson();
}
