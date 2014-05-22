#ifndef CTRLCOMMAND_H
#define CTRLCOMMAND_H

#include <QJsonValue>

class CtrlCommand
{
public:
    CtrlCommand();

    QString getString();

private:
    QJsonValue mJson;
};

#endif // CTRLCOMMAND_H
