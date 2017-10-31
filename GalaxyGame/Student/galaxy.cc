#include "galaxy.hh"

Student::Galaxy::Galaxy()
{

}

Student::Galaxy::~Galaxy()
{

}

void Student::Galaxy::addShip(std::shared_ptr<Common::Ship> ship)
{

}

void Student::Galaxy::removeShip(std::shared_ptr<Common::Ship> ship)
{

}

void Student::Galaxy::addStarSystem(std::shared_ptr<Common::StarSystem> starSystem)
{

}

std::shared_ptr<Common::IGalaxy::ShipVector> Student::Galaxy::getShips()
{
    std::shared_ptr<Common::IGalaxy::ShipVector> s;
    return s;
}

Common::StarSystem::StarSystemVector Student::Galaxy::getSystemsInRange(std::shared_ptr<Common::StarSystem> origin, int range)
{
    Common::StarSystem::StarSystemVector s;
    return s;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getRandomSystem()
{
    std::shared_ptr<Common::StarSystem> s;
    return s;
}

Common::IGalaxy::ShipVector Student::Galaxy::getShipsInStarSystem(std::string name)
{
    Common::IGalaxy::ShipVector s;
    return s;
}

std::vector<std::string> Student::Galaxy::getSystemNames()
{
    std::vector<std::string> s;
    return s;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getStarSystemByName(std::string name)
{
    std::shared_ptr<Common::StarSystem> s;
    return s;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getStarSystemById(unsigned id)
{
    std::shared_ptr<Common::StarSystem> s;
    return s;
}
