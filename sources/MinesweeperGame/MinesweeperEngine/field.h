#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
class Cell;
using namespace std;
class Field
{
public:
    Field();
    Field(int sizeX, int sizeY);
    void openAllCells();
    void setValuesInCells(int x, int y);
    bool checkValidCoord(int coord1, int coord2);
    void spawnMines();
    int random(int maxValue);
    int getSizeX();
    int getSizeY();
    int getMinesNumber();
    Cell *getConsField();
    Cell* consField[16][32];
    void openCellsAround(int x, int y);
    bool lose();
    bool isGameActive();
    bool gameActive;
protected:
    int fieldSizeX;
    int fieldSizeY;
    int minesNumber;
    vector<vector<Cell> > vecField;
    bool loseFlag;

};

#endif // FIELD_H
