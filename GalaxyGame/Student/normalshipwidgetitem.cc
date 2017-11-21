#include "normalshipwidgetitem.hh"


NormalShipWidgetItem::NormalShipWidgetItem(const QString &text,
                                           QListWidget *view,
                                           int type): CustomListWidgetItem(text, view)
{
    this->setFlags(this->flags() | Qt::ItemIsUserCheckable);
    this->setCheckState(Qt::Unchecked);
}
