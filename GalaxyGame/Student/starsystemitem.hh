#ifndef STARSYSTEMITEM_HH
#define STARSYSTEMITEM_HH
#include "customitem.hh"
#include <QPixmap>
/*!
 * \brief The StarSystemItem class represent a star system image in the galaxy
 */
class StarSystemItem: public CustomItem
{
public:
    /*!
     * \brief StarSystemItem Constructor for the class, used the constructor from parent class.
     */
    StarSystemItem(QPixmap pixmap_, Common::Point location = Common::Point(0,0));
private:
    /*!
     * \brief mousePressEvent Event when click on a star system image.
     * \param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // STARSYSTEMITEM_HH
