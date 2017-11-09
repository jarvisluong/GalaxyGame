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
    int getNumberOfShips();


private slots:
    void on_okBtn_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_HH
