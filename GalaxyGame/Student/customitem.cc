#include "customitem.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CustomItem::CustomItem(QPixmap pixmap_): QGraphicsPixmapItem(pixmap_)
{

}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     Common::IGalaxy::ShipVector vt = galaxy->getShipsInStarSystem(name);
     for(auto i: vt) {
         qDebug() << QString::fromStdString(i->getName()) << endl;
     }
}

void CustomItem::setGalaxyWindow(Student::Galaxy *galaxy_)
{
    galaxy = galaxy_;
}

void CustomItem::setNameForStarSystem(std::string name_)
{
    name = name_;
}
