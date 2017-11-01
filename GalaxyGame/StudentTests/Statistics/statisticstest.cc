#include <QString>
#include <QtTest>
#include "statistics.hh"
class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();

private Q_SLOTS:
    void initStatistics();
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
    QCOMPARE(d.getCreditBalance(), 0u);
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
