#include "registrationwindows.h"
#include "ui_registrationwindows.h"
#include<QPushButton>
#include<QRegExp>
#include<QRegularExpressionValidator>
#include<QFile>
#include<QDataStream>
#include<QMessageBox>

#include<QDebug>
#include<QPixmap>
#include<QTimer>


registrationWindows::registrationWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationWindows)
{
    ui->setupUi(this);

    setWindowTitle("注册");

//////规定注册密码，手机号的格式
    QRegExp regx("1([0-9]+)");
    QValidator *validator = new QRegExpValidator(regx,ui->phoneinput);
    ui->phoneinput->setValidator(validator);

    QRegExp regx1("([0-9]+)");
    QValidator *validator1 = new QRegExpValidator(regx1,ui->codeinput);
    ui->codeinput->setValidator(validator1);
    QValidator *validator2 = new QRegExpValidator(regx1,ui->recodeinput);
    ui->recodeinput->setValidator(validator2);

//    QRegExp regx3("[a-zA-Z0-9]+");
//    QValidator *validator3 = new QRegExpValidator(regx3,ui->usernameinput);
//    ui->usernameinput->setValidator(validator3);
//////规定注册密码，手机号的格式
//    ui->backmainbtn->setIcon(pix);
//    ui->backmainbtn->setIconSize(QSize(25,25));
//    QPixmap pix ;
//    pix.load(":/resource/off.png");



    ui->backmainbtn -> setStyleSheet("#backmainbtn{border:0px ;}");
    ui->backmainbtn -> setStyleSheet("#backmainbtn{border-image:url(:/resource/off.png);}");
    ui->backmainbtn -> setFixedSize( 64,64 ) ;


    connect(
        
        ui->backmainbtn ,

        &QPushButton::pressed,

        [=](){
            ui->backmainbtn -> setStyleSheet("#backmainbtn{border-image:url(:/resource/on.png);}");
        }
    
    );



    connect(ui->backmainbtn ,&QPushButton::released, [=](){
        ui->backmainbtn -> setStyleSheet("#backmainbtn{border-image:url(:/resource/off.png);}");
    });

//////下面是连接按钮信号然后发送返回主窗口信号的
    connect(ui->backmainbtn,&QPushButton::clicked,[=](){
        emit registrationtomain();
    });



//---------------------注册并登录按钮--------------------//
    connect(ui->registrationbtn,&QPushButton::clicked,[=](){
       if(checkPhone(ui->phoneinput->text()) && checkCode(ui->codeinput->text(),ui->recodeinput->text())){
           if( ui->usernameinput->text() == QString("") ) {
               QMessageBox *box = new QMessageBox();
               box->information(this , QString("提示") , QString("请输入用户名") ,QMessageBox::Ok ,QMessageBox::Ok);
               box->setButtonText(QMessageBox::Ok , QString("我忘了，抱歉"));
               this->show();
           }else{
               {
                   QFile *file = new QFile(QString("./data/")+ui->phoneinput->text()+QString(".dat"));
                   QDataStream stream(file);
                   file -> open(QIODevice::WriteOnly);
                   stream << ui->phoneinput->text().toLongLong() << ui->usernameinput->text() << ui->codeinput->text().toInt()
                          << NOJOIN << 0 << 0 << 0 << 0 ; //活动编码《排名《票数《天数
                   file->close();

               }

               {
                   QFile *file = new QFile(QString("./data/users.dat"));
                   QDataStream stream(file);
                   file->open(  QIODevice:: ReadOnly | QIODevice::WriteOnly);
                   int number ;
                   stream >> number ;
                   for (int i = 1 ; i <= number ; i++) {
                       long long int readphone;
                       stream >> readphone ;
                       qDebug() << "已经注册的用户是：" << readphone ;
                   }

                   stream << ui->phoneinput->text().toLongLong();
                   qDebug() << "输入的用户是："<< (ui->phoneinput->text()).toLongLong() ;
                   file->close();
                   file->open( QIODevice:: ReadOnly | QIODevice::WriteOnly);
                   stream << (number+1) ;
                   file->close();
               }
//               ui->codeinput->setText(QString(""));
//               ui->recodeinput->setText(QString(""));
//               ui->usernameinput->setText(QString(""));
//               ui->phoneinput->setText(QString(""));
               emit successRegistration();
           }
       }else
           this->show();
    });



}

//-----------------这里是确认密码和验证密码输入正确的函数--------------------//
bool registrationWindows::checkCode(QString setCode, QString verifyCode){

    if(setCode!=verifyCode){

        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("两次密码输入不一致") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我再试试！"));
        return false;
    }

    int set = setCode.toUInt();
    if(set<1000){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("输入密码好短，一下就破开了") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我再试试！"));
        return false;
    }

    return true;
}//-----------------这里是确认密码和验证密码结束的函数---------------------//




//-----------这里是确认电话号码输入正确的函数---------------//
bool registrationWindows::checkPhone(QString phoneNumber){
    long long int phone = phoneNumber.toLongLong();

    if(phone < 10000000000){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("电话是11位的📞") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我再试试！"));
        return false;
    }

    QFile *file = new QFile(QString("./data/")+phoneNumber+QString(".dat"));
    QDataStream stream(file);
    if(file->open(QIODevice::ReadOnly)){
        QMessageBox *box = new QMessageBox();
        box->critical (this , QString("警告⚠") , QString("我这好像有这个用户了哟！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("那我再试试！"));
        file->close();
        return false;
    }
    return true;
}






long long int registrationWindows::getPhone(){
    return ui->phoneinput->text().toLongLong();
}







registrationWindows::~registrationWindows() //
{
    delete ui;
}



 void registrationWindows::clearLineEdit(){
     ui->phoneinput -> setText(QString("") );
     ui->codeinput -> setText(QString("") );
     ui->recodeinput -> setText(QString("") );
     ui->usernameinput->setText(QString(""));
     return ;
 }
