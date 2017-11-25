#ifndef NOTENOUGHHEALTHDIALOG_HH
#define NOTENOUGHHEALTHDIALOG_HH

#include "galaxy.hh"
#include <QDialog>

namespace Ui {
class NotEnoughHealthDialog;
}

class NotEnoughHealthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NotEnoughHealthDialog(QWidget *parent = 0);
    ~NotEnoughHealthDialog();
    void updateListWidget(Common::IGalaxy::ShipVector _ships);
private slots:
    void on_pushButton_clicked();

private:
    Ui::NotEnoughHealthDialog *ui;
};

#endif // NOTENOUGHHEALTHDIALOG_HH
