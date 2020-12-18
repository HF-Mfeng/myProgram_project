#include "userview.h"
#include "ui_userview.h"

#include<QString>

userview::userview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userview)
{
    ui->setupUi(this);
}

userview::userview(QWidget *parent ,long long int Qphone, int Qvotes , int Qranking ,double Qpercentage ) :
    QWidget(parent),
    ui(new Ui::userview)
{
    ui->setupUi(this);
    QString str ;

    str = str.number(Qphone);
    setphone(str);

    str = str.number(Qvotes);
    setvotes(str);

    str = str.number(Qranking);
    setranking(str);

    str = str.number(Qpercentage)+QString("%");
    setpercentage(str);

}

#include<QDebug>

userview::userview(QWidget *parent ,long long int Qphone, int Qvotes , int Qranking ,double Qpercentage ,int movex,int movey ) :
    QWidget(parent),
    ui(new Ui::userview)
{
    ui->setupUi(this);
    QString str ;

    str = str.number(Qphone);
    setphone(str);

    str = str.number(Qvotes);
    setvotes(str);

    str = str.number(Qranking);
    setranking(str);

    str = (str.number(Qpercentage,'f',2)+QString("%"));
    qDebug() << Qpercentage << QString("").number(Qpercentage) << "百分比的测试";
    setpercentage(str);

    this->move(movex,movey);
    connect(ui->votebtn , &QPushButton::clicked , [=](){
        ui->votebtn->hide();
        emit yes();
    });
}
void userview::addVotes(){
    setvotes(QString("").number(ui->votes->text().toInt()+1));
}




void userview::setphone(QString text){
    ui->phone->setText(text);
}
void userview::setvotes(QString text){
    ui->votes->setText(text);
}
void userview::setranking(QString text){
     ui->ranking->setText(text);
}
void userview::setpercentage(QString text){
     ui->percentage->setText(text);
}


userview::~userview()
{
    delete ui;
}
