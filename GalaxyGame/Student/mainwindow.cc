#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "constants.hh"
#include "creditsdialog.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include "customitem.hh"
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


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::addStarSystemToGalaxyScene(std::shared_ptr<Common::StarSystem> starSystem)
{
    CustomItem* item = new CustomItem(QPixmap::fromImage(star_image));
    item->setNameForStarSystem(starSystem->getName());
    int x = starSystem->getCoordinates().x;
    int y = starSystem->getCoordinates().y;
    transformCoordinates(x, y);
    item->setPos(x, y);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setGalaxyWindow(static_cast<Student::Galaxy*> (galaxy));
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
