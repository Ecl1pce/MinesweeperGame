#ifndef APPLICATION_H
#define APPLICATION_H

#include "field.h"
#include "str_switch.h"
class Application
{
public:
    Application();
    int viewMainMenu();
    void startGame();
    int enterDifficulty();
    int paintField(Field field);
    int difficulty;
    Field appField;
    int x;
    int y;
    void open(int x, int y);
    int minesLeft;
    int calculateMinesLeft(Field field);
    void setFlag(int x, int y);
    void help();
    int facticalMinesNumber;
    int calculateFlagsLeft();
    int flagsLeft;
    void noManyFlags();
    void enterCommands();
    string command;
    bool isWin;
    bool gameActiv;
};

#endif // APPLICATION_H
