#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "ship.hh"
#include "point.hh"
#include <QGraphicsPixmapItem>
#include <QObject>

namespace Student {
/*!
 * \brief The PlayerShip class
 */
class PlayerShip : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief PlayerShip constructor
     * \param initialLocation initial location for the ship to be put in the system
     * \param initialHealth initial health for the ship
     */
    PlayerShip(Common::Point initialLocation, int initialHealth = 50);

    /*!
     * \brief goToLocation this method makes the ship to change location in the system
     * \param nextLocation new location to move to
     */
    void goToLocation(Common::Point nextLocation);

    /*!
     * \brief decreaseHealth decrease health of the ship
     * \param amount amount of health to decrease
     */
    void decreaseHealth(int amount);

    /*!
     * \brief increaseHealth increase health of the ship
     * \param amount amount of health to increase
     */
    void increaseHealth(int amount);

    /*!
     * \brief getHealth get the current health of the ship
     * \return the health of the ship
     */
    int getHealth();

    /*!
     * \brief getLocation get the current location of the ship
     * \return the location of the ship
     */
    Common::Point getLocation();    

    /*!
     * \brief set_ui_item set the reference to the UI display item of the ship
     * \param item the pointer to the PixMap item of the ship
     */
    void set_ui_item(QGraphicsPixmapItem *item);

    /*!
     * \brief get_ui_item get the reference to the UI display item of the ship
     * \return the pointer to the PixMap item of the ship
     */
    QGraphicsPixmapItem *get_ui_item();

    void resetToInitialLocation();

signals:
    void healthChanged(int new_health);
    void loseAllHealth();

private:
    /*!
     * \brief invariant
     * \pre health always between 0 and Constants::playerMaxHealth
     */
    void invariant();

    /*!
     * \brief ui_item the pointer to the UI display item of the ship
     */
    QGraphicsPixmapItem* ui_item;

    /*!
     * \brief _location current location of the ship
     */
    Common::Point _location;

    /*!
     * \brief _health current health of the ship
     */
    int _health;
};
}

#endif // PLAYERSHIP_H
