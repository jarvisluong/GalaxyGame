#ifndef CUSTOMLISTWIDGETITEM_HH
#define CUSTOMLISTWIDGETITEM_HH

#include "ship.hh"
#include <QListWidgetItem>
class CustomListWidgetItem: public QListWidgetItem
{
public:
    CustomListWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
    void setShipForWidgetItem(std::shared_ptr<Common::Ship> ship_);
    std::shared_ptr<Common::Ship> getShipFromWidgetItem();
private:
    std::shared_ptr<Common::Ship> ship;
};

#endif // CUSTOMLISTWIDGETITEM_HH
