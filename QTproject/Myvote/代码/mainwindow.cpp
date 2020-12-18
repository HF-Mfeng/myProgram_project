#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"registrationwindows.h"
#include"administratorlogin.h"
#include"userview.h"
#include"user.h"
#include"administrator.h"


#include<QRegExp>
#include<QRegularExpressionValidator>
#include<QPushButton>
#include<QTime>
#include<QString>
#include<QFileInfo>
#include<QFile>
#include<QDataStream>
#include<QDir>
#include<QMessageBox>
#include<QDate>
#include<QTextStream>

#include<QInputDialog>
#include<QLineEdit>
#include<QDialogButtonBox>

#include<QDebug>
#include<QPainter>
#include<QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//设置背景和标题
    setWindowTitle(QString("模拟投票小程序"));//字符串

    ui->enterBtn->resize(64,64);
    ui->enterBtn -> setStyleSheet("#enterBtn{border:0px ;}");
    ui->enterBtn -> setStyleSheet("#enterBtn{border-image:url(:/resource/dengluoff.png);}");
    connect(ui->enterBtn, &QPushButton::pressed ,[=](){
       ui->enterBtn -> setStyleSheet("#enterBtn{border-image:url(:/resource/dengluon.png);}");
    });
    connect(ui->enterBtn, &QPushButton::released, [=](){
        ui->enterBtn -> setStyleSheet("#enterBtn{border-image:url(:/resource/dengluoff.png);}");
    });

    ui->registeredBtn->resize(64,64);
    ui->registeredBtn -> setStyleSheet("#registeredBtn{border:0px ;}");
    ui->registeredBtn -> setStyleSheet("#registeredBtn{border-image:url(:/resource/zhuceoff.png);}");
    connect(ui->registeredBtn, &QPushButton::pressed ,[=](){
       ui->registeredBtn -> setStyleSheet("#registeredBtn{border-image:url(:/resource/zhuceon.png);}");
    });
    connect(ui->registeredBtn, &QPushButton::released, [=](){
        ui->registeredBtn -> setStyleSheet("#registeredBtn{border-image:url(:/resource/zhuceoff.png);}");
    });


   // this->setStyleSheet("#MainWindow{border-image:url(:/resource/Vote1.png);}");

//    QPixmap pix(300,300);
//    bool a =
//    pix.load(":/resource/Vote1.png");
//    qDebug () << a ;
//    ui->label->setGeometry(1,1,300,300);
//    ui->label->setPixmap(pix);



//------------------------------检测是否存在对应文件---------------------------//
    InitialCheck();


//设置密码和手机号码输入格式的
    QRegExp regx("1([0-9]+)");
    QRegExp regx1("([0-9]+)");
    QValidator *validator = new QRegExpValidator(regx,ui->phoneinput);
    QValidator *validator1 = new QRegExpValidator(regx1,ui->codeinput);
    ui->phoneinput->setValidator(validator);
    ui->codeinput->setValidator(validator1);
//设置密码和手机号码输入格式


    registrationWindows *reg = new registrationWindows(this);  //创建一个注册界面



//这里是点击主界面的注册按钮，然后进入注册的页面
    connect(ui->registeredBtn,&QPushButton::clicked,[=](){
        reg->show();
        beauty();
        this->hide();
    });

    connect(reg , &registrationWindows::registrationtomain,[=](){

        this->show();
        beauty();
        reg->close();
        reg->clearLineEdit();
        });//处理函数
//这里是注册界面返回到主界面的按钮信号

//--------------------用户注册并登录---------------------------//
    user *us = new user(nullptr);//--------------------------------------创造一个用户界面
    connect(reg,&registrationWindows::successRegistration,[=](){
        us->UserInitialization(reg->getPhone() );
        us->show();
        beauty();
        reg->close();
        reg->clearLineEdit();
    });

//这里是管理员登陆界面
    administratorlogin *admin = new administratorlogin();     //创建管理员登录界面
    connect(ui->administratorBtn,&QPushButton::clicked,[=](){
        admin->show();
        beauty();
        this->hide();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------测试期间提示密码--------------//
        {
            QFile *file = new QFile(QString("./data/administor.dat"));
            QDataStream stream(file);
            file->open(QIODevice::ReadOnly);
            int mycode ;
            stream >> mycode;
            file->close();
            QString str = str.number(mycode);
            QMessageBox *box= new QMessageBox();
            box->information(this , QString("提示🐖") , QString("测试期间，管理员密码是：")+str+QString("。您可以更改密码！"),QMessageBox::Ok ,QMessageBox::Ok);
            box->setButtonText(QMessageBox::Ok,QString("我知道了"));
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    });
    connect(admin ,&administratorlogin::backmain,[=](){
        this->show();
        beauty();
        admin->close();

    });      //----------------------------------------------------------这里是管理员登陆界面返回函数



//-----------这是管理员登录操作,ad代表管理员
     administrator *ad = new administrator();
     connect(admin , &administratorlogin::login,[=](){
            ad->administratorInitialization();
            ad->show();
            beauty();
            admin->close();
        });

     connect(ad,&administrator::backMain,[=](){
         this->show();
         beauty();
         ad->close();
         ad->deletCC();
     });

//-----------从管理员界面返回

//这里是进入用户界面注意检查密码，手机号的正确性
    connect(ui->enterBtn,&QPushButton::clicked,[=](){ //进入用户界面
        if(successlog(  ui->phoneinput->text()  ,  ui->codeinput->text()  ) ){
            us->UserInitialization( ui->phoneinput->text().toLongLong() );
            us->show();
            beauty();
            this->hide();
        }
   });
    connect(us,&user::exitlogin,[=](){               //点击返回按钮返回主窗口
        ui->codeinput->setText(QString(""));
        us->deleteCan();
        this->show();
        beauty();
        us->close();

    });




}//---------------------------------------------------------------------------------------------------------这里是构造函数终止的右括号








void MainWindow::InitialCheck(){          ///////函数的功能就是获取今天的时间，然后判断是否存在信息文件
    aDay = aDay.currentDate();//-----------获取今天的时间

    QDir dir;
    if(!dir.exists(QString("./data/"))){
        dir.mkdir(QString("./data/"));
    }

    {
        QFile *file = new QFile(QString("./data/users.dat"));
        if(!(file->exists())){
            QDataStream stream (file);
            file->open(QIODevice::WriteOnly);
            stream << 0;
            file->close();
        }}           ////////////////////人物大全的创建

    {
        QFile *file = new QFile(QString("./data/administor.dat"));
        if(!(file->exists())){
            QDataStream stream (file);
            file->open(QIODevice::WriteOnly);
            stream << 88888888 << 0 << 0 ;
            file->close();
        }}            //////////////////////管理员的创建


     {
        QFile *file = new QFile(QString("./data/activities.dat"));
        if(!(file->exists())){
            QDataStream stream (file);
            file->open(QIODevice::WriteOnly);
            stream << 0  ;
            file->close();
        }}            /////////////////////////活动大全的创建





}//-------------------------------------------------------------------------//





#include<QDebug>



///////检查是否正确登录
bool MainWindow::successlog(QString phone, QString code){           ///
    QFile *file = new QFile(PATH+phone+endPATH);
    if(!file->open(QIODevice::ReadOnly)){
        QMessageBox *box  = new QMessageBox();
        box->critical(this , QString("错误⚠") , QString("用户名不正确！！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok,QString("重试"));
        return false;
    }
    long long int myphone ;
    QString str;
    int mycode ;
    QDataStream stream(file);
    stream >> myphone >> str >> mycode;
    if(code.toInt() != mycode){
        QMessageBox *box  = new QMessageBox();
        box->critical(this , QString("错误⚠") , QString("密码不正确！！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok,QString("重试"));
        qDebug() << myphone << str << mycode ;
        return false;
    }
    return true;

}



void MainWindow::beauty(){
    QTime dietime = QTime::currentTime().addMSecs(200);
    while(QTime::currentTime()<dietime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

