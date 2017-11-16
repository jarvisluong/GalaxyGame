#include "customlistwidgetitem.hh"

CustomListWidgetItem::CustomListWidgetItem(const QString &text, QListWidget *view, int type): QListWidgetItem(text, view)
{

}

void CustomListWidgetItem::setShipForWidgetItem(std::shared_ptr<Common::Ship> ship_)
{
    ship = ship_;
}

std::shared_ptr<Common::Ship> CustomListWidgetItem::getShipFromWidgetItem()
{
    return ship;
}
