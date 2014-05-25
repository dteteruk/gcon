#-------------------------------------------------
#
# Project created by QtCreator 2014-05-21T21:45:53
#
#-------------------------------------------------

QT       += core network

QT       -= gui

DESTDIR = ../../bin

INCLUDEPATH = ../gconlib

TARGET = gcl
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    commandmanager.cpp

HEADERS += \
    commandmanager.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lgcon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lgcon
else:unix: LIBS += -L$$PWD/../../lib/ -lgcon

INCLUDEPATH += $$PWD/../gconlib
DEPENDPATH += $$PWD/../gconlib
