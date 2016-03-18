#include "field.h"

Field::Field()
{

}

Field::Field(int difficulty)
{
    switch (difficulty) {
    case 1:
        fieldSizeX = 9;
        fieldSizeY = 9;
        break;
    case 2:
        fieldSizeX = 16;
        fieldSizeY = 16;
    case 3:
        fieldSizeX = 16;
        fieldSizeY = 32;
    default:
        fieldSizeX = 9;
        fieldSizeY = 9;
        break;
    }
        field = new Cell* [fieldSizeX];
                for (int i = 0; i < fieldSizeX; i++)
                {
                  field[i] = new Cell [fieldSizeY];
                }

        for (int i = 0; i < fieldSizeX; i++)
            for (int j = 0; j < fieldSizeY; j++)
                field[i][j] = Cell(i,j);

       // for (int i = 0; i < fieldSizeX; i++)
//            for (int j = 0; j < fieldSizeY; j++)

}

bool Field::checkValidCoord(int coord1, int coord2)
{
    return (coord1 >= 0) && (coord2 >= 0) && (coord1 <  fieldSizeX) && (coord2 <  fieldSizeY);
}
 void Field::spawnMines(fieldSizeX, fieldSizeY, minesNumber)
 {
     while (i < minesNumber)
     {

     }
 }
