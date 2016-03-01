#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T19:37:54
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += core.cpp

HEADERS += core.h\
        core_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
