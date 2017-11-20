#include "buyhealthdialog.hh"
#include "ui_buyhealthdialog.h"

//BuyHealthDialog::BuyHealthDialog(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::BuyHealthDialog)
//{
//    ui->setupUi(this);

//}

BuyHealthDialog::BuyHealthDialog(unsigned credits_, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BuyHealthDialog)
{
    ui->setupUi(this);
    ui->healthspinBox->setMaximum(credits_ / 5);
    ui->credits_price_label->setText("You have " + QString::number(credits_) + " credits. Price: 5 credits for 1 health.");
}

BuyHealthDialog::~BuyHealthDialog()
{
    delete ui;
}

int BuyHealthDialog::getNumberOfHealthToBuy()
{
    return ui->healthspinBox->value();
}

void BuyHealthDialog::setCreditsForText(int credits_)
{
    ui->credits_price_label->setText("You have " + QString::number(credits_) + " credits. Price: 5 credits for 1 health.");
    ui->healthspinBox->setMaximum(credits_ / 5);
}

void BuyHealthDialog::on_buyButton_clicked()
{
    emit on_buy_btn_clicked();
}
