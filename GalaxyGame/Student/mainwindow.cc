#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "constants.hh"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(Constants::gameName);
    ui->gameNameLabel->setText(Constants::gameName);
    ui->authorLabel->setText(Constants::author);
    ui->versionLabel->setText(Constants::version);

    galaxy_scene = new QGraphicsScene(Constants::sceneRect);
    galaxy_scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    ui->galaxyView->setScene(galaxy_scene);

    ship_image.load("Assets/spaceship.png");
    ship_image = ship_image.scaled(20, 20);
    star_image.load("Assets/star.png");
    star_image = star_image.scaled(20, 20);

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


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addShipToGalaxyScene(int x, int y)
{
    qDebug() << "add a ship at " << x << " " << y << endl;
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(ship_image));
    item->setPos(x, y);
    galaxy_scene->addItem(item);
}

void MainWindow::addStarSystemToGalaxyScene(int x, int y)
{
    qDebug() << "add a star system at " << x << " " << y << endl;
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(star_image));
    item->setPos(x, y);
    galaxy_scene->addItem(item);
}

void MainWindow::on_endTurnBtn_clicked()
{
    gameRunner->createActions();
    gameRunner->doActions();
}
