#include "gameoverdialog.hh"
#include "ui_gameoverdialog.h"

GameOverDialog::GameOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Game over!");
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

void GameOverDialog::on_no_button_clicked()
{
    reject();
}

void GameOverDialog::on_yes_button_clicked()
{
    accept();
}
