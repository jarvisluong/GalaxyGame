#ifndef CUSTOMITEM_HH
#define CUSTOMITEM_HH

#include "galaxy.hh"
#include "mainwindow.hh"
#include <QGraphicsPixmapItem>
#include <QPixmap>

class CustomItem: public QGraphicsPixmapItem
{
public:
    CustomItem(QPixmap pixmap_);
    void setGalaxyForStarSystemItem(Student::Galaxy* galaxy_);
    void setMainWindowForStarSystemItem(MainWindow* w_);
    void setStarSystemForItem(std::shared_ptr<Common::StarSystem> star_);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    Student::Galaxy* galaxy;
    MainWindow* window;
    std::shared_ptr<Common::StarSystem> starSystem;
};

#endif // CUSTOMITEM_HH
