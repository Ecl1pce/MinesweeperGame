#include <QString>
#include <QtTest>

class MinesweeperTestsTest : public QObject
{
    Q_OBJECT

public:
    MinesweeperTestsTest();

private Q_SLOTS:
    void testCase1();
};

MinesweeperTestsTest::MinesweeperTestsTest()
{
}

void MinesweeperTestsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MinesweeperTestsTest)

#include "tst_minesweeperteststest.moc"
