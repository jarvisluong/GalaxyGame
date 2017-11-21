#ifndef BUYHEALTHDIALOG_HH
#define BUYHEALTHDIALOG_HH

#include "constants.hh"
#include <QDialog>

namespace Ui {
class BuyHealthDialog;
}

class BuyHealthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuyHealthDialog(unsigned credits_, QWidget *parent = 0);
    ~BuyHealthDialog();
    int getNumberOfHealthToBuy();
    void setCreditsForText(int credits_, int health_);
signals:
    void on_buy_btn_clicked();

private slots:
    void on_buyButton_clicked();

private:
    Ui::BuyHealthDialog *ui;
};

#endif // BUYHEALTHDIALOG_HH
