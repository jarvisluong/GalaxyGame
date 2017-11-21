#include "buyhealthdialog.hh"
#include "ui_buyhealthdialog.h"


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

void BuyHealthDialog::setCreditsForText(int credits_, int health_)
{
    ui->credits_price_label->setText("You have " + QString::number(credits_) + " credits. Price: 5 credits for 1 health.");
    ui->healthspinBox->setMaximum(std::min(credits_ / 5, Constants::playerMaxHealth - health_));
    if(credits_ / 5 > Constants::playerMaxHealth - health_) {
//        ui->notificationLabel->setStyleSheet("QLabel {color: red}");
        QFont font;
        font.setBold(true);
        ui->notificationLabel->setFont(font);
        ui->notificationLabel->setText("*Maximum health is " + QString::number(Constants::playerMaxHealth) + ". Buy "
                                       + QString::number(Constants::playerMaxHealth - health_) + " is enough.");
        ui->notificationLabel->show();
    }
}

void BuyHealthDialog::on_buyButton_clicked()
{
    ui->notificationLabel->hide();
    emit on_buy_btn_clicked();
}

