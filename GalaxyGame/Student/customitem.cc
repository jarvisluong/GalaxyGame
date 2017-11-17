#include "customitem.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CustomItem::CustomItem(QPixmap pixmap_): QGraphicsPixmapItem(pixmap_)
{

}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     Common::IGalaxy::ShipVector shipVector = galaxy->getShipsInStarSystem(starSystem->getName());
     window->updateListWidget(shipVector);
}

void CustomItem::setGalaxyForStarSystemItem(Student::Galaxy *galaxy_)
{
    galaxy = galaxy_;
}

void CustomItem::setMainWindowForStarSystemItem(MainWindow *w_)
{
    window = w_;
}

void CustomItem::setStarSystemForItem(std::shared_ptr<Common::StarSystem> star_)
{
    starSystem = star_;
}
