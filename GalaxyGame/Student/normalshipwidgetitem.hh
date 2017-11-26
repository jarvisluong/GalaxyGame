#ifndef NORMALSHIPWIDGETITEM_HH
#define NORMALSHIPWIDGETITEM_HH
#include "customlistwidgetitem.hh"

/*!
 * \brief The NormalShipWidgetItem class displays the ships that have 0 < health < max_health
 */
class NormalShipWidgetItem: public CustomListWidgetItem
{
public:
    /*!
     * \brief NormalShipWidgetItem constructor which does similar to CustomListWidgetItem, but set the item to be checkable
     * \param text see CustomListWidget documentation
     * \param view see CustomListWidget documentation
     * \param type see CustomListWidget documentation
     */
    NormalShipWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
};

#endif // NORMALSHIPWIDGETITEM_HH
