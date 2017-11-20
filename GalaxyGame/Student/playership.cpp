#include "playership.h"
#include <QDebug>

namespace Student {

PlayerShip::PlayerShip(Common::Point initialLocation, int initialHealth)
    :_location(initialLocation),
      _health(initialHealth)
{
    invariant();
}

void PlayerShip::goToLocation(Common::Point nextLocation)
{
    double distance = nextLocation.distanceTo(_location);
    int health_to_decrease = (int)(distance / 2);
    decreaseHealth(health_to_decrease);
    _location = nextLocation;
    ui_item->setPos(nextLocation.x * 21 + 500, nextLocation.y * 21 + 500);
}

void PlayerShip::decreaseHealth(int amount)
{
    invariant();
    if (_health <= amount) {
        _health = 0;
    } else {
        _health -= amount;
    }
    invariant();
    if (_health == 0) {
        emit loseAllHealth();
    } else {
        emit healthChanged(_health);
    }
}

void PlayerShip::increaseHealth(int amount)
{
    invariant();
    if (_health + amount >= maxHealth) {
        _health = maxHealth;
    } else {
        _health += amount;
    }
    invariant();
    emit healthChanged(_health);
}

int PlayerShip::getHealth()
{
    return _health;
}

Common::Point PlayerShip::getLocation()
{
    return _location;
}

void PlayerShip::set_ui_item(QGraphicsPixmapItem *item)
{
    ui_item = item;
}

QGraphicsPixmapItem *PlayerShip::get_ui_item()
{
    return ui_item;
}

void PlayerShip::invariant()
{
    Q_ASSERT(_health >= 0 && _health <= maxHealth);
}

}
