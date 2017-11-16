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
     // update the ListView with returned vt
     // window->updateListView(vt);

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
