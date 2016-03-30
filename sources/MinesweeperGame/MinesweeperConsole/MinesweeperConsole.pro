QT += core
QT -= gui

TARGET = MinesweeperConsole
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    application.cpp

HEADERS += \
    application.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MinesweeperEngine/release/ -lMinesweeperEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MinesweeperEngine/debug/ -lMinesweeperEngine
else:unix: LIBS += -L$$OUT_PWD/../MinesweeperEngine/ -lMinesweeperEngine

INCLUDEPATH += $$PWD/../MinesweeperEngine
DEPENDPATH += $$PWD/../MinesweeperEngine
