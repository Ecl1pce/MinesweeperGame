#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
class Cell;
using namespace std;

/**
 * @brief The Field class Класс целого игрового поля
 */
class Field
{
public:
    Field();
    Field(int sizeX, int sizeY, int minesNumber);
    void openAllCells();
    void setValuesInCells(int x, int y);
    bool checkValidCoord(int coord1, int coord2);
    int random(int maxValue);
    int getSizeX();
    int getSizeY();
    int getMinesNumber();
    Cell getPieceOfField(int x, int y);
    void openCellsAround(int x, int y);
    bool lose();
    bool isGameActive();
    void setFlag(int x, int y);
    bool gameActive;

protected:
    int spawnMines();
    vector<vector<Cell> > consField;
    int fieldSizeX;
    int fieldSizeY;
    int minesNumber;
    vector<vector<Cell> > vecField;
    bool loseFlag;

};

#endif // FIELD_H
