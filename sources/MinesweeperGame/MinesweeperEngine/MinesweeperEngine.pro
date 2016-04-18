#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T17:29:12
#
#-------------------------------------------------

QT       -= gui
QMAKE_CXXFLAGS += -std=c++11
TARGET = MinesweeperEngine
TEMPLATE = lib

DEFINES += MINESWEEPERENGINE_LIBRARY

SOURCES += \
    cell.cpp \
    field.cpp

HEADERS +=\
    cell.h \
    field.h \
    str_switch.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
