#include <QString>
#include <QtTest>
#include "field.h"
#include "cell.h"
class MinesweeperTestsTest : public QObject
{
    Q_OBJECT

public:
    MinesweeperTestsTest();
    Cell* testCell;
    Field field;
private Q_SLOTS:
    void testForCell();
    void testForMinesSpawn();
    void testForValidCoordCheck();
    void testForSizeCheck();
    void testForSettingValuesInCells();

};

MinesweeperTestsTest::MinesweeperTestsTest()
{
}

void MinesweeperTestsTest::testForCell()
{
testCell = new Cell(10,20);
QCOMPARE(testCell->getX(),10);
QCOMPARE(testCell->getY(),20);
QCOMPARE(testCell->isFlag(),0);
QCOMPARE(testCell->isMine(),0);
QCOMPARE(testCell->isOpen(),0);
QCOMPARE(testCell->getValue(),0);

for (int i = 0; i < 5; i++)
testCell->incValue();
QCOMPARE(testCell->getValue(),5);

testCell->setMine();
QCOMPARE(testCell->isMine(),1);

testCell->swapFlag();
QCOMPARE(testCell->isFlag(),1);

testCell->swapFlag();
QCOMPARE(testCell->isFlag(),0);
}

void MinesweeperTestsTest::testForMinesSpawn()
{
    int x = 0;
for (int i = 0; i < field.getSizeX(); i++)
    for (int j = 0; j < field.getSizeY(); j++)
        if (field.consField[i][j]->isMine())
            x++;
QCOMPARE(x, field.getMinesNumber());
}

void MinesweeperTestsTest::testForValidCoordCheck()
{
    QCOMPARE(field.checkValidCoord(0, 0), 1);
    QCOMPARE(field.checkValidCoord(15, 31), 1);
    QCOMPARE(field.checkValidCoord(0, 31), 1);
    QCOMPARE(field.checkValidCoord(15, 0), 1);
    QCOMPARE(field.checkValidCoord(-1, 0), 0);
    QCOMPARE(field.checkValidCoord(16, 32), 0);
    QCOMPARE(field.checkValidCoord(20, 12), 0);
    QCOMPARE(field.checkValidCoord(16, 0), 0);

}

void MinesweeperTestsTest::testForSizeCheck()
{
    QCOMPARE(field.getSizeX(), 16);
    QCOMPARE(field.getSizeY(), 32);
}

void MinesweeperTestsTest::testForSettingValuesInCells()
{
    int facticalValue[16][32];
    for (int x = 0; x < 16; x++)
        for (int y = 0; y < 32; y++)
            facticalValue[x][y] = 0;

    for (int x = 0; x < field.getSizeX(); x++)
        for (int y = 0; y < field.getSizeY(); y++)
        {
            if (field.checkValidCoord(x - 1, y - 1) && field.consField[x-1][y-1]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x - 1, y) && field.consField[x-1][y]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x - 1, y + 1) && field.consField[x-1][y+1]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x, y - 1) && field.consField[x][y-1]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x, y + 1) && field.consField[x][y+1]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x + 1, y - 1) && field.consField[x+1][y-1]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x + 1, y) && field.consField[x+1][y]->isMine())
                facticalValue[x][y]++;
            if (field.checkValidCoord(x + 1, y + 1) && field.consField[x+1][y+1]->isMine())
                facticalValue[x][y]++;
        }
    for (int x = 0; x < field.getSizeX(); x++)
        for (int y = 0; y < field.getSizeY(); y++)
            QCOMPARE(field.consField[x][y]->getValue(), facticalValue[x][y]);
}

QTEST_APPLESS_MAIN(MinesweeperTestsTest)

#include "tst_minesweeperteststest.moc"
