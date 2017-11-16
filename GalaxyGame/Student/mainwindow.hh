#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ieventhandler.hh"
#include "igamerunner.hh"
#include "galaxy.hh"
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
    ~MainWindow();

public slots:
    void addShipToGalaxyScene(int x, int y);
    void addStarSystemToGalaxyScene(int x, int y);
private slots:
    void on_endTurnBtn_clicked();
    void on_viewCreditsBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* galaxy_scene;
    QImage ship_image;
    QImage star_image;
    std::shared_ptr<Common::IEventHandler> handler;
    std::shared_ptr<Common::IGameRunner> gameRunner;
    Common::IGalaxy* galaxy;
};

#endif // MAINWINDOW_H
