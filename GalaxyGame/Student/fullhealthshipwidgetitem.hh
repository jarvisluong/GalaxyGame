#ifndef FULLHEALTHSHIPWIDGETITEM_HH
#define FULLHEALTHSHIPWIDGETITEM_HH
#include "customlistwidgetitem.hh"

class FullHealthShipWidgetItem: public CustomListWidgetItem
{
public:
    FullHealthShipWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
};

#endif // FULLHEALTHSHIPWIDGETITEM_HH
