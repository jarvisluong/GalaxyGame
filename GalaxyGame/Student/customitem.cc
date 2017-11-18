#include "customitem.hh"
#include "utilities.hh"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
using namespace Utilities;

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
    assert_not_null(galaxy_);
    galaxy = galaxy_;
}

void CustomItem::setMainWindowForStarSystemItem(MainWindow *w_)
{
    assert_not_null(w_);
    window = w_;
}

void CustomItem::setStarSystemForItem(std::shared_ptr<Common::StarSystem> star_)
{
    assert_not_null(star_.get());
    starSystem = star_;
}
