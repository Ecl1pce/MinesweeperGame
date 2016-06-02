TEMPLATE = subdirs
QMAKE_CXXFLAGS += -std=c++11

SUBDIRS += \
    MinesweeperConsole \
    MinesweeperEngine \
    MinesweeperDesktop \
    MinesweeperTests

MinesweeperConsole.depends = MinesweeperEngine

