#ifndef CUSTOMITEM_HH
#define CUSTOMITEM_HH

#include "galaxy.hh"
#include <QGraphicsPixmapItem>
#include <QPixmap>

class CustomItem: public QGraphicsPixmapItem
{
public:
    CustomItem(QPixmap pixmap_);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void setGalaxyWindow(Student::Galaxy* galaxy_);
    void setNameForStarSystem(std::string name_);
private:
    std::string name;
    Student::Galaxy* galaxy;
};

#endif // CUSTOMITEM_HH
