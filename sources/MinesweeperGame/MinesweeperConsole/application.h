#ifndef APPLICATION_H
#define APPLICATION_H

#include "../MinesweeperEngine/field.h"
#include "../MinesweeperEngine/cell.h"

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
