#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T20:04:25
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += \
    cell.cpp \
    field.cpp

HEADERS +=\
        core_global.h \
    cell.h \
    field.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
