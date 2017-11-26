#ifndef ABANDONSHIPWIDGETITEM_HH
#define ABANDONSHIPWIDGETITEM_HH
#include "customlistwidgetitem.hh"

/*!
 * \brief The AbandonShipWidgetItem class displays the abandoned ships (which health is 0)
 */
class AbandonShipWidgetItem: public CustomListWidgetItem
{
public:
    /*!
     * \brief AbandonShipWidgetItem constructor which does similar to CustomListWidgetItem, but set the text color to red
     * \param text see CustomListWidgetItem documentation
     * \param view see CustomListWidgetItem documentation
     * \param type see CustomListWidgetItem documentation
     */
    AbandonShipWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
};

#endif // ABANDONSHIPWIDGETITEM_HH
