#include "customitem.hh"
#include "utilities.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
using namespace Utilities;

CustomItem::CustomItem(QPixmap pixmap_, Common::Point location): QGraphicsPixmapItem(pixmap_), _location(location)
{

}

//void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//     Common::IGalaxy::ShipVector shipVector = galaxy->getShipsInStarSystem(name);
//     window->updateListWidget(shipVector);
//     window->updatePlayerShipLocation(_location);
//     window->setStarSystemLabel(name);
//}

void CustomItem::setGalaxyForItem(Student::Galaxy *galaxy_)
{
    assert_not_null(galaxy_);
    galaxy = galaxy_;
}

void CustomItem::setNameForItem(std::string name_)
{
    name = name_;
}

void CustomItem::setMainWindowForItem(MainWindow *w_)
{
    assert_not_null(w_);
    window = w_;
}

void CustomItem::setLocationForItem(Common::Point location)
{
    _location = location;
}

Common::Point CustomItem::getLocation()
{
    return _location;
}
