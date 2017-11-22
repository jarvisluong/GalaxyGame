#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "constants.hh"
#include "creditsdialog.h"
#include "customlistwidgetitem.hh"
#include "utilities.hh"
#include "objectnotfoundexception.hh"
#include "normalshipwidgetitem.hh"
#include "abandonshipwidgetitem.hh"
#include "fullhealthshipwidgetitem.hh"
#include "starsystemitem.hh"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QListWidgetItem>
#include <QList>
using namespace Utilities;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(Constants::gameName);
    ui->gameNameLabel->setText(Constants::gameName);
    ui->authorLabel->setText(Constants::author);
    ui->versionLabel->setText(Constants::version);
    ui->shipListWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->buyHealthBtn->setEnabled(false);
    galaxy_scene = new QGraphicsScene(Constants::sceneRect);
    galaxy_scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    ui->galaxyView->setScene(galaxy_scene);

    star_image.load("Assets/star.png");
    star_image = star_image.scaled(20, 20);

    ship_image.load("Assets/spaceship.png");
    ship_image = ship_image.scaled(20, 20);
    connect(ui->viewCreditsBtn, SIGNAL(clicked(bool)), this, SLOT(on_viewCreditsBtn_clicked()));

    stat_info = new Student::Statistics();
    connect(stat_info, SIGNAL(on_point_changed(uint)), this, SLOT(on_statistic_point_changed(uint)));
    connect(stat_info, SIGNAL(on_credit_changed(uint)), this, SLOT(on_statistic_credit_changed(uint)));
    stat_info->addCredits(10);

    buy_dialog = new BuyHealthDialog(10);
    connect(buy_dialog, SIGNAL(on_buy_btn_clicked()), this, SLOT(on_buy_health_dialog_button_clicked()));
}

void MainWindow::setEventHandler(std::shared_ptr<Common::IEventHandler> handler_)
{    
    assert_not_null(handler_.get());
    handler = handler_;
}

void MainWindow::setGameRunner(std::shared_ptr<Common::IGameRunner> gamerunner_)
{
    assert_not_null(gamerunner_.get());
    gameRunner = gamerunner_;
}


std::shared_ptr<Common::IGameRunner> MainWindow::getGameRunner() const
{
    return gameRunner;
}

void MainWindow::setGalaxy(Student::Galaxy *galaxy_)
{
    assert_not_null(galaxy_);
    galaxy = galaxy_;
}

void MainWindow::updateListWidget(Common::IGalaxy::ShipVector ships)
{
        ui->shipListWidget->clear();
        for(int i = 0; i < ships.size(); i++) {
            QString ship_name = QString::fromStdString(ships[i]->getName());
            int current_ship_health = ships[i]->getEngine()->getHealth();
            if (current_ship_health == 0) {
                ships[i]->abandonShip();
            }
            QString health = QString::number(current_ship_health);
            if(!ships[i]->isAbandoned()) {
                if(ships[i]->getEngine()->getMaxHealth() == current_ship_health) {
                    FullHealthShipWidgetItem* item = new FullHealthShipWidgetItem(ship_name + "; Health: " + health, ui->shipListWidget);
                    item->setShipForWidgetItem(ships[i]);
                    ui->shipListWidget->addItem(item);
                } else {
                    NormalShipWidgetItem* item = new NormalShipWidgetItem(ship_name + "; Health: " + health, ui->shipListWidget);
                    item->setShipForWidgetItem(ships[i]);
                    ui->shipListWidget->addItem(item);
                }
            } else {
                AbandonShipWidgetItem* item = new AbandonShipWidgetItem(ship_name + "; Health: " + health, ui->shipListWidget);
                item->setShipForWidgetItem(ships[i]);
                ui->shipListWidget->addItem(item);
            }
        }
}

void MainWindow::updatePlayerShipLocation(Common::Point new_location)
{
    _player_ship->goToLocation(new_location);
    qDebug() << _player_ship->getLocation().x << ' ' << _player_ship->getLocation().y << endl;
}

void MainWindow::initPlayerShip()
{
    ship_image.load("Assets/spaceship.png");
    ship_image = ship_image.scaled(20, 20);
    _player_ship = new Student::PlayerShip(Constants::initialPlayerLocation);
    ui->healthLCDNumber->display(50);
    QGraphicsPixmapItem *ui_item = new QGraphicsPixmapItem(QPixmap::fromImage(ship_image));
    ui_item->setPos(500, 500);
    setStarSystemLabel(galaxy
                ->getStarSystemByLocation(Constants::initialPlayerLocation)
                ->getName()
    );
    _player_ship->set_ui_item(ui_item);
    galaxy_scene->addItem(_player_ship->get_ui_item());   
    connect(_player_ship, SIGNAL(healthChanged(int)), this, SLOT(on_player_health_changed(int)));
    connect(_player_ship, SIGNAL(loseAllHealth()), this, SLOT(on_player_lose_all_health()));

    // When window launches, non-playable ships should be moved so that they lose health
    // => able to save. Otherwise, user must press "End turn" before they actually play anything.
    gameRunner->createActions();
    gameRunner->doActions();
    //
}

void MainWindow::setStarSystemLabel(std::string starSystemName)
{
    ui->starSystemNameLabel->setText(QString::fromStdString(
                "You are at star system: "
                + starSystemName
                                         ));
}

void MainWindow::setCurrentStarSystemNameForPlayableShip(std::string system_name)
{
    current_system_name = system_name;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem> starSystem)
{
    assert_not_null(starSystem.get());
    StarSystemItem* item = new StarSystemItem(QPixmap::fromImage(star_image));
    item->setNameForItem(starSystem->getName());
    item->setLocationForItem(starSystem->getCoordinates());
    int x = starSystem->getCoordinates().x;
    int y = starSystem->getCoordinates().y;
    transformCoordinates(x, y);
    item->setPos(x, y);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setGalaxyForItem(galaxy);
    item->setMainWindowForItem(this);
    QString toolText = "Id: " + QString::number(starSystem->getId()) + "<br>" + "Name: " + QString::fromStdString(starSystem->getName()) + "<br>" +
            "Population: " + QString::number(starSystem->getPopulation());
    item->setToolTip(toolText);
    galaxy_scene->addItem(item);
}

void MainWindow::on_endTurnBtn_clicked()
{
    gameRunner->createActions();
    gameRunner->doActions();
    Common::IGalaxy::ShipVector ships_ = galaxy->getShipsInStarSystem(current_system_name);
    updateListWidget(ships_);
}

void MainWindow::on_viewCreditsBtn_clicked()
{
    CreditsDialog c;
    c.exec();
}

void MainWindow::transformCoordinates(int& x, int& y)
{
    x *= 21; y *= 21;
    // reference to Constants must be stated in Galaxy.pro => ask TA
    // x += Constants::sceneRect.width() / 2; y += Constants::sceneRect.height() / 2;
    x += 500; y += 500;
}

void MainWindow::on_saveSelectedShipsBtn_clicked()
{
    // update points, credits, health of player-ship, health of saved ships
    int tempPoint = 0, tempCredit = 0, tempMinusHealth = 0, numberOfSavedShips = 0;
    Common::IGalaxy::ShipVector ships_;
    for(int i = 0; i < ui->shipListWidget->count(); i++) {
        QListWidgetItem* item = ui->shipListWidget->item(i);
        CustomListWidgetItem* customItem = static_cast<CustomListWidgetItem*> (item);
        if(customItem->checkState()) {
            ships_.push_back(customItem->getShipFromWidgetItem());
            numberOfSavedShips++;
            int max_health = customItem->getShipFromWidgetItem()->getEngine()->getMaxHealth();
            int current_health = customItem->getShipFromWidgetItem()->getEngine()->getHealth();
            tempMinusHealth +=  max_health - current_health;
            customItem->getShipFromWidgetItem()->getEngine()->repair(max_health - current_health);

            QString name = QString::fromStdString(customItem->getShipFromWidgetItem()->getName());
            QString health = QString::number(max_health);
            customItem->setText(name + "; Health: " + health);
            customItem->setTextColor("green");
            customItem->setData(10, QVariant());
        }
    }

    // user may press save ships which already have max health- ignore these cases (tempMinusHealth=0)
    if(tempMinusHealth != 0) {
        tempPoint += numberOfSavedShips;
        tempCredit += 5*numberOfSavedShips + tempMinusHealth / 2;
        stat_info->addCredits(tempCredit);
        stat_info->addPoints(tempPoint);
        _player_ship->decreaseHealth(tempMinusHealth);
    }
}

void MainWindow::on_player_health_changed(int new_health)
{
    qDebug() << "updaing health" << new_health << endl;
    ui->healthLCDNumber->display(new_health);
    if(_player_ship->getHealth() >= 50) {
        ui->buyHealthBtn->setEnabled(false);
    } else {
        ui->buyHealthBtn->setEnabled(true);
    }
}

void MainWindow::on_player_lose_all_health()
{
    qDebug() << "You lose all health" << endl;
    ui->healthLCDNumber->display(0);
}

void MainWindow::on_statistic_point_changed(unsigned new_point)
{
    ui->pointLCDNumber->display(QString::number(new_point));
}

void MainWindow::on_statistic_credit_changed(unsigned new_credit)
{
    ui->creditLCDNumber->display(QString::number(new_credit));
}

void MainWindow::on_buy_health_dialog_button_clicked()
{
    _player_ship->increaseHealth(buy_dialog->getNumberOfHealthToBuy());
    stat_info->reduceCredits(buy_dialog->getNumberOfHealthToBuy() * 5);
    buy_dialog->close();
}

void MainWindow::on_buyHealthBtn_clicked()
{
    buy_dialog->setCreditsForText(stat_info->getCreditBalance(), _player_ship->getHealth());
    buy_dialog->show();
}
