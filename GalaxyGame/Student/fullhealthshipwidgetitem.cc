#include "fullhealthshipwidgetitem.hh"

FullHealthShipWidgetItem::FullHealthShipWidgetItem(const QString &text,
                                                   QListWidget *view,
                                                   int type): CustomListWidgetItem(text, view)

{
    this->setTextColor("green");
    this->setData(10, QVariant());
}
