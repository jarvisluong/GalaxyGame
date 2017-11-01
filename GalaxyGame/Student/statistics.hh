#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "istatistics.hh"
namespace Student {

class Statistics : public Common::IStatistics
{
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

private:
    unsigned _number_of_saved_ships;
    unsigned _number_of_lost_ships;
    unsigned _points;
    unsigned _credits;
};
}//Student

#endif // STATISTICS_HH
