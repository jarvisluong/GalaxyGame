#include "customitem.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CustomItem::CustomItem(QPixmap pixmap_): QGraphicsPixmapItem(pixmap_)
{

}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     Common::IGalaxy::ShipVector shipVector = galaxy->getShipsInStarSystem(name);
     window->updateListWidget(shipVector);
}

void CustomItem::setGalaxyForStarSystemItem(Student::Galaxy *galaxy_)
{
    galaxy = galaxy_;
}

void CustomItem::setNameForStarSystemItem(std::string name_)
{
    name = name_;
}

void CustomItem::setMainWindowForStarSystemItem(MainWindow *w_)
{
    window = w_;
}
