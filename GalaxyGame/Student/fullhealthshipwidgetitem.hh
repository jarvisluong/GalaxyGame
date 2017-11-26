#ifndef FULLHEALTHSHIPWIDGETITEM_HH
#define FULLHEALTHSHIPWIDGETITEM_HH
#include "customlistwidgetitem.hh"

/*!
 * \brief The FullHealthShipWidgetItem class displays the ships that have max health
 */
class FullHealthShipWidgetItem: public CustomListWidgetItem
{
public:
    /*!
     * \brief FullHealthShipWidgetItem constructor which does similar to CustomListWidgetItem, but set text color to green
     * \param text see CustomListWidget documentation
     * \param view see CustomListWidget documentation
     * \param type see CustomListWidget documentation
     */
    FullHealthShipWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);
};

#endif // FULLHEALTHSHIPWIDGETITEM_HH

