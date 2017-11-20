#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "ship.hh"
#include "point.hh"
#include <QGraphicsPixmapItem>

namespace Student {
class PlayerShip
{
public:
    PlayerShip(Common::Point initialLocation, unsigned int initialHealth = 50);
    void goToLocation(Common::Point nextLocation);
    void decreaseHealth(unsigned int amount);
    void increaseHealth(unsigned int amount);
    unsigned int getHealth();
    Common::Point getLocation();    
    void set_ui_item(QGraphicsPixmapItem *item);
    QGraphicsPixmapItem *get_ui_item();
private:
    void invariant();
    QGraphicsPixmapItem* ui_item;
    const unsigned int maxHealth = 50;
    Common::Point _location;
    unsigned int _health;
};
}

#endif // PLAYERSHIP_H
