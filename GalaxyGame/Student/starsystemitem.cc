#include "starsystemitem.hh"


StarSystemItem::StarSystemItem(QPixmap pixmap_, Common::Point location): CustomItem(pixmap_, location)
{

}

void StarSystemItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Common::IGalaxy::ShipVector shipVector = galaxy->getShipsInStarSystem(name);
    window->updateListWidget(shipVector);
    window->updatePlayerShipLocation(_location);
    window->setStarSystemLabel(name);
}
