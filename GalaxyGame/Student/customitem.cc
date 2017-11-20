#include "customitem.hh"
#include "utilities.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
using namespace Utilities;

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
    assert_not_null(galaxy_);
    galaxy = galaxy_;
}

void CustomItem::setNameForStarSystemItem(std::string name_)
{
    name = name_;
}

void CustomItem::setMainWindowForStarSystemItem(MainWindow *w_)
{
    assert_not_null(w_);
    window = w_;
}

void CustomItem::setLocationForStarSystemItem(Common::Point location)
{
    _location = location;
}

Common::Point CustomItem::getLocation()
{
    return _location;
}
