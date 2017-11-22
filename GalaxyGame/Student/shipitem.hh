#ifndef SHIPITEM_HH
#define SHIPITEM_HH
#include "customitem.hh"
#include <QPixmap>
class ShipItem: public CustomItem
{
public:
    ShipItem(QPixmap pixmap_, Common::Point location = Common::Point(0,0));
};

#endif // SHIPITEM_HH
