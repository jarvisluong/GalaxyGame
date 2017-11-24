#include "starsystemitem.hh"


StarSystemItem::StarSystemItem(QPixmap pixmap_, Common::Point location): CustomItem(pixmap_, location)
{

}

void StarSystemItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Common::IGalaxy::ShipVector shipVector = galaxy->getShipsInStarSystem(name);
    window->updateListWidget(shipVector);
    window->setStarSystemLabel(name);
    window->updatePlayerShipLocation(_location);
    window->setCurrentStarSystemNameForPlayableShip(name);
}

void StarSystemItem::setGalaxyForItem(Student::Galaxy *galaxy_)
{
    assert_not_null(galaxy_);
    galaxy = galaxy_;
}
