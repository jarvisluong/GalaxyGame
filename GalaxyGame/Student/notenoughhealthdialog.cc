#include "notenoughhealthdialog.hh"
#include "ui_notenoughhealthdialog.h"

NotEnoughHealthDialog::NotEnoughHealthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotEnoughHealthDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Warning!");
}

NotEnoughHealthDialog::~NotEnoughHealthDialog()
{
    delete ui;
}

void NotEnoughHealthDialog::updateListWidget(Common::IGalaxy::ShipVector _ships)
{
    for(int i = 0; i < _ships.size(); i++) {
        QString name = QString::fromStdString(_ships[i]->getName());
        QString curr_health = QString::number(_ships[i]->getEngine()->getHealth());
        QString max_health = QString::number(_ships[i]->getEngine()->getMaxHealth());
        QString s = name + "; " + "Current health: "+ curr_health + "; Max health: " + max_health;
        ui->savedShipsWidget->addItem(s);
    }
}

void NotEnoughHealthDialog::on_pushButton_clicked()
{
    accept();
}
