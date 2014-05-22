#-------------------------------------------------
#
# Project created by QtCreator 2014-05-22T21:19:31
#
#-------------------------------------------------

QT       -= gui

DESTDIR = ../../lib

TARGET = gcon
TEMPLATE = lib

DEFINES += GCONLIB_LIBRARY

SOURCES += commandsender.cpp

HEADERS += commandsender.h\
        gconlib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
