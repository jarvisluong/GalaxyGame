#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "constants.hh"
#include "creditsdialog.h"
#include "customitem.hh"
#include "customlistwidgetitem.hh"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QListWidgetItem>
#include <QList>
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
}

void MainWindow::setEventHandler(std::shared_ptr<Common::IEventHandler> handler_)
{
    handler = handler_;
}

void MainWindow::setGameRunner(std::shared_ptr<Common::IGameRunner> gamerunner_)
{
    gameRunner = gamerunner_;
}


std::shared_ptr<Common::IGameRunner> MainWindow::getGameRunner() const
{
    return gameRunner;
}

void MainWindow::setGalaxy(Common::IGalaxy *galaxy_)
{
    galaxy = galaxy_;
}

void MainWindow::updateListWidget(Common::IGalaxy::ShipVector ships)
{
    ui->shipListWidget->clear();

    for(int i = 0; i < ships.size(); i++) {
        QString ship_name = QString::fromStdString(ships[i]->getName());
        QString health = QString::number(ships[i]->getEngine()->getHealth());
        CustomListWidgetItem* item = new CustomListWidgetItem(ship_name + "; Health: " + health, ui->shipListWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
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
    _player_ship = new Student::PlayerShip(Common::Point(500, 500));
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
    qDebug() << "saved ships are below (for now we call decreaseHealth(2) for each ship because health == maxHealth): " << endl;
    for(int i = 0; i < ui->shipListWidget->count(); i++) {
        QListWidgetItem* item = ui->shipListWidget->item(i);
        CustomListWidgetItem* customItem = static_cast<CustomListWidgetItem*> (item);
        if(customItem->checkState()) {
            customItem->getShipFromWidgetItem()->getEngine()->decreaseHealth(2);
            qDebug() << QString::fromStdString(customItem->getShipFromWidgetItem()->getName()) << " " << QString::number(customItem->getShipFromWidgetItem()->getEngine()->getHealth()) << endl;
        }
    }
}
