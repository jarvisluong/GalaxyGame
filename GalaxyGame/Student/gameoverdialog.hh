#ifndef GAMEOVERDIALOG_HH
#define GAMEOVERDIALOG_HH

#include <QDialog>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverDialog(QWidget *parent = 0);
    ~GameOverDialog();
private slots:
    /*!
     * \brief on_no_button_clicked executes when no button in the dialog clicked
     */
    void on_no_button_clicked();
    /*!
     * \brief on_yes_button_clicked executes when yes button in the dialog clicked
     */
    void on_yes_button_clicked();

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_HH
