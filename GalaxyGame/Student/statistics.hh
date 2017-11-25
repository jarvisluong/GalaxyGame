#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "istatistics.hh"
#include <QObject>
namespace Student {

class Statistics : public QObject, public Common::IStatistics
{
    Q_OBJECT
public:
    Statistics();

     void addSavedShip();
     unsigned getSavedShips() const;

     void addLostShip();
     unsigned getLostShips() const;

     void addPoints(unsigned amount);
     void reducePoints(unsigned amount);
     unsigned getPoints() const;

     void addCredits(unsigned amount);
     void reduceCredits(unsigned amount);
     int getCreditBalance() const;
signals:
     void on_point_changed(unsigned point_);
     void on_credit_changed(unsigned credit_);
private:
    unsigned _number_of_saved_ships;
    unsigned _number_of_lost_ships;
    unsigned _points;
    int _credits;

    void invariant() const;
};
}//Student

#endif // STATISTICS_HH
