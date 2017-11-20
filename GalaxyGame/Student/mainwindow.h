#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    ~MainWindow();
    void addShipToGalaxyScene(int x, int y);
    void addStarSystemToGalaxyScene(int x, int y);
private:
    Ui::MainWindow *ui;
    QGraphicsScene* galaxy_scene;
    QImage ship_image;
    QImage star_image;
};

#endif // MAINWINDOW_H
