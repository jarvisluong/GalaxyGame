#include "galaxy.hh"
#include "initialize.hh"
#include "igamerunner.hh"
#include "utility.hh"
#include "eventhandler.hh"
#include "mainwindow.hh"
#include "configdialog.hh"
#include "constants.hh"
#include <QApplication>
#include <memory>
#include <time.h>
#include <QDebug>

// TODO: ask TA why Student::Galaxy cannot be a property in MainWindow class
// Resolve now by static_cast- maybe not a good idea.
int main(int argc, char *argv[])
{
    int appExitCode;
    Common::utilityInit(time(NULL));
    do {
        QApplication a(argc, argv);

        std::shared_ptr<Common::IEventHandler> handler = std::make_shared<Student::EventHandler>();
        std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();
        MainWindow w;
        w.setGalaxy(galaxy.get());
        MainWindow::connect(galaxy.get(), SIGNAL(starSystemAddedAtCoordinates(std::shared_ptr<Common::StarSystem>)), &w, SLOT(addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem>)));
        std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);

        w.setEventHandler(handler);
        w.setGameRunner(gameRunner);
        Dialog configWindow;
        if(configWindow.exec()) {
            w.getGameRunner()->spawnShips(configWindow.getNumberOfShips());
            w.initPlayerShip();
            w.show();
            appExitCode = a.exec();
        } else {
            // If the user decides to close the configuration window
            appExitCode = 0;
        }
    //    Student::EventHandler* student_handler = dynamic_cast<Student::EventHandler*>(handler.get());


    } while (appExitCode == Constants::restartGameCode);
    return appExitCode;
}
