#include "abandonshipwidgetitem.hh"



AbandonShipWidgetItem::AbandonShipWidgetItem(const QString &text,
                                             QListWidget *view,
                                             int type): CustomListWidgetItem(text, view)
{
    this->setTextColor("red");
}
