#ifndef CELL_H
#define CELL_H


class Cell
{
public:
    Cell();
    int getX();
    int getY();
    bool isMine();
    void setMine();
    bool isFlag();
    int getValue();
    void incValue();
    void openCell();
    void swapFlag();

protected:
    int x;
    int y;
    int value;
    bool flag;
    bool mine;
    bool open;
};

#endif // CELL_H
