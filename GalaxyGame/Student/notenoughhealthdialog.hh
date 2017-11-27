#ifndef NOTENOUGHHEALTHDIALOG_HH
#define NOTENOUGHHEALTHDIALOG_HH

#include "galaxy.hh"
#include <QDialog>

namespace Ui {
class NotEnoughHealthDialog;
}

/*!
 * \brief The NotEnoughHealthDialog class displays when user tries to save ships but does not have enough health
 */
class NotEnoughHealthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NotEnoughHealthDialog(QWidget *parent = 0);
    ~NotEnoughHealthDialog();
    /*!
     * \brief updateListWidget updates the list widget display
     * \param _ships all the ships that user tries to save
     */
    void updateListWidget(Common::IGalaxy::ShipVector _ships);
private slots:
    /*!
     * \brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:
    Ui::NotEnoughHealthDialog *ui;
};

#endif // NOTENOUGHHEALTHDIALOG_HH
