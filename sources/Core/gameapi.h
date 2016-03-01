#ifndef GAMEAPI_H
#define GAMEAPI_H

#include "core_global.h"

class CORESHARED_EXPORT GameAPI
{

public:
    GameAPI();
    void GetField();
    int StartGame(int difficulty);
    void OpenCell(int x, int y);
    void SetRedFlag(int x, int y);
    void SetQuestion(int x, int y);
    void GetStatus();
    void SaveGame();

};

#endif // GAMEAPI_H
