#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
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
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addShipToGalaxyScene(int x, int y)
{

}

void MainWindow::addStarSystemToGalaxyScene(int x, int y)
{

}
