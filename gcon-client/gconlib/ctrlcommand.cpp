#include "ctrlcommand.h"

CtrlCommand::CtrlCommand(): mJson()
{
}

QString CtrlCommand::getString() {
    return mJson.toString();
}
