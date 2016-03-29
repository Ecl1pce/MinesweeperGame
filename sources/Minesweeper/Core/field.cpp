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
        minesNumber = 27;
        break;
    case 2:
        fieldSizeX = 16;
        fieldSizeY = 16;
        minesNumber = 78;
        break;
    case 3:
        fieldSizeX = 16;
        fieldSizeY = 32;
        minesNumber = 164;
        break;
    default:
        fieldSizeX = 9;
        fieldSizeY = 9;
        minesNumber = 27;
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

        spawnMines(fieldSizeX, fieldSizeY, minesNumber);

        for (int i = 0; i < fieldSizeX; i++)
            for (int j = 0; j < fieldSizeY; j++)
                setValuesInCells(i, j);
}

bool Field::checkValidCoord(int coord1, int coord2)
{
    return (coord1 >= 0) && (coord2 >= 0) && (coord1 <  fieldSizeX) && (coord2 <  fieldSizeY);
}
void Field::spawnMines(int fieldSizeX, int fieldSizeY, int minesNumber)
{
    int i = 0;
    while (i < minesNumber)
    {
        int x = random(fieldSizeX);
        int y = random(fieldSizeY);
        if (checkValidCoord(x,y))
        {
            Cell *thisCell = &field[x][y];
            if (!thisCell->isMine())
            {
                thisCell->setMine();
                i++;
            }
        }
    }
 }
int Field::random(int maxValue)
{
    srand(static_cast<unsigned int>(time(NULL)));
    return ((rand() % maxValue) - (rand() % 3) + 3);
}
void Field::setValuesInCells(int x, int y)
{
            if (checkValidCoord(x - 1, y - 1))
                field[x - 1][y - 1].incValue();
            if (checkValidCoord(x - 1, y))
                field[x - 1][y].incValue();
            if (checkValidCoord(x - 1, y + 1))
                field[x - 1][y + 1].incValue();
            if (checkValidCoord(x, y - 1))
                field[x][y - 1].incValue();
            if (checkValidCoord(x, y + 1))
                field[x][y + 1].incValue();
            if (checkValidCoord(x + 1, y - 1))
                field[x + 1][y - 1].incValue();
            if (checkValidCoord(x + 1, y))
                field[x + 1][y].incValue();
            if (checkValidCoord(x + 1, y + 1))
                field[x + 1][y + 1].incValue();
}
void Field::openAllCells()
{
    for (int i = 0; i < fieldSizeX; i++)
        for (int j = 0; j < fieldSizeY; j++)
            field[i][j].openCell();
}
