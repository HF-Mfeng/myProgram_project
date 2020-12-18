#include "threelabels.h"
#include "ui_threelabels.h"

threeLabels::threeLabels(QWidget *parent , QString left , QString mid ,QString right , int movex , int movey) :
    QWidget(parent),
    ui(new Ui::threeLabels)
{
    ui->setupUi(this);
    ui->leftlable->setText(left);
    ui->midlabel->setText(mid);
    ui->rightlabel->setText( right);
    this->move( movex , movey );
    this->show();
}

threeLabels::~threeLabels()
{
    delete ui;
}
