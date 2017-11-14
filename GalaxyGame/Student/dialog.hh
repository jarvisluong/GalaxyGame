#ifndef DIALOG_HH
#define DIALOG_HH

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    /*!
     * \brief getNumberOfShips returns the number of ships that user entered
     * \return the number of ships that the user entered. It should always be from 10 to
     */
    int getNumberOfShips();


private slots:
    void on_okBtn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_HH
