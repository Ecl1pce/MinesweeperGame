#include "field.h"

Field::Field()
{
    fieldSizeX = 16;
    fieldSizeY = 32;
    minesNumber = 40;
    gameActive = 1;
    loseFlag = 0;

        vector <Cell> tmpVect;
        for (int i = 0; i < fieldSizeX; i++)
        {
            for (int j = 0; j < fieldSizeY; j++)
                tmpVect.push_back(Cell(i, j));
            consField.push_back(tmpVect);
        }

            srand(static_cast<unsigned int>(time(NULL)));
            spawnMines();

            for (int i = 0; i < fieldSizeX; i++)
                for (int j = 0; j < fieldSizeY; j++)
                    setValuesInCells(i, j);
}

Field::Field(int sizeX, int sizeY, int minesNumber)
{
    Field::minesNumber = minesNumber;
    gameActive = 1;
    loseFlag = 0;
       fieldSizeX = sizeX;
       fieldSizeY = sizeY;

        vector <Cell> tmpVect;
        for (int i = 0; i < fieldSizeX; i++)
        {
            for (int j = 0; j < fieldSizeY; j++)
                tmpVect.push_back(Cell(i, j));
            consField.push_back(tmpVect);
        }

            srand(static_cast<unsigned int>(time(NULL)));

            spawnMines();

            for (int i = 0; i < fieldSizeX; i++)
                for (int j = 0; j < fieldSizeY; j++)
                    setValuesInCells(i, j);
}

bool Field::checkValidCoord(int coord1, int coord2)
{
    return (coord1 >= 0) && (coord2 >= 0) && (coord1 <  fieldSizeX) && (coord2 <  fieldSizeY);
}
int Field::spawnMines()
{
    int numberOfSpawnedMines = 0;
    int x,y;
    while (numberOfSpawnedMines < minesNumber)
    {
        x = random(fieldSizeX);
        y = random(fieldSizeY);
        Cell *cell = &consField[x][y];
        if (cell->isMine() == 0)
        {
            cell->setMine();
            numberOfSpawnedMines++;
        }

    }
return numberOfSpawnedMines;
}
int Field::random(int maxValue)
{
    return ((rand() % maxValue));

}
void Field::setValuesInCells(int x, int y)
{
    if (checkValidCoord(x - 1, y - 1) && consField[x-1][y-1].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x - 1, y) && consField[x-1][y].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x - 1, y + 1) && consField[x-1][y+1].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x, y - 1) && consField[x][y-1].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x, y + 1) && consField[x][y+1].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x + 1, y - 1) && consField[x+1][y-1].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x + 1, y) && consField[x+1][y].isMine())
        consField[x][y].incValue();
    if (checkValidCoord(x + 1, y + 1) && consField[x+1][y+1].isMine())
        consField[x][y].incValue();
}
void Field::openAllCells()
{
    for (int i = 0; i < fieldSizeX; i++)
        for (int j = 0; j < fieldSizeY; j++)
            consField[i][j].openCell();
}
int Field::getSizeX()
{
    return fieldSizeX;
}
int Field::getSizeY()
{
    return fieldSizeY;
}
int Field::getMinesNumber()
{
    return minesNumber;
}
void Field::openCellsAround(int x, int y)
{
    if (checkValidCoord(x, y))
    {
    consField[x][y].openCell();
    if (consField[x][y].isMine())
        loseFlag = 1;
    if (consField[x][y].getValue() == 0)
    {
        if (checkValidCoord(x - 1, y - 1))
        {
            if (consField[x-1][y-1].getValue() == 0 && consField[x-1][y-1].isOpen() == 0)
                openCellsAround(x - 1, y - 1);
            else
                consField[x-1][y-1].openCell();
        }
        if (checkValidCoord(x - 1, y))
        {
            if (consField[x-1][y].getValue() == 0 && consField[x-1][y].isOpen() == 0)
                openCellsAround(x - 1, y);
            else  consField[x-1][y].openCell();
        }

        if (checkValidCoord(x - 1, y + 1))
        {
            if (consField[x-1][y+1].getValue() == 0 && consField[x-1][y+1].isOpen() == 0)
                openCellsAround(x - 1, y + 1);
            else
                consField[x-1][y+1].openCell();
        }

        if (checkValidCoord(x, y - 1))
        {
            if (consField[x][y-1].getValue() == 0 && consField[x][y-1].isOpen() == 0)
                openCellsAround(x, y - 1);
            else   consField[x][y-1].openCell();
        }

        if (checkValidCoord(x, y + 1))
        {
            if (consField[x][y+1].getValue() == 0 && consField[x][y+1].isOpen() == 0)
                openCellsAround(x, y + 1);
            else   consField[x][y+1].openCell();
        }

        if (checkValidCoord(x + 1, y - 1))
        {
            if (consField[x+1][y-1].getValue() == 0 && consField[x+1][y-1].isOpen() == 0)
                openCellsAround(x + 1, y - 1);
            else   consField[x+1][y-1].openCell();
        }

        if (checkValidCoord(x + 1, y))
        {
            if (consField[x+1][y].getValue() == 0 && consField[x+1][y].isOpen() == 0)
                openCellsAround(x + 1, y);
            else   consField[x+1][y].openCell();
        }

        if (checkValidCoord(x + 1, y + 1))
        {
            if (consField[x+1][y+1].getValue() == 0 && consField[x+1][y+1].isOpen() == 0)
                openCellsAround(x + 1, y + 1);
            else   consField[x+1][y+1].openCell();
        }
    }
}
}
bool Field::isLose()
{
    return loseFlag;
}
bool Field::isGameActive()
{
    return gameActive;
}
Cell Field::getPieceOfField(int x, int y)
{
    return consField[x][y];
}
void Field::setFlag(int x, int y)
{
    consField[x][y].swapFlag();
}
