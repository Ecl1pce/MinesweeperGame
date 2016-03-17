#include "cell.h"

Cell::Cell()
{

}
int Cell::getX() { return x; }

int Cell::getY() { return y; }

bool Cell::isMine() { return mine; }

bool Cell::isFlag() { return flag; }

int Cell::getValue() { return value; }

void Cell::incValue() { value++; }

void Cell::setMine() { mine = 1; }

void Cell::swapFlag() { flag = !flag; }
