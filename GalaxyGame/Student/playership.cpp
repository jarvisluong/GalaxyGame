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
    invariant();
}

void PlayerShip::goToLocation(Common::Point nextLocation)
{
    _location = nextLocation;
    ui_item->setPos(nextLocation.x * 21 + 500, nextLocation.y * 21 + 500);
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
