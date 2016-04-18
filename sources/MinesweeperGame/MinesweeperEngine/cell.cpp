#include "cell.h"

Cell::Cell()
{

}

Cell::Cell(int coordX, int coordY)
{
    x = coordX;
    y = coordY;
    mine = 0;
    open = 0;
    flag = 0;
    value = 0;
}

int Cell::getX() { return x; }

int Cell::getY() { return y; }

bool Cell::isMine() { return mine; }

bool Cell::isFlag() { return flag; }

int Cell::getValue() { return value; }

void Cell::incValue() { value++; }

void Cell::setMine() { mine = 1; }

void Cell::swapFlag() { flag = !flag; }

void Cell::openCell() { open = 1; }

bool Cell::isOpen() { return open; }

