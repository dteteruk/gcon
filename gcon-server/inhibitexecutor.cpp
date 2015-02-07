#include "inhibitexecutor.h"
#include <QDebug>
#include <QtDBus>
#include "serverstate.h"

InhibitExecutor::InhibitExecutor()
{
}


void InhibitExecutor::execute(const QJsonObject &jobj)
{
    qDebug()<<"Unlock execute";

    if (jobj["inhibit"].toBool()) {
        QDBusMessage msg = QDBusMessage::createMethodCall("org.gnome.SessionManager",
                                                          "/org/gnome/SessionManager",
                                                          "org.gnome.SessionManager",
                                                          "Inhibit");
        QList<QVariant> args;
        args.append("gcon-server");
        args.append((uint)0);
        args.append("locked by user");
        args.append((uint)8);
        msg.setArguments(args);
        QDBusMessage repl = QDBusConnection::sessionBus().call(msg);
        qDebug()<<"Error"<<repl.errorMessage()<<repl.arguments();

        ServerState* pState = ServerState::getInstance();
        pState->setInhibitId(repl.arguments().first().toUInt());
    } else {
        ServerState* pState = ServerState::getInstance();
        uint inhibitId = pState->getInhibitId();
        if (inhibitId) {
            QDBusMessage msg = QDBusMessage::createMethodCall("org.gnome.SessionManager",
                                                              "/org/gnome/SessionManager",
                                                              "org.gnome.SessionManager",
                                                              "Uninhibit");
            QList<QVariant> args;
            args.append(inhibitId);
            msg.setArguments(args);
            QDBusMessage repl = QDBusConnection::sessionBus().call(msg);
            qDebug()<<"Error"<<repl.errorMessage();
            pState->setInhibitId(0);
        } else {
             qDebug()<<"No previous Inhibit";
        }
    }
}
