#ifndef GALAXY_HH
#define GALAXY_HH
#include "igalaxy.hh"
#include "ship.hh"
#include "starsystem.hh"
#include "ieventhandler.hh"
#include "point.hh"
#include "mainwindow.hh"
#include "constants.hh"
#include "playership.h"
#include <QObject>
namespace Student {

class Galaxy :  public QObject, public Common::IGalaxy, public std::enable_shared_from_this<Galaxy>
{
    Q_OBJECT
public:
    Galaxy();
    ~Galaxy();
    //IGalaxy
    virtual void addShip(std::shared_ptr<Common::Ship> ship);
    virtual void removeShip(std::shared_ptr<Common::Ship> ship);
    virtual void addStarSystem(std::shared_ptr<Common::StarSystem> starSystem);

    virtual std::shared_ptr<ShipVector> getShips();

    virtual Common::StarSystem::StarSystemVector getSystemsInRange
    (std::shared_ptr<Common::StarSystem> origin, int range);
    virtual std::shared_ptr<Common::StarSystem> getRandomSystem();

    ShipVector getShipsInStarSystem(std::string name);
    std::vector<std::string> getSystemNames();
    std::shared_ptr<Common::StarSystem> getStarSystemByName(std::string name);
    std::shared_ptr<Common::StarSystem> getStarSystemById(unsigned id);

    /**
     * @brief getStarSystemByLocation gets an instance of the star system by location
     * @param location Location of the star system
     * @return Shared pointer to the object of the star system
     * @exception ObjectNotFoundException, if the star system with given location does not exist
     * @post Exception guarantee: strong
     */
    std::shared_ptr<Common::StarSystem> getStarSystemByLocation(Common::Point location);
    /*!
     * \brief Checks if a star system is in the galaxy.
     * \param starSystem The star system that needs to be checked.
     * \return true if star system is in the galaxy; false otherwise.
     */
    bool isSytemInGalaxy(std::shared_ptr<Common::StarSystem> starSystem);

signals:
    /*!
     * \brief signal that notifies a starSystem has been added to the galaxy.
     * \param starSystem The starSystem that was added.
     */
    void starSystemAddedAtCoordinates(std::shared_ptr<Common::StarSystem> starSystem);

private:
    /*!
     * \brief _ships_in_galaxy Contains all the ships in the galaxy
     */
    // TODO: decide whether this contains playable ship or not
    ShipVector _ships_in_galaxy;
    /*!
     * \brief _star_systems_in_galaxy Contains all the star systems in the galaxy
     */
    Common::StarSystem::StarSystemVector _star_systems_in_galaxy;
};

}//Student

#endif // GALAXY_HH
