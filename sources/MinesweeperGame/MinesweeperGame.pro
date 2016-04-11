TEMPLATE = subdirs

SUBDIRS += \
    MinesweeperConsole \
    MinesweeperEngine \
    MinesweeperDesktop \
    MinesweeperTests

MinesweeperConsole.depends = MinesweeperEngine
