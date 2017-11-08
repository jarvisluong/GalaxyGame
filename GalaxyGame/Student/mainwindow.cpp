#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(Constants::gameName);
    ui->gameNameLabel->setText(Constants::gameName);
    ui->authorLabel->setText(Constants::author);
    ui->versionLabel->setText(Constants::version);
}

MainWindow::~MainWindow()
{
    delete ui;
}
