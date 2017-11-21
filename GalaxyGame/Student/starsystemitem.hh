#ifndef STARSYSTEMITEM_HH
#define STARSYSTEMITEM_HH
#include "customitem.hh"
#include <QPixmap>
class StarSystemItem: public CustomItem
{
public:
    StarSystemItem(QPixmap pixmap_, Common::Point location = Common::Point(0,0));
private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // STARSYSTEMITEM_HH
