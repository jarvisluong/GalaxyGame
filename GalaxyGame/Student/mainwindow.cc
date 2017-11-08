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

    galaxy_scene = new QGraphicsScene(QRect(0, 0, 1000, 1000));
    ui->galaxyView->setScene(galaxy_scene);

    ship_image.load("spaceship.png");
    star_image.load("star.png");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addShipToGalaxyScene(int x, int y)
{
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(ship_image));
    item->setPos(x, y);
    galaxy_scene->addItem(item);
}

void MainWindow::addStarSystemToGalaxyScene(int x, int y)
{
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(star_image));
    item->setPos(x, y);
    galaxy_scene->addItem(item);
}
