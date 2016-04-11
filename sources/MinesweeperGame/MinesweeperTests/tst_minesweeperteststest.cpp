#include <QString>
#include <QtTest>
#include "field.h"
class MinesweeperTestsTest : public QObject
{
    Q_OBJECT

public:
    MinesweeperTestsTest();
    int defaultDiff = 1;
private Q_SLOTS:
    void testCase1();
};

MinesweeperTestsTest::MinesweeperTestsTest()
{
}

void MinesweeperTestsTest::testCase1()
{

}

QTEST_APPLESS_MAIN(MinesweeperTestsTest)

#include "tst_minesweeperteststest.moc"
