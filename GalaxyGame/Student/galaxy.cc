#include "galaxy.hh"
#include "objectnotfoundexception.hh"
#include <stdlib.h>
#include <algorithm>

Student::Galaxy::Galaxy()
{

}

Student::Galaxy::~Galaxy()
{
    // TODO: maybe delete all shared pointers to free memory???
}

void Student::Galaxy::addShip(std::shared_ptr<Common::Ship> ship)
{
    // TODO: Add check if the ship is already in the system
    _ships_in_galaxy.push_back(ship);
}

void Student::Galaxy::removeShip(std::shared_ptr<Common::Ship> ship)
{

}

void Student::Galaxy::addStarSystem(std::shared_ptr<Common::StarSystem> starSystem)
{
    // TODO: Add check if the star system is already in the system
    _star_systems_in_galaxy.push_back(starSystem);
}

std::shared_ptr<Common::IGalaxy::ShipVector> Student::Galaxy::getShips()
{
    auto ptr_ships = std::make_shared<Common::IGalaxy::ShipVector>(_ships_in_galaxy);
    return ptr_ships;
}

Common::StarSystem::StarSystemVector Student::Galaxy::getSystemsInRange(std::shared_ptr<Common::StarSystem> origin, int range)
{
    Common::StarSystem::StarSystemVector s;
    return s;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getRandomSystem()
{
    if (_star_systems_in_galaxy.size() == 0) {
        throw Common::ObjectNotFoundException("There is no star systems in the galaxy");
    }
    int random_index = rand() % _star_systems_in_galaxy.size();
    std::shared_ptr<Common::StarSystem> random = _star_systems_in_galaxy.at(random_index);
    return random;
}

Common::IGalaxy::ShipVector Student::Galaxy::getShipsInStarSystem(std::string name)
{
    Common::IGalaxy::ShipVector s;
    return s;
}

std::vector<std::string> Student::Galaxy::getSystemNames()
{
    std::vector<std::string> system_names;
    for (auto system : _star_systems_in_galaxy) {
        system_names.push_back(system->getName());
    }
    return system_names;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getStarSystemByName(std::string name)
{
    auto iter_found_system = std::find_if(
                                _star_systems_in_galaxy.begin(),
                                _star_systems_in_galaxy.end(),
                                [name](auto star_system) {
                                    return star_system->getName() == name;
                                   }
                                          );
    if (iter_found_system == _star_systems_in_galaxy.end()) {
        throw Common::ObjectNotFoundException("The Star System with the given name does not exist");
    }
    return &iter_found_system;
}

std::shared_ptr<Common::StarSystem> Student::Galaxy::getStarSystemById(unsigned id)
{
    auto iter_found_system = std::find_if(
                                _star_systems_in_galaxy.begin(),
                                _star_systems_in_galaxy.end(),
                                [id](auto star_system) {
                                    return star_system->getId() == id;
                                   }
                                          );
    if (iter_found_system == _star_systems_in_galaxy.end()) {
        throw Common::ObjectNotFoundException("The Star System with the given id does not exist");
    }
    return &iter_found_system;
}
