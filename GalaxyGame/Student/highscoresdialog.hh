#ifndef HIGHSCORESDIALOG_HH
#define HIGHSCORESDIALOG_HH

#include <QDialog>
#include <QLabel>
namespace Ui {
class HighScoresDialog;
}

/*!
 * \brief The HighScoresDialog class Displays top 10 scores
 */
class HighScoresDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HighScoresDialog(QWidget *parent = 0);
    /*!
     * \brief setInformationForDialog displays top 10 scores to the dialog
     * \param points a vector that contains all the points user has achieved (no duplication)
     */
    void setInformationForDialog(std::vector<int> points);

    ~HighScoresDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HighScoresDialog *ui;
};

#endif // HIGHSCORESDIALOG_HH
