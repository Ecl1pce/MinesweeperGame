#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include <stdlib.h>
#include <time.h>
class Cell;

class Field
{
public:
    Field();
    Field(int difficulty);
    void openAllCells();
    void setValuesInCells(int x, int y);
    bool checkValidCoord(int coord1, int coord2);
    void spawnMines(int fieldSizeX, int fieldSizeY,int minesNumber);
    int random(int maxValue);
    int getSizeX();
    int getSizeY();
    int getMinesNumber();
    Cell** getField();
    Cell** field;
protected:
   // static const int SIZE = 8;
    int fieldSizeX;
    int fieldSizeY;

    int minesNumber;
};

#endif // FIELD_H
