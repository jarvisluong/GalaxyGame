#ifndef CUSTOMITEM_HH
#define CUSTOMITEM_HH

#include "galaxy.hh"
#include "mainwindow.hh"
#include "point.hh"
#include <QGraphicsPixmapItem>
#include <QPixmap>

class CustomItem: public QGraphicsPixmapItem
{
public:
    /*!
     * \brief CustomItem Constructor for the class.
     * \param pixmap_ The pixmap (the image for the item).
     * \param location The location of the item
     */
    CustomItem(QPixmap pixmap_, Common::Point location = Common::Point(0,0));

    /*!
     * \brief setGalaxyForStarSystemItem Sets galaxy property for the class.
     * \pre galaxy_ must not be a NULL pointer.
     * \param galaxy_ The pointer to be set.
     */
    void setGalaxyForStarSystemItem(Student::Galaxy* galaxy_);

    /*!
     * \brief setMainWindowForStarSystemItem Sets the window property for the class.
     * \pre w_ must not be a NULL pointer.
     * \param w_ The window to be set.
     */
    void setMainWindowForStarSystemItem(MainWindow* w_);

    /*!
     * \brief setNameForStarSystemItem Sets the name property for the class.
     * \param name_ The name to be set.
     */
    void setNameForStarSystemItem(std::string name_);

    /*!
     * \brief setLocationForStarSystemItem Sets the name property for the class.
     * \param location The location to be set.
     */
    void setLocationForStarSystemItem(Common::Point location);

    /*!
     * \brief getLocation get the location property of the class.
     * \return the location of the class
     */
    Common::Point getLocation();

    /*!
     * \brief setStarSystemForItem Sets the starSystem property for the class.
     * \pre star_ must not be a NULL pointer.
     * \param star_
     */
    void setStarSystemForItem(std::shared_ptr<Common::StarSystem> star_);
private:
    /*!
     * \brief mousePressEvent Handlers the event when user clicks on a starSystem
     * \param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    std::string name;
    Common::Point _location;
    Student::Galaxy* galaxy;
    MainWindow* window;
};

#endif // CUSTOMITEM_HH
