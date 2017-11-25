#include "creditsdialog.h"
#include "ui_creditsdialog.h"
#include "constants.hh"

CreditsDialog::CreditsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Credits");
    ui->starImageCredit->setText(Constants::star_image_author);
}

CreditsDialog::~CreditsDialog()
{
    delete ui;
}
