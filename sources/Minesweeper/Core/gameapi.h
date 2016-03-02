#ifndef GAMEAPI_H
#define GAMEAPI_H

#include "core_global.h"

class CORESHARED_EXPORT GameAPI
{

public:
    GameAPI();
    void getField();
    int startGame(int difficulty);
    void openCell(int x, int y);
    void setRedFlag(int x, int y);
    void setQuestion(int x, int y);
    void setStatus();
    void saveGame();

};

#endif // GAMEAPI_H
