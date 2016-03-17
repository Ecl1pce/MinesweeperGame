#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
class Cell;

class Field
{
public:
    Field();
    Field(int difficulty);
protected:
    static const int FIELD_SETTING_SIZE = 8;
    int fieldSizeX;
    int fieldSizeY;
    Cell** field;
};

#endif // FIELD_H
