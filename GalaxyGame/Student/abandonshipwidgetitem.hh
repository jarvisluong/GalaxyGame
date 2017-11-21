#ifndef ABANDONSHIPWIDGETITEM_HH
#define ABANDONSHIPWIDGETITEM_HH
#include "customlistwidgetitem.hh"

class AbandonShipWidgetItem: public CustomListWidgetItem
{
public:
    AbandonShipWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
};

#endif // ABANDONSHIPWIDGETITEM_HH
