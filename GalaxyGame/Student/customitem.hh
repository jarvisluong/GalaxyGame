#ifndef CUSTOMITEM_HH
#define CUSTOMITEM_HH

#include "galaxy.hh"
#include "mainwindow.hh"
#include <QGraphicsPixmapItem>
#include <QPixmap>

class CustomItem: public QGraphicsPixmapItem
{
public:
    /*!
     * \brief CustomItem Constructor for the class.
     * \param pixmap_ The pixmap (the image for the item).
     */
    CustomItem(QPixmap pixmap_);

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
    Student::Galaxy* galaxy;
    MainWindow* window;
    std::shared_ptr<Common::StarSystem> starSystem;
};

#endif // CUSTOMITEM_HH
