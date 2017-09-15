#ifndef INITIALIZE_HH
#define INITIALIZE_HH

#include "igalaxy.hh"
#include "ieventhandler.hh"
#include "igamerunner.hh"

#include <memory>

namespace Common {
typedef std::function<std::shared_ptr<Common::Ship>(std::shared_ptr<Common::StarSystem>,
                                                    std::shared_ptr<Common::IEventHandler>)> BuildFunction;

std::shared_ptr<IGameRunner> getGameRunner(std::shared_ptr<IGalaxy> galaxy,
                                           std::shared_ptr<IEventHandler> handler);

void addNewShipType(std::string typeName, BuildFunction buildFunction);

} //Common

#endif // INITIALIZE_HH
