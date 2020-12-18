#include "administorview.h"
#include "ui_administorview.h"

#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QFont>

administorview::administorview(QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::administorview)
{
    ui->setupUi(this);
    connect(ui->btnpass,&QPushButton::clicked,[=](){
        ui->btnpass->hide();
        emit yes();
    });

}

administorview::administorview(QWidget *parent , QString hisname , long long int hisphone , int movex ,int movey) :
    QWidget(parent),
    ui(new Ui::administorview)
{
    ui->setupUi(this);
    QString str ;

    str = str.number(hisphone);
    ui->labelusername->setText(hisname);
    ui->labeluserphone->setText(str);

    this->move(movex,movey);


    connect(ui->btnpass,&QPushButton::clicked,[=](){
        emit yes();
        ui->btnpass->hide();
    });


}

administorview::~administorview()
{
    delete ui;
}

threelabels::threelabels(QWidget *parent , QString anName , long long int aPhone , int givevotes , int movex ,int movey){
    this->setParent(parent);
    this->setGeometry(movex,movey,421,46);
    this->setFont(QFont(QString("楷书")));

    QString str ;

    QLabel *lab1 = new QLabel(this);
    lab1->setText(anName);
    lab1->setGeometry(0,0,160,46);
    lab1->show();

    QLabel *lab2 = new QLabel(this);
    lab2 ->setGeometry(160,0,160,46);
    str=str.number(aPhone);
    lab2->setText(str);
    lab2->show();

    QLabel *lab3 = new QLabel(this);
    lab3 ->setGeometry(320,0,160,46);
    str=str.number(givevotes);
    lab3->setText(str);
    lab3->show();

    this->show();
}

threelabels::threelabels(QWidget *parent , int rank ,long long int aPhone , int manyvotes , int movex ,int movey){
    this->setParent(parent);
    this->setGeometry(movex,movey,421,46);
    this->setFont(QFont(QString("楷书")));

    QString str ;

    QLabel *lab1 = new QLabel(this);
    lab1->setGeometry(0,0,160,46);
    str=str.number(rank);
    lab1->setText(str);
    lab1->show();

    QLabel *lab2 = new QLabel(this);
    lab2 ->setGeometry(160,0,160,46);
    str=str.number(aPhone);
    lab2->setText(str);
    lab2->show();

    QLabel *lab3 = new QLabel(this);
    lab3 ->setGeometry(320,0,160,46);
    str=str.number(manyvotes);
    lab3->setText(str);
    lab3->show();

    this->show();
}

threelabels::~threelabels(){
    delete this;
}
