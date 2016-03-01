#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T20:04:25
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += gameapi.cpp

HEADERS += gameapi.h\
        core_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
