#include "dialog.hh"
#include "ui_dialog.h"
#include <QString>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getNumberOfShips()
{
    return ui->numOfShipsTE->toPlainText().toInt();
}

void Dialog::on_okBtn_clicked()
{
    // TODO: check if the user inputs invalid number of ship
    accept();
}
