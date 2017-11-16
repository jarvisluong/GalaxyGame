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
    void setNameForStarSystemItem(std::string name_);
    void setMainWindowForStarSystemItem(MainWindow* w_);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    std::string name;
    Student::Galaxy* galaxy;
    MainWindow* window;
};

#endif // CUSTOMITEM_HH
