#include "customitem.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CustomItem::CustomItem(QPixmap pixmap_, Common::Point location): QGraphicsPixmapItem(pixmap_), _location(location)
{

}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     Common::IGalaxy::ShipVector shipVector = galaxy->getShipsInStarSystem(name);
     window->updateListWidget(shipVector);
     window->updatePlayerShipLocation(_location);
}

void CustomItem::setGalaxyForStarSystemItem(Student::Galaxy *galaxy_)
{
    galaxy = galaxy_;
}

void CustomItem::setNameForStarSystemItem(std::string name_)
{
    name = name_;
}

void CustomItem::setLocationForStarSystemItem(Common::Point location)
{
    _location = location;
}

Common::Point CustomItem::getLocation()
{
    return _location;
}

void CustomItem::setMainWindowForStarSystemItem(MainWindow *w_)
{
    window = w_;
}
