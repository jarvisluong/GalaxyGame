#ifndef STARSYSTEMITEM_HH
#define STARSYSTEMITEM_HH
#include "customitem.hh"
#include "galaxy.hh"
#include "utilities.hh"
#include <QPixmap>
using namespace Utilities;
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
    /*!
     * \brief setGalaxyForItem Sets galaxy property for the class.
     * \pre galaxy_ must not be a NULL pointer.
     * \param galaxy_ The pointer to be set.
     */
    void setGalaxyForItem(Student::Galaxy* galaxy_);
private:
    /*!
     * \brief mousePressEvent Handlers the event when user clicks on a item
     * \param event
     */
     void mousePressEvent(QGraphicsSceneMouseEvent* event);

     Student::Galaxy* galaxy;

};

#endif // STARSYSTEMITEM_HH
