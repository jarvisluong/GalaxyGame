#include "playership.h"
#include <QDebug>
#include <QPixmap>
#include <QImage>

namespace Student {

PlayerShip::PlayerShip(Common::Point initialLocation, unsigned int initialHealth)
    :_location(initialLocation),
      _health(initialHealth)
{
    QImage ship_image;
    ship_image.load("Assets/ship.png");
    ship_image.scaled(20, 20);
    ui_item = new QGraphicsPixmapItem(QPixmap::fromImage(ship_image));
    invariant();
}

void PlayerShip::goToLocation(Common::Point nextLocation)
{
    _location = nextLocation;
}

void PlayerShip::decreaseHealth(unsigned int amount)
{
    invariant();
    if (_health <= amount) {
        _health = 0;
    } else {
        _health -= amount;
    }
    invariant();
}

void PlayerShip::increaseHealth(unsigned int amount)
{
    invariant();
    if (_health + amount >= maxHealth) {
        _health = maxHealth;
    } else {
        _health += amount;
    }
    invariant();
}

unsigned int PlayerShip::getHealth()
{
    return _health;
}

Common::Point PlayerShip::getLocation()
{
    return _location;
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
