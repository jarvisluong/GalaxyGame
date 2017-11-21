#ifndef CUSTOMITEM_HH
#define CUSTOMITEM_HH

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
     * \brief setMainWindowForItem Sets the window property for the class.
     * \pre w_ must not be a NULL pointer.
     * \param w_ The window to be set.
     */
    void setMainWindowForItem(MainWindow* w_);

    /*!
     * \brief setNameForItem Sets the name property for the class.
     * \param name_ The name to be set.
     */
    void setNameForItem(std::string name_);

    /*!
     * \brief setLocationForStarSystemItem Sets the name property for the class.
     * \param location The location to be set.
     */
    void setLocationForItem(Common::Point location);

    /*!
     * \brief getLocation get the location property of the class.
     * \return the location of the class
     */
    Common::Point getLocation();

protected:
    std::string name;
    Common::Point _location;
    MainWindow* window;
};

#endif // CUSTOMITEM_HH
