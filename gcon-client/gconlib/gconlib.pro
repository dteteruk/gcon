#-------------------------------------------------
#
# Project created by QtCreator 2014-05-22T21:19:31
#
#-------------------------------------------------

QT       -= gui
QT += network

DESTDIR = ../../lib

TARGET = gcon
TEMPLATE = lib

DEFINES += GCONLIB_LIBRARY

SOURCES += commandsender.cpp \
    ctrlcommand.cpp \
    suspendcmd.cpp \
    mutecmd.cpp

HEADERS += commandsender.h\
        gconlib_global.h \
    ctrlcommand.h \
    suspendcmd.h \
    mutecmd.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
