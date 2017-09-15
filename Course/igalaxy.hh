#ifndef IGALAXY_HH
#define IGALAXY_HH

#include "ship.hh"
#include "starsystem.hh"

#include <memory>
#include <vector>

namespace Common {

class IGalaxy
{

public:

    typedef std::vector<std::shared_ptr<Common::Ship>> ShipVector;

    IGalaxy() = default;
    virtual ~IGalaxy() = default;

    virtual void addShip(std::shared_ptr<Ship> ship) = 0;
    virtual void removeShip(std::shared_ptr<Ship> ship) = 0;
    virtual void addStarSystem(std::shared_ptr<StarSystem> system) = 0;
    virtual std::shared_ptr<ShipVector> getShips() = 0;
    virtual StarSystemVector getSystemsInRange(std::shared_ptr<StarSystem> origin, int range) = 0;
    virtual std::shared_ptr<StarSystem> getRandomSystem() = 0;
    virtual ShipVector getShipsInStarSystem(std::string name) = 0;
    virtual std::shared_ptr<Common::StarSystem> getStarSystemByName(std::string name) = 0 ;
    virtual std::shared_ptr<Common::StarSystem> getStarSystemById(unsigned id) = 0;
};
} //Common

#endif // IGALAXY_HH
