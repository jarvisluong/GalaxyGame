#include "galaxy.hh"
#include "initialize.hh"
#include "igamerunner.hh"
#include "utility.hh"
#include "eventhandler.hh"
#include "mainwindow.hh"
#include "dialog.hh"
#include <QApplication>
#include <memory>
#include <time.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<Common::IEventHandler> handler = std::make_shared<Student::EventHandler>();
    std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();

    Student::Galaxy* myGalaxy = galaxy.get();
    MainWindow w;
    MainWindow::connect(myGalaxy, SIGNAL(shipAddedAtCoordinates(int, int)), &w, SLOT(addShipToGalaxyScene(int,int)));
    MainWindow::connect(myGalaxy, SIGNAL(starSystemAddedAtCoordinates(int,int)), &w, SLOT(addStarSystemToGalaxyScene(int,int)));
    MainWindow::connect(&w, SIGNAL(), &w, SLOT(on_viewCreditsBtn_clicked()));
    std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);
    Common::utilityInit(time(NULL));

    w.setEventHandler(handler);
    w.setGameRunner(gameRunner);
    Dialog configWindow;
    if(configWindow.exec()) {
        w.getGameRunner()->spawnShips(configWindow.getNumberOfShips());
        w.show();
    }


    return a.exec();
}
