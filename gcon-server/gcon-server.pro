#-------------------------------------------------
#
# Project created by QtCreator 2014-05-25T16:32:17
#
#-------------------------------------------------

QT       += core network dbus

QT       -= gui

DESTDIR = ../bin

TARGET = gcon-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    dispatcher.cpp \
    server.cpp \
    commandexecutor.cpp \
    muteexecutor.cpp \
    suspendexecutor.cpp \
    servershutdownexecutor.cpp \
    volumeexecutor.cpp \
    serverstate.cpp \
    inhibitexecutor.cpp

HEADERS += \
    dispatcher.h \
    server.h \
    commandexecutor.h \
    muteexecutor.h \
    suspendexecutor.h \
    servershutdownexecutor.h \
    volumeexecutor.h \
    serverstate.h \
    inhibitexecutor.h

LIBS += -lasound
