#ifndef BUYHEALTHDIALOG_HH
#define BUYHEALTHDIALOG_HH

#include "constants.hh"
#include <QDialog>

namespace Ui {
class BuyHealthDialog;
}

/*!
 * \brief The BuyHealthDialog class display the dialog for user to buy more health
 */
class BuyHealthDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief BuyHealthDialog constructor of this dialog
     * \param credits_ number of credits that player currently has
     * \param parent QWidget parent
     */
    explicit BuyHealthDialog(unsigned credits_, QWidget *parent = 0);

    ~BuyHealthDialog();

    /*!
     * \brief getNumberOfHealthToBuy get the number of health that player inputs to buy
     * \return
     */
    int getNumberOfHealthToBuy();

    /*!
     * \brief setCreditsForText hints the player about the amount of health they can buy
     * \param credits_ the amount of credits that player currently has
     * \param health_ the amount of health that player currently has
     */
    void setCreditsForText(int credits_, int health_);
signals:
    void on_buy_btn_clicked();

private slots:
    void on_buyButton_clicked();

private:
    Ui::BuyHealthDialog *ui;
};

#endif // BUYHEALTHDIALOG_HH
