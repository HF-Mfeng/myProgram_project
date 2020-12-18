#include "changecode.h"
#include "ui_changecode.h"

#include<QPushButton>
#include<QString>
#include<QDataStream>
#include<QFile>
#include<QMessageBox>
#include<QRegExp>
#include<QRegularExpressionValidator>

changeCode::changeCode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeCode)
{
    ui->setupUi(this);

    QRegExp regx1("([0-9]+)");
    QValidator *validator = new QRegExpValidator(regx1,ui->uplineedit);
    ui->uplineedit->setValidator(validator);

    QValidator *validator2 = new QRegExpValidator(regx1,ui->midlineedit);
    ui->midlineedit->setValidator(validator2);

    QValidator *validator3 = new QRegExpValidator(regx1,ui->downlineedit);
    ui->downlineedit->setValidator(validator3);

    connect( ui->cancelBtn , &QPushButton::clicked , [=](){
        emit cancelBack();
    } );
    connect( ui->sureBtn , &QPushButton::clicked , [=](){
        emit yesBack();
    } );
}

changeCode::~changeCode()
{
    delete ui;
}

#include<QDebug>

bool changeCode::changeUser(){
    QFile *file = new QFile(QString("./data/") + QString("").number(thisPhone) + QString(".dat") );
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly);

    long long int a ;
    QString b ;
    int oldCode ;
    stream >> a >> b >> oldCode ;

    qDebug() << "类中的电话属性是：" << this->thisPhone ;

    qDebug() << "当前用户：" << a << "用户名" << b << "您当前密码是" << oldCode ;

    if( ui->uplineedit->text().toInt() != oldCode ){
        file->close();
        QMessageBox *box = new QMessageBox();
        box->warning(this , QString("警告⚠") , QString("原密码错误") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("重试"));
        return  false ;
    }

    if(ui->midlineedit->text() != ui->downlineedit->text() ){
        file->close();
        QMessageBox *box = new QMessageBox();
        box->warning( this , QString("警告⚠") , QString("两次密码不一致！！！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("重试"));
        return  false ;
    }

    if( ui->midlineedit ->text() == ui->uplineedit->text()){
        file->close();
        QMessageBox *box = new QMessageBox();
        box->warning(this , QString("警告⚠") , QString("新密码与原密码相同，请重试") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("重试"));
        return  false ;
    }

    file->close();
    file->open(QIODevice::WriteOnly|QIODevice::ReadOnly);
    stream >> a >> b ;
    stream << ( ui->downlineedit->text().toInt());
    file->close();

    QMessageBox *message = new QMessageBox(this);
    message -> information(this , QString("提示") ,QString("更改成功，将退出重新登录") , QMessageBox::Ok,QMessageBox::Ok);
    message -> setButtonText(QMessageBox::Ok , QString("确定"));


    return true ;
}


void changeCode::setPhone( long long phone ){
    this->thisPhone = phone ;
    return ;
}
void changeCode::init(){
    ui->uplineedit->setText(QString(""));
    ui->downlineedit->setText(QString(""));
    ui->midlineedit->setText(QString(""));
}


bool changeCode::changeAdministory(){
    QFile *file = new QFile(QString("./data/administor.dat"));
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly);
    int oldCode ;
    stream >> oldCode ;

    if( ui->uplineedit->text().toInt() != oldCode ){
        file->close();
        QMessageBox *box = new QMessageBox();
        box->warning(this , QString("警告⚠") , QString("原密码错误") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("重试"));
        return  false ;
    }

    if(ui->midlineedit->text() != ui->downlineedit->text() ){
        file->close();
        QMessageBox *box = new QMessageBox();
        box->warning(this , QString("警告⚠") , QString("两次密码不一致！！！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("重试"));
        return  false ;
    }

    if( ui->midlineedit ->text() == ui->uplineedit->text()){
        file->close();
        QMessageBox *box = new QMessageBox();
        box->warning(this , QString("警告⚠") , QString("新密码与原密码相同，请重试") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("重试"));

        return  false ;
    }

    file->close();


    file->open(QIODevice::WriteOnly|QIODevice::ReadOnly);

    stream << ( ui->downlineedit->text().toInt());

    file->close();
    {
        QMessageBox *message = new QMessageBox(this);
        message -> information(this , QString("提示") ,QString("更改成功，将退出重新登录") , QMessageBox::Ok,QMessageBox::Ok);
        message -> setButtonText(QMessageBox::Ok , QString("确定"));
    }
    return true;
}
