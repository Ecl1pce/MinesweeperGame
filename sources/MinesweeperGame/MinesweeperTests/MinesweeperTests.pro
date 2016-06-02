#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T17:30:12
#
#-------------------------------------------------

QT       += testlib
QMAKE_CXXFLAGS += -std=c++11

QT       -= gui

TARGET = tst_minesweeperteststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_minesweeperteststest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MinesweeperEngine/release/ -lMinesweeperEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MinesweeperEngine/debug/ -lMinesweeperEngine
else:unix: LIBS += -L$$OUT_PWD/../MinesweeperEngine/ -lMinesweeperEngine

INCLUDEPATH += $$PWD/../MinesweeperEngine
DEPENDPATH += $$PWD/../MinesweeperEngine
