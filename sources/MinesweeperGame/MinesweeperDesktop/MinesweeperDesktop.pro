#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T17:29:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinesweeperDesktop
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    mainwindow.cpp \
    optionswindow.cpp \
    gamewindow.cpp

HEADERS  += \
    mainwindow.h \
    optionswindow.h \
    gamewindow.h \
    qmypushbutton.h

FORMS    += \
    mainwindow.ui \
    optionswindow.ui \
    gamewindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MinesweeperEngine/release/ -lMinesweeperEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MinesweeperEngine/debug/ -lMinesweeperEngine
else:unix: LIBS += -L$$OUT_PWD/../MinesweeperEngine/ -lMinesweeperEngine

INCLUDEPATH += $$PWD/../MinesweeperEngine
DEPENDPATH += $$PWD/../MinesweeperEngine

RESOURCES += \
    resource.qrc
