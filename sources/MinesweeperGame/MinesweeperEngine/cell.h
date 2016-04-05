#ifndef CELL_H
#define CELL_H


class Cell
{
public:
    Cell();
    Cell(int coord1, int coord2);
    int getX();
    int getY();
    bool isMine();
    void setMine();
    bool isFlag();
    int getValue();
    void incValue();
    int openCell();
    void swapFlag();
    bool isOpen();
    bool open;

protected:
    int x;
    int y;
    int value;
    bool flag;
    bool mine;

};

#endif // CELL_H
