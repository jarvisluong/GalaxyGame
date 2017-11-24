#include "statistics.hh"
#include "stateexception.hh"
#include <QtDebug>

const int MAX_LOAN_ALLOWANCE = -50;

Student::Statistics::Statistics()
{
    _number_of_lost_ships = 0;
    _number_of_saved_ships = 0;
    _points = 0;
    _credits = 0;
    invariant();
}

void Student::Statistics::addSavedShip()
{
    invariant();
    _number_of_saved_ships++;
    invariant();
}

unsigned Student::Statistics::getSavedShips() const
{
    invariant();
    return _number_of_saved_ships;
}

void Student::Statistics::addLostShip()
{
    invariant();
    _number_of_lost_ships++;
    invariant();
}

unsigned Student::Statistics::getLostShips() const
{
    invariant();
    return _number_of_lost_ships;
}

void Student::Statistics::addPoints(unsigned amount)
{
    invariant();
    _points += amount;
    emit on_point_changed(_points);
    invariant();
}

void Student::Statistics::reducePoints(unsigned amount)
{
    invariant();
    if (amount > _points) {
        throw Common::StateException("Cannot reduce more points than current points");
    }
    _points -= amount;
    emit on_point_changed(_points);
    invariant();
}

unsigned Student::Statistics::getPoints() const
{
    invariant();
    return _points;
}

void Student::Statistics::addCredits(unsigned amount)
{
    invariant();
    _credits += amount;
    emit on_credit_changed(_credits);
    invariant();
}

void Student::Statistics::reduceCredits(unsigned amount)
{
    invariant();
    if (int(_credits - amount) <= MAX_LOAN_ALLOWANCE) {
        throw Common::StateException("Cannot have lower credits than allowance");
    }
    _credits -= amount;
    emit on_credit_changed(_credits);
    invariant();
}

int Student::Statistics::getCreditBalance() const
{
    invariant();
    return _credits;
}

void Student::Statistics::reset()
{
    _number_of_lost_ships = 0;
    _number_of_saved_ships = 0;
    _points = 0;
    _credits = 0;
    emit on_point_changed(0);
    emit on_credit_changed(10);
}

void Student::Statistics::invariant() const
{
    Q_ASSERT(_points >= 0);
    Q_ASSERT(_credits > MAX_LOAN_ALLOWANCE);
}
