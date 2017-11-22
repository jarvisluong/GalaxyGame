#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ieventhandler.hh"
#include "igamerunner.hh"
#include "galaxy.hh"
#include "playership.h"
#include "statistics.hh"
#include "buyhealthdialog.hh"
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
    /*!
     * \brief setEventHandler Sets the handler property.
     * \pre handler_ must not be NULL pointer.
     * \param handler_ The value to be set.
     */
    void setEventHandler(std::shared_ptr<Common::IEventHandler> handler_);

    /*!
     * \brief setGameRunner Sets the gameRunner property.
     * \pre gamerunner_ must not be NULL pointer.
     * \param gamerunner_ The value to be set.
     */
    void setGameRunner(std::shared_ptr<Common::IGameRunner> gamerunner_);

    /*!
     * \brief setGalaxy Sets the galaxy property.
     * \pre galaxy_ must not be NULL pointer.
     * \param galaxy_ The galaxy_ to be set.
     */
    void setGalaxy(Student::Galaxy* galaxy_);

    /*!
     * \brief getGameRunner Gets the gameRunner property.
     * \return gameRunner property of MainWindow.
     */
    std::shared_ptr<Common::IGameRunner> getGameRunner() const;

    /*!
     * \brief updateListWidget Updates the list of ships at a star system.
     * \param ships The ships that are in a star system.
     */
    void updateListWidget(Common::IGalaxy::ShipVector ships);
    void updatePlayerShipLocation(Common::Point new_location);
    void initPlayerShip();

    void setStarSystemLabel(std::string starSystemName);

    void setCurrentStarSystemNameForPlayableShip(std::string system_name);
    ~MainWindow();
public slots:
    /*!
     * \brief addStarSystemToGalaxyScene Adds a starSystem image to the MainWindow UI.
     * \pre starSystem must not be a NULL pointer.
     * \param starSystem The system to be added
     */
    void addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem> starSystem);
    void on_player_health_changed(int new_health);
    void on_player_lose_all_health();

private slots:
    void on_endTurnBtn_clicked();
    void on_viewCreditsBtn_clicked();
    void on_saveSelectedShipsBtn_clicked();
    void on_statistic_point_changed(unsigned new_point);
    void on_statistic_credit_changed(unsigned new_credit);
    void on_buy_health_dialog_button_clicked();
    void on_buyHealthBtn_clicked();

private:
    Ui::MainWindow *ui;
    Student::PlayerShip* _player_ship;
    QGraphicsScene* galaxy_scene;
    QImage ship_image;
    QImage star_image;
    std::shared_ptr<Common::IEventHandler> handler;
    std::shared_ptr<Common::IGameRunner> gameRunner;
    Student::Galaxy* galaxy;
    void transformCoordinates(int& x, int& y);
    Student::Statistics* stat_info;
    BuyHealthDialog* buy_dialog;
    std::string current_system_name;

};

#endif // MAINWINDOW_H
