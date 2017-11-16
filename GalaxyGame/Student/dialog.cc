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
    return ui->numberOfShipsInput->value();
}

void Dialog::on_okBtn_clicked()
{
    accept();
}
