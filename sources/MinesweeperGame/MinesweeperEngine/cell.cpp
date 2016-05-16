#include "cell.h"


Cell::Cell(int coordX, int coordY)
{
    x = coordX;
    y = coordY;
    mine = 0;
    open = 0;
    flag = 0;
    value = 0;
}

int Cell::getX() const { return x; }

int Cell::getY() const { return y; }

bool Cell::isMine() const { return mine; }

bool Cell::isFlag() const { return flag; }

int Cell::getValue() const { return value; }

void Cell::incValue() { value++; }

void Cell::setMine() { mine = 1; }

void Cell::swapFlag() { flag = !flag; }

void Cell::openCell() { open = 1; }

bool Cell::isOpen() { return open; }

