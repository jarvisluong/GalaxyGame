#ifndef CUSTOMITEM_HH
#define CUSTOMITEM_HH

#include "galaxy.hh"
#include "mainwindow.hh"
#include "point.hh"
#include <QGraphicsPixmapItem>
#include <QPixmap>

class CustomItem: public QGraphicsPixmapItem
{
public:
    CustomItem(QPixmap pixmap_, Common::Point location = Common::Point(0,0));
    void setGalaxyForStarSystemItem(Student::Galaxy* galaxy_);
    void setNameForStarSystemItem(std::string name_);
    void setLocationForStarSystemItem(Common::Point location);
    Common::Point getLocation();
    void setMainWindowForStarSystemItem(MainWindow* w_);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    std::string name;
    Common::Point _location;
    Student::Galaxy* galaxy;
    MainWindow* window;
};

#endif // CUSTOMITEM_HH
