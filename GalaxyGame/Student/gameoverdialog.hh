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
signals:
    void no_button_clicked();
    void yes_button_clicked();
private slots:
    void on_no_button_clicked();

    void on_yes_button_clicked();

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_HH
