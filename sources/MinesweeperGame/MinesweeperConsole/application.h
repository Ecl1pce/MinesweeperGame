#ifndef APPLICATION_H
#define APPLICATION_H

#include "field.h"
class Application
{
public:
    Application();
    int viewMainMenu();
    void startGame(int difficulty);
    int enterDifficulty();
    int paintField(Field field);
    int difficulty;
    Field appField;
    int x;
    int y;
    void open(int x, int y);

};

#endif // APPLICATION_H
