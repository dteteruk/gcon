#include <QCoreApplication>

#include "dispatcher.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Dispatcher d;
    Server serv(&d, 7727);

    return a.exec();
}
