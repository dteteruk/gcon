#-------------------------------------------------
#
# Project created by QtCreator 2014-05-25T16:32:17
#
#-------------------------------------------------

QT       += core network

QT       -= gui

DESTDIR = ../bin

TARGET = gcon-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    dispatcher.cpp \
    server.cpp

HEADERS += \
    dispatcher.h \
    server.h