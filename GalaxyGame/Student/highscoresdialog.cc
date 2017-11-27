#include "highscoresdialog.hh"
#include "ui_highscoresdialog.h"
#include "constants.hh"
HighScoresDialog::HighScoresDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScoresDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("High Scores");
}

void HighScoresDialog::setInformationForDialog(std::vector<int> points)
{
    if(points.size() == 0) {
        ui->label->setText(Constants::no_points_to_show);
        return;
    }
    ui->label->setText(Constants::your_top_10);
    int k = 0;
    ui->label_1->setText("Point 1: " + QString::number(points[0])); k++;
    if(k == points.size()) return;
    ui->label_2->setText("Point 2: " + QString::number(points[1])); k++;
    if(k == points.size()) return;
    ui->label_3->setText("Point 3: " + QString::number(points[2])); k++;
    if(k == points.size()) return;
    ui->label_4->setText("Point 4: " + QString::number(points[3])); k++;
    if(k == points.size()) return;
    ui->label_5->setText("Point 5: " + QString::number(points[4])); k++;
    if(k == points.size()) return;
    ui->label_6->setText("Point 6: " + QString::number(points[5])); k++;
    if(k == points.size()) return;
    ui->label_7->setText("Point 7: " + QString::number(points[6])); k++;
    if(k == points.size()) return;
    ui->label_8->setText("Point 8: " + QString::number(points[7])); k++;
    if(k == points.size()) return;
    ui->label_9->setText("Point 9: " + QString::number(points[8])); k++;
    if(k == points.size()) return;
    ui->label_10->setText("Point 10: " + QString::number(points[9]));
}
HighScoresDialog::~HighScoresDialog()
{
    delete ui;
}

void HighScoresDialog::on_pushButton_clicked()
{
    accept();
}

