#include "customitem.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

CustomItem::CustomItem(QPixmap pixmap_): QGraphicsPixmapItem(pixmap_)
{

}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

//     qDebug() << QString::fromStdString(name) << endl;
     Common::IGalaxy::ShipVector vt = galaxy->getShipsInStarSystem(name);
     qDebug() << vt.size() << endl;
}

void CustomItem::setGalaxyWindow(Student::Galaxy *galaxy_)
{
    galaxy = galaxy_;
}

void CustomItem::setNameForStarSystem(std::string name_)
{
    name = name_;
}
