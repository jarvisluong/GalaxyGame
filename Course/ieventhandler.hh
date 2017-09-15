#ifndef IEVENTHANDLER_HH
#define IEVENTHANDLER_HH

#include <string>
#include <memory>

namespace Common {

class Ship;
class StarSystem;
struct Point;

class IEventHandler
{
public:
    IEventHandler() = default;
    virtual ~IEventHandler() = default;

    virtual void shipSpawned(std::shared_ptr<Ship>) = 0;
    virtual void shipRemoved (std::shared_ptr<Ship>) = 0 ;
    virtual void shipMoved(std::shared_ptr<Ship>,Point, Point) = 0 ;
    virtual void shipRelocated(std::shared_ptr<Ship>, std::shared_ptr<StarSystem>) = 0;
    virtual void exceptionInExecution(std::shared_ptr<Ship>, std::string const&) = 0;
    virtual void distressOn(std::shared_ptr<Ship>) = 0 ;
    virtual void distressOff(std::shared_ptr<Ship>) = 0;
    virtual void shipAbandoned(std::shared_ptr<Ship>) = 0;
};

}

#endif // IEVENTHANDLER_HH
