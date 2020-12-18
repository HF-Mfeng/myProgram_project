#include "createactivity.h"
#include "ui_createactivity.h"


#include<QPushButton>
#include<QString>
#include<QFile>
#include<QDataStream>
#include<QDate>
#include<QMessageBox>

createActivity::createActivity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createActivity)
{
    ui->setupUi(this);



//-----------------点击了取消按钮的----------------//
    connect(ui->cancelbtn,&QPushButton::clicked,[=](){
       emit backAdministrator();
    });


//---------------点击了创建按钮-------------------//
    connect(ui->creatbtn,&QPushButton::clicked,[=](){
      if(this->checkSetting()){
         creatAnActivity();
         emit successCreat();
      }

    });

}//--------------------------------------------------------------------------------------------------------------------//


#include<QDebug>


//--------------------创建活动时对文件的操作--------------------------//
void createActivity::creatAnActivity(){
    QDate day1 = day1.currentDate();
    qDebug()<<"今天是"<<day1 ;
    int Code = 10000 + day1.day() + day1.month()*100;         //////////Code计算出活动的编码
    QFile *file = new QFile( PATH + QString("").number(Code) + endPATH );
    QDataStream stream(file);

    if(!file->open(QIODevice::WriteOnly)){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("没法创建活动") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那算了吧！"));
        return;
    }

    QString activityName ;
    QDate firstDate = ui->firstTime->date();
    QDate secondDate = ui->secondTime->date();
    QDate thirdDate = ui->thirdTime->date();
    QChar ifEveryDayCan ;
    int votes ;                                   ///记得后面补个零 , Code代表活动的编码
    if(ui->yesbtn->isChecked()){
        ifEveryDayCan = YES ;
    }else if(ui->nobtn->isChecked())
        ifEveryDayCan = NO ;

    votes = ui->setVotes->value();
    activityName = ui->lineEdit->text(); ////////////上面都是初始化的



    stream << Code << activityName << firstDate << secondDate << thirdDate << ifEveryDayCan << votes << 0 ;
    file->close();

    {
    QFile *file = new QFile(PATH + QString("activities.dat"));
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);

    int num;
    QDate one , two , three ;
    QString name;

    stream >> num ;
     num++ ;
     file->close();
     file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);
     stream << num ;
    for ( int i = 1; i < num ; i++ ) {
        int j ;
        stream >> j >> one >> two >> three ;
    }
    stream <<  Code << firstDate << secondDate << thirdDate ;

    file->close();
    }


    {
    QFile *file = new QFile(QString("./data/administor.dat"));
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);

    int code ;
    stream >> code ;

    stream << Code ;

    file->close();
    }


    return;
}






bool createActivity::checkSetting(){
    today = today.currentDate();

    if( !(ui->yesbtn->isChecked() || ui->nobtn->isChecked()) ){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("那个单选题没做") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我去做做"));
        return false;
    }

    if( ui->lineEdit->text() == QString("")){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("活动叫啥名啊") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("忘设置了"));
        return false;
    }

    if( ui->firstTime->date() < today){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("报名时间太早了趴") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我重新弄"));
        return false;
    }

    if( !(ui->firstTime->date() <= ui->secondTime->date() ) ){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("奇怪，报名时间比投票时间都晚") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我重新搞"));
        return false;
    }

    if(!(ui->secondTime->date() <= ui->thirdTime->date() )){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("结束时间不能比报名时间快") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我重新搞"));
        return false;
    }

    if( ui->setVotes->value() < 1 ){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("咋滴，每个人只能投0票呗？") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("我再设置"));
        return false;
    }

    QFile *file = new QFile( PATH + QString("activities.dat"));
    QDataStream stream(file);
    int number;
    QDate first ,second , third ;
    int code;
    file->open(QIODevice::ReadOnly);

    stream >> number;

    for (int i = 1 ; i <= number ; i++ ) {
        stream >> code >> first >>second >> third ;
    }

    file ->close();

    if(today<third){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("当前仍有活动没结束呢！，没法创建，你退出吧！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("走就走"));
        return false;
    }
    return true;
}


createActivity::~createActivity()
{
    delete ui;
}
