#ifndef NORMALSHIPWIDGETITEM_HH
#define NORMALSHIPWIDGETITEM_HH
#include "customlistwidgetitem.hh"

class NormalShipWidgetItem: public CustomListWidgetItem
{
public:
    NormalShipWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
};

#endif // NORMALSHIPWIDGETITEM_HH
