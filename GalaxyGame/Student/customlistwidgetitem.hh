#ifndef CUSTOMLISTWIDGETITEM_HH
#define CUSTOMLISTWIDGETITEM_HH

#include "ship.hh"
#include <QListWidgetItem>
class CustomListWidgetItem: public QListWidgetItem
{
public:
    /*!
     * \brief CustomListWidgetItem Constructor for the class. This constructor uses the constructor from QListWidget item parent class.
     * \param text The text for the item.
     * \param view The view to add the item on.
     * \param type Optional parameter.
     */
    CustomListWidgetItem(const QString &text, QListWidget *view = Q_NULLPTR, int type = Type);

    /*!
     * \brief setShipForWidgetItem Sets ship property for the class.
     * \pre ship_ pointer to be set.
     * \param ship_ The ship pointer to be set.
     */
    void setShipForWidgetItem(std::shared_ptr<Common::Ship> ship_);

    /*!
     * \brief getShipFromWidgetItem Gets the ship property of the class.
     * \return shared_ptr to the ship property.
     */
    std::shared_ptr<Common::Ship> getShipFromWidgetItem();
protected:

    /*!
     * \brief ship is the ship that this item displays to player
     */
    std::shared_ptr<Common::Ship> ship;
};

#endif // CUSTOMLISTWIDGETITEM_HH
