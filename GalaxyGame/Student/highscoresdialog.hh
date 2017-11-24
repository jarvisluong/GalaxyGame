#ifndef HIGHSCORESDIALOG_HH
#define HIGHSCORESDIALOG_HH

#include <QDialog>
#include <QLabel>
namespace Ui {
class HighScoresDialog;
}

class HighScoresDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HighScoresDialog(QWidget *parent = 0);
    void setInformationForDialog(std::vector<int> points);
    void setTextForLabelWhenFileNotExists();
    ~HighScoresDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HighScoresDialog *ui;
};

#endif // HIGHSCORESDIALOG_HH
