#ifndef APPLICATION_H
#define APPLICATION_H

#include "field.h"
class Application
{
public:
    Application();
    int viewMainMenu();
    void startGame();
    int enterDifficulty();
    int paintField(Field field);
    void open(int x, int y);
    void setFlag(int x, int y);
    int calculateFlagsLeft();
    void checkLose();
    void checkWin();

protected:
    int calculateMinesLeft();
    void help();
    void enterCommands();
    void noManyFlags();

    int difficulty;
    Field* appField;
    int x;
    int y;
    int minesLeft;  
    int facticalMinesNumber;
    int flagsLeft;
    string command;
    bool isWin;
    bool gameActiv;
    int sizeX;
    int sizeY;
    int mines;
};

#endif // APPLICATION_H
