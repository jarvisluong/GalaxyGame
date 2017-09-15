#ifndef IGAMERUNNER_HH
#define IGAMERUNNER_HH

namespace Common {

class IGameRunner
{

public:

    IGameRunner() = default;
    virtual ~IGameRunner() = default;

    virtual void spawnShips(unsigned int count) = 0;
    virtual void createActions() = 0;
    virtual void doActions() = 0;
};
} //Common

#endif // IGAMERUNNER_HH
