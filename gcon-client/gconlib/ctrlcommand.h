#ifndef CTRLCOMMAND_H
#define CTRLCOMMAND_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

class CtrlCommand
{
public:
    CtrlCommand();
    virtual ~CtrlCommand();

    virtual QByteArray getJson();

protected:
    QJsonObject mCmd;

};

#endif // CTRLCOMMAND_H
