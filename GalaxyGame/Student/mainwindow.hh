#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ieventhandler.hh"
#include "igamerunner.hh"
#include "galaxy.hh"
#include "playership.h"
#include "statistics.hh"
#include "buyhealthdialog.hh"
#include "gameoverdialog.hh"
#include "configdialog.hh"
#include "constants.hh"
#include "notenoughhealthdialog.hh"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QFile>
#include <QPair>
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

    /*!
     * \brief updatePlayerShipLocation updates the player ship location
     * \param new_location the new location of the player ship
     */
    void updatePlayerShipLocation(Common::Point new_location);

    /*!
     * \brief initPlayerShip initializes the player ship
     */
    void initPlayerShip();

    /*!
     * \brief setStarSystemLabel sets tex for star system label, which notifies user the system (s)he is currently at
     * \param starSystemName the name of the star system
     */
    void setStarSystemLabel(std::string starSystemName);

    /*!
     * \brief setCurrentStarSystemNameForPlayableShip sets the value for current_system_name property
     * \param system_name the name to be set
     */
    void setCurrentStarSystemNameForPlayableShip(std::string system_name);

    /*!
     * \brief user_wants_to_end_game exits game
     */
    void user_wants_to_end_game();

    /*!
     * \brief user_wants_to_continue_game re-initilizes the game
     */
    void user_wants_to_continue_game();
    ~MainWindow();
public slots:
    /*!
     * \brief addStarSystemToGalaxyScene Adds a starSystem image to the MainWindow UI.
     * \pre starSystem must not be a NULL pointer.
     * \param starSystem The system to be added
     */
    void addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem> starSystem);

    /*!
     * \brief on_player_health_changed Updates health information for the UI
     * \param new_health New health of the player
     */
    void on_player_health_changed(int new_health);

    /*!
     * \brief on_player_lose_all_health Updates health information to 0 and asks if user wants to play again
     */
    void on_player_lose_all_health();

private slots:
    /*!
     * \brief on_endTurnBtn_clicked Users end their turn, non-playable ships start to move
     */
    void on_endTurnBtn_clicked();

    /*!
     * \brief on_viewCreditsBtn_clicked Displays credit dialog
     */
    void on_viewCreditsBtn_clicked();

    /*!
     * \brief on_saveSelectedShipsBtn_clicked Save the ships user selected
     */
    void on_saveSelectedShipsBtn_clicked();

    /*!
     * \brief on_statistic_point_changed Updates point information for the UI
     * \param new_point New point of player
     */
    void on_statistic_point_changed(unsigned new_point);

    /*!
     * \brief on_statistic_credit_changed Updates credit information for the UI
     * \param new_credit New credit of player
     */
    void on_statistic_credit_changed(unsigned new_credit);

    /*!
     * \brief on_buy_health_dialog_button_clicked increases health and reduce credits
     */
    void on_buy_health_dialog_button_clicked();

    /*!
     * \brief on_buyHealthBtn_clicked Displays buy health dialog
     */
    void on_buyHealthBtn_clicked();

    /*!
     * \brief on_highScoreBtn_clicked Displays high score dialog
     */
    void on_highScoreBtn_clicked();

private:
    Ui::MainWindow *ui;
    /*!
     * \brief _player_ship The user's ship
     */
    Student::PlayerShip* _player_ship;

    /*!
     * \brief galaxy_scene scene for the game
     */
    QGraphicsScene* galaxy_scene;

    /*!
     * \brief ship_image image for player ship
     */
    QImage ship_image;

    /*!
     * \brief star_image image for star system
     */
    QImage star_image;

    /*!
     * \brief handler eventhandler for the game
     */
    std::shared_ptr<Common::IEventHandler> handler;

    /*!
     * \brief gameRunner
     */
    std::shared_ptr<Common::IGameRunner> gameRunner;

    /*!
     * \brief galaxy Galaxy property for the game
     */
    Student::Galaxy* galaxy;

    /*!
     * \brief transformCoordinates transform the current coordinates for better look in the UI
     * \param x The x coordinate
     * \param y The y coordinate
     */
    void transformCoordinates(int& x, int& y);

    /*!
     * \brief stat_info pointer to statistic class; which controls the player information
     */
    Student::Statistics* stat_info;

    /*!
     * \brief buy_dialog the buy health dialog
     */
    BuyHealthDialog* buy_dialog;

    /*!
     * \brief current_system_name System name that player is currently at
     */
    std::string current_system_name = "";

    /*!
     * \brief createTop10File creates new file to keep track of user's scores
     */
    void createTop10File();

    /*!
     * \brief writeToTop10File appends new point to the file
     * \param pointToAppend the point to be appended
     */
    void writeToTop10File(QString pointToAppend);

    /*!
     * \brief readFromTop10File reads from the file all user's scores
     * \return vector of user's scores
     */
    std::vector<QString> readFromTop10File();

    /*!
     * \brief checkIfUserHasEnoughHealth checks if user has enough health to save selected ships
     * \return bool value notifies whether user has enough health or not; ShipVector is the vector of ships that user chose to save
     */
    QPair<bool, Common::IGalaxy::ShipVector> checkIfUserHasEnoughHealth();
};

#endif // MAINWINDOW_H
