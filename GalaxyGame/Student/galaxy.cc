#include "galaxy.hh"
#include "objectnotfoundexception.hh"
#include "stateexception.hh"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

Student::Galaxy::Galaxy()
{

}

Student::Galaxy::~Galaxy()
{
    // TODO: maybe delete all shared pointers to free memory???
}

void Student::Galaxy::addShip(std::shared_ptr<Common::Ship> ship)
{
    auto iter_find_ship = std::find(_ships_in_galaxy.begin(), _ships_in_galaxy.end(), ship);
    if(iter_find_ship != _ships_in_galaxy.end()) {
        throw Common::StateException("The ship is already in the galaxy");
    }
    _ships_in_galaxy.push_back(ship);
}

void Student::Galaxy::removeShip(std::shared_ptr<Common::Ship> ship)
{
    auto iter_find_ship = std::find(_ships_in_galaxy.begin(), _ships_in_galaxy.end(), ship);
    if(iter_find_ship == _ships_in_galaxy.end()) {
        throw Common::ObjectNotFoundException("The ship is not in the galaxy");
    }
    _ships_in_galaxy.erase(iter_find_ship);
}

void Student::Galaxy::addStarSystem(std::shared_ptr<Common::StarSystem> starSystem)
{
    if (isSytemInGalaxy(starSystem)) {
        throw Common::StateException("System is already in the galaxy");
    }
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
    Common::IGalaxy::ShipVector _ships_in_star_system;
    auto iter_find_system_by_name = getStarSystemByName(name);
    for(auto iter_ship: _ships_in_galaxy) {
        if(iter_ship->getLocation()->getCoordinates() == iter_find_system_by_name->getCoordinates()) {
            _ships_in_star_system.push_back(iter_ship);
        }
    }
    return _ships_in_star_system;
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
    return *iter_found_system;
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
    return *iter_found_system;
}

bool Student::Galaxy::isSytemInGalaxy(std::shared_ptr<Common::StarSystem> starSystem)
{
    std::string name = starSystem->getName();
    auto id = starSystem->getId();
    Common::Point point = starSystem->getCoordinates();
    bool is_found_name_system = std::find_if(
                                _star_systems_in_galaxy.begin(),
                                _star_systems_in_galaxy.end(),
                                [name](auto star_system) {
                                    return star_system->getName() == name;
                                   }
                                          ) != _star_systems_in_galaxy.end();
    bool is_found_id_system = std::find_if(
                                _star_systems_in_galaxy.begin(),
                                _star_systems_in_galaxy.end(),
                                [id](auto star_system) {
                                    return star_system->getId() == id;
                                   }
                                          ) != _star_systems_in_galaxy.end();
    bool is_found_point_system = std::find_if(
                                _star_systems_in_galaxy.begin(),
                                _star_systems_in_galaxy.end(),
                                [point](auto star_system) {
                                    return star_system->getCoordinates() == point;
                                   }
                                          ) != _star_systems_in_galaxy.end();
    return is_found_id_system || is_found_name_system || is_found_point_system;
}
