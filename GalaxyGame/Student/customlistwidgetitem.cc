#include "customlistwidgetitem.hh"
#include "utilities.hh"
using namespace Utilities;
CustomListWidgetItem::CustomListWidgetItem(const QString &text, QListWidget *view, int type): QListWidgetItem(text, view)
{

}

void CustomListWidgetItem::setShipForWidgetItem(std::shared_ptr<Common::Ship> ship_)
{
    assert_not_null(ship_.get());
    ship = ship_;
}

std::shared_ptr<Common::Ship> CustomListWidgetItem::getShipFromWidgetItem()
{
    return ship;
}
