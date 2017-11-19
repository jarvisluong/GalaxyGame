#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ieventhandler.hh"
#include "igamerunner.hh"
#include "galaxy.hh"
#include "playership.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setEventHandler(std::shared_ptr<Common::IEventHandler> handler_);
    void setGameRunner(std::shared_ptr<Common::IGameRunner> gamerunner_);
    std::shared_ptr<Common::IGameRunner> getGameRunner() const;
    void setGalaxy(Common::IGalaxy* galaxy_);
    void updateListWidget(Common::IGalaxy::ShipVector ships);
    void initPlayerShip();
    ~MainWindow();
public slots:
    void addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem> starSystem);
private slots:
    void on_endTurnBtn_clicked();
    void on_viewCreditsBtn_clicked();
    void on_saveSelectedShipsBtn_clicked();

private:
    Ui::MainWindow *ui;
    Student::PlayerShip* _player_ship;
    QGraphicsScene* galaxy_scene;
    QImage ship_image;
    QImage star_image;
    std::shared_ptr<Common::IEventHandler> handler;
    std::shared_ptr<Common::IGameRunner> gameRunner;
    Common::IGalaxy* galaxy;
    void transformCoordinates(int& x, int& y);
};

#endif // MAINWINDOW_H
