#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
class Cell;

class Field
{
public:
    Field();
    Field(int difficulty);
    void openAllCells();
    int checkMinesAround(int coord1, int coord2);
    bool checkValidCoord(int coord1, int coord2);
    int minesNumber;
    void spawnMines(fieldSizeX, fieldSizeY, minesNumber);
protected:
   // static const int SIZE = 8;
    int fieldSizeX;
    int fieldSizeY;
    Cell** field;
};

#endif // FIELD_H
