#ifndef APPLICATION_H
#define APPLICATION_H

#include "field.h"
#include "cell.h"
class Field;
class Cell;

class Application
{
public:
    Application();
    int viewMainMenu();
    void startGame(int difficulty);
    int enterDifficulty();
    int paintField(int x, int y, Cell** field);
    int difficulty;



};

#endif // APPLICATION_H
