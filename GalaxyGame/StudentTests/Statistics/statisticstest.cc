#include "statistics.hh"
#include "stateexception.hh"
#include <QString>
#include <QtTest>

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();

private Q_SLOTS:
    void initStatistics();
    void testAddSavedShip();
    void testAddLostShip();
    void testAddPoints();
    void testRemovePoints();
    void testAddCredits();
    void testRemoveCredits();
};

StatisticsTest::StatisticsTest()
{
}


void StatisticsTest::initStatistics()
{
    Student::Statistics d;
    QCOMPARE(d.getSavedShips(), 0u);
    QCOMPARE(d.getLostShips(), 0u);
    QCOMPARE(d.getPoints(), 0u);
    QCOMPARE(d.getCreditBalance(), 0);
}

void StatisticsTest::testAddSavedShip()
{
    Student::Statistics d;
    d.addSavedShip();
    QCOMPARE(d.getSavedShips(), 1u);
}

void StatisticsTest::testAddLostShip()
{
    Student::Statistics d;
    d.addLostShip();
    QCOMPARE(d.getLostShips(), 1u);
}

void StatisticsTest::testAddPoints()
{
    Student::Statistics d;
    d.addPoints(4);
    QCOMPARE(d.getPoints(), 4u);
}

void StatisticsTest::testRemovePoints()
{
    Student::Statistics d;
    d.addPoints(3);
    QVERIFY_EXCEPTION_THROWN(d.reducePoints(4), Common::StateException);
}

void StatisticsTest::testAddCredits()
{
    Student::Statistics d;
    d.addCredits(3);
    QCOMPARE(d.getCreditBalance(), 3);
}

void StatisticsTest::testRemoveCredits()
{
    Student::Statistics d;
    QVERIFY_EXCEPTION_THROWN(d.reduceCredits(50), Common::StateException);
    QVERIFY_EXCEPTION_THROWN(d.reduceCredits(51), Common::StateException);
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
