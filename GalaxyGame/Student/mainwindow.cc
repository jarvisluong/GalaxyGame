#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "constants.hh"
#include "creditsdialog.h"
#include "customitem.hh"
#include "customlistwidgetitem.hh"
#include "utilities.hh"
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

    galaxy_scene = new QGraphicsScene(Constants::sceneRect);
    galaxy_scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    ui->galaxyView->setScene(galaxy_scene);

    star_image.load("Assets/star.png");
    star_image = star_image.scaled(20, 20);

    initPlayerShip();

    connect(ui->viewCreditsBtn, SIGNAL(clicked(bool)), this, SLOT(on_viewCreditsBtn_clicked()));
    connect(_player_ship, SIGNAL(healthChanged(int)), this, SLOT(on_player_health_changed(int)));
    connect(_player_ship, SIGNAL(loseAllHealth()), this, SLOT(on_player_lose_all_health()));

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

void MainWindow::setGalaxy(Common::IGalaxy *galaxy_)
{
    assert_not_null(galaxy_);
    galaxy = galaxy_;
}

void MainWindow::updateListWidget(Common::IGalaxy::ShipVector ships)
{
        ui->shipListWidget->clear();
        for(int i = 0; i < ships.size(); i++) {
            ships[i]->getEngine()->decreaseHealth(5);
            QString ship_name = QString::fromStdString(ships[i]->getName());
            QString health = QString::number(ships[i]->getEngine()->getHealth());
            CustomListWidgetItem* item = new CustomListWidgetItem(ship_name + "; Health: " + health, ui->shipListWidget);
            if(!ships[i]->isAbandoned()) {
                item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                item->setCheckState(Qt::Unchecked);
            } else {
                item->setTextColor(QColor("red"));
            }
            item->setShipForWidgetItem(ships[i]);
            ui->shipListWidget->addItem(item);
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
    _player_ship = new Student::PlayerShip(Common::Point(0, 0));
    ui->healthLCDNumber->display(50);
    QGraphicsPixmapItem *ui_item = new QGraphicsPixmapItem(QPixmap::fromImage(ship_image));
    ui_item->setPos(500, 500);
    _player_ship->set_ui_item(ui_item);
    galaxy_scene->addItem(_player_ship->get_ui_item());
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem> starSystem)
{
    assert_not_null(starSystem.get());
    CustomItem* item = new CustomItem(QPixmap::fromImage(star_image));
    item->setNameForStarSystemItem(starSystem->getName());
    item->setLocationForStarSystemItem(starSystem->getCoordinates());
    int x = starSystem->getCoordinates().x;
    int y = starSystem->getCoordinates().y;
    transformCoordinates(x, y);
    item->setPos(x, y);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setGalaxyForStarSystemItem(static_cast<Student::Galaxy*> (galaxy));
    item->setMainWindowForStarSystemItem(this);
    galaxy_scene->addItem(item);
}

void MainWindow::on_endTurnBtn_clicked()
{
    gameRunner->createActions();
    gameRunner->doActions();
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
            customItem->setFlags(item->flags());
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
    buy_dialog->setCreditsForText(stat_info->getCreditBalance());
    buy_dialog->show();
}
