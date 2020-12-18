#include "yigejiemian.h"
#include "ui_yigejiemian.h"

yigejiemian::yigejiemian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yigejiemian)
{
    ui->setupUi(this);
}

yigejiemian::~yigejiemian()
{
    delete ui;
}
