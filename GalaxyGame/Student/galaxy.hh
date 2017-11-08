#ifndef GALAXY_HH
#define GALAXY_HH
#include "igalaxy.hh"
#include "ship.hh"
#include "starsystem.hh"
#include "ieventhandler.hh"
#include "point.hh"
#include "mainwindow.hh"
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

    bool isSytemInGalaxy(std::shared_ptr<Common::StarSystem> starSystem);

signals:
    void shipAddedAtCoordinates(int x, int y);
    void starSystemAddedAtCoordinates(int x, int y);
private:
    ShipVector _ships_in_galaxy;
    Common::StarSystem::StarSystemVector _star_systems_in_galaxy;
};

}//Student

#endif // GALAXY_HH
