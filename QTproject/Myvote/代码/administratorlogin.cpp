#include "administratorlogin.h"
#include "ui_administratorlogin.h"


#include<QPushButton>
#include<QRegExp>
#include<QRegularExpressionValidator>
#include<QFile>
#include<QDataStream>
#include<QString>
#include<QMessageBox>


administratorlogin::administratorlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administratorlogin)
{
    ui->setupUi(this);


//设置密码输入格式的
    QRegExp regx("([0-9]+)");
    QValidator *validator = new QRegExpValidator(regx,ui->lineEdit);
    ui->lineEdit->setValidator(validator);
//设置密码输入格式的

///////连接返回按钮，然后返回主窗口
    connect(ui->backbtn,&QPushButton::clicked,[=](){
       emit backmain();
    });

/////-----------------管理员登录管理员界面
    connect(ui->loginbtn,&QPushButton::clicked,[=](){
       if(checkMyCode())
           emit login();
    });

}

bool administratorlogin::checkMyCode(){
    QFile *file = new QFile( PATH + QString("administor") + endPATH );
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly);
    int mycode ;
    stream >> mycode;
    file->close();

    if( mycode != ui->lineEdit->text().toInt() ){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("密码不对哦！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("好的"));
        ui->lineEdit->setText(QString(""));
        return false;
    }
    ui->lineEdit->setText(QString(""));
    return true;

}

administratorlogin::~administratorlogin()
{
    delete ui;
}
