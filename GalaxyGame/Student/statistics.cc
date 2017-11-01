#include "statistics.hh"
#include "stateexception.hh"

Student::Statistics::Statistics()
{
    _number_of_lost_ships = 0;
    _number_of_saved_ships = 0;
    _points = 0;
    _credits = 0;
}

void Student::Statistics::addSavedShip()
{
    _number_of_saved_ships++;
}

unsigned Student::Statistics::getSavedShips() const
{
    return _number_of_saved_ships;
}

void Student::Statistics::addLostShip()
{
    _number_of_lost_ships++;
}

unsigned Student::Statistics::getLostShips() const
{
    return _number_of_lost_ships;
}

void Student::Statistics::addPoints(unsigned amount)
{
    _points += amount;
}

void Student::Statistics::reducePoints(unsigned amount)
{
    if (amount > _points) {
        throw Common::StateException("Cannot reduce more points than current points");
    }
    _points -= amount;
}

unsigned Student::Statistics::getPoints() const
{
    return _points;
}

void Student::Statistics::addCredits(unsigned amount)
{
    _credits += amount;
}

void Student::Statistics::reduceCredits(unsigned amount)
{
    _credits -= amount;
}

int Student::Statistics::getCreditBalance() const
{
    return _credits;
}
