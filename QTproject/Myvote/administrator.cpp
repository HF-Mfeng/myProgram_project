#include "administrator.h"
#include "ui_administrator.h"
#include"userview.h"
#include"createactivity.h"
#include"mainwindow.h"
#include"administorview.h"
#include"threelabels.h"
#include"changecode.h"



#include<QPushButton>
#include<QRegExp>
#include<QRegularExpressionValidator>
#include<QScrollArea>
#include<QDialog>
#include<QString>
#include<qlineedit.h>
#include<QTime>
#include<QFile>
#include<QDataStream>
#include<QDate>


administrator::administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);

    setWindowTitle(QString("管理员,您好！"));



    page=1; //////////////////////初始化上半部分的显示
    ui->labelupleft->setText(QString("用户名"));
    ui->labelupright->setText(QString("投票次数"));


    connect(ui->backmainbtn,&QPushButton::clicked,[=](){    //点击返回按钮返回主函数的
       emit backMain();
    });

//---------------管理员更改密码--------------//
    changeCode *change = new changeCode();
    connect(ui->changecodebtn ,&QPushButton::clicked , [=](){
        change->show();
        beauty();
        this->hide();
    });
    connect(change , &changeCode::yesBack , [=](){
        if(change->changeAdministory()){
            change->close();
            emit backMain();
        }
    });
    connect(change , &changeCode::cancelBack ,[=](){
        this->show();
        beauty();
        change->close();
        change->init();
    });
//---------------管理员更改密码--------------//



//--------------管理员点击创建活动---------------------------------------//
    createActivity *anActivity = new createActivity();
    connect(ui->creatbtn,&QPushButton::clicked,[=](){
        anActivity->show();
        beauty();
        this->hide();
    });
//------------------------下面是从活动创建界面返回且是没有创建活动的-----------------------//
    connect(anActivity,&createActivity::backAdministrator,[=](){
        this->show();
        beauty();
        anActivity->close();
    });

//-----------------------下面是创建了活动然后返回的--------------------------------------//
    connect(anActivity,&createActivity::successCreat,[=](){
        this->show();
        beauty();
        anActivity->close();
    });

}//该构造函数结束处-----------------------------------------------------------------------



#include<QDebug>


#include<QDebug>
////////////////////这个不要删除，这个有用的
QString administrator::getUserName( long long int userPhone ) {
    QFile *file = new QFile( PATH + QString("").number(userPhone) + endPATH );
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly);

    long long int a ;
    QString name ;
    stream >> a >> name ;
    file->close();
    return  name;
}

void administrator::beauty(){
    QTime dietime = QTime::currentTime().addMSecs(200);
    while(QTime::currentTime()<dietime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

administrator::~administrator()
{
    delete ui;
}



int administrator::heVotesToHer(long long hisphone){
    QFile *file = new QFile( PATH + QString("").number(hisphone) + endPATH );
    QDataStream stream(file);
    file -> open( QIODevice:: ReadOnly);
    long long int a ; QString b ; int c ;QChar d;
    int e , f , g , information ;
    stream >> a >> b >> c >> d >> e >> f >> g >>information ;
    file -> close();
    return information ;
}

//2 is 用户名 手机号码 投票数
//1 is 排名   手机号码  票数

void administrator::showWhichPage(int WhichPage){
    switch (WhichPage) {
    case 1:{
        QWidget *connent = new QWidget(ui->contentUp );
        connent -> setGeometry(0 , 32 , 419 , 900 );
        connent -> show();
        QFile *file = new QFile( PATH + QString("").number(this->thisActivityCode) + endPATH );
        QDataStream stream(file);
        file->open(QIODevice::ReadOnly);
        int a ;
        QString b;
        QDate c ,d ,e ;
        QChar f;
        int g , number ;
        stream >> a >> b >>c >>d >>e >> f >> g >> number ;
        PeoPle human[number];
        for ( int i = 0 ; i < number ; i++ ) {
            long long readPhone ;
            int readVotes ;
            stream >> readPhone >> readVotes ;
            human[i].phone = readPhone ;
            human[i].votes = readVotes ;
            human[i].rangking = 0 ;
        }
        file->close();
        rankVotes( human , number );
        for ( int i = 1 ; i <= number ; i++ ) {

            threeLabels *one = new threeLabels(ui->contentUp ,///////////这里我改了，看有没有问题
                                               QString("").number(human[i-1].rangking) ,
                                               QString("").number(human[i-1].phone) ,
                                               QString("").number(human[i-1].votes) ,
                                                0 , 43*(i-1) );
        }





    }
        break;
    case 2:{
        QWidget *connent = new QWidget(ui->contentUp );
        connent -> setGeometry(0 , 32 , 419 , 900 );
        connent -> show();
        QFile *file = new QFile( QString("./data/users.dat") );
        QDataStream stream(file);
        file->open(QIODevice::ReadOnly);
        int number ;
        stream >> number ;

        for (int i = 1; i <= number ; i++ ) {

            long long readphone ;
            stream >> readphone ;
            qDebug() << readphone << "," << i << "次";
            threeLabels *one = new threeLabels(connent ,///////////这里我改了，看有没有问题
                                               getUserName(readphone) ,
                                               QString("").number(readphone) ,
                                               QString("").number(heVotesToHer(readphone)) ,
                                                0 , 43*(i-1) );

        }
        file->close();

    }
        break;
    }
}















//// ----------------------------下面是初始化管理员的全部内容------------------------------------------//
void administrator::administratorInitialization(){
    Today = Today.currentDate();//初始化今天的日子
    QFile *checkActivity = new QFile(QString("./data/activities.dat"));
    QDataStream ActivityStream(checkActivity);
    checkActivity->open(QIODevice::ReadOnly);
    int activityNumber , activityCode ; //活动数量和活动编码
    QDate activityFirstDate , activitySeconeDate , activityThirdDate ;
    ActivityStream >> activityNumber;

    //并且这里需要连接一下切换页面的函数
    qDebug()<< "I am the adminittator !!r" ;
    ui->labelupleft->setText(QString("用户名"));
    ui->labelupright->setText(QString("已投票数"));
    showWhichPage(2);/////这里加上页面用户名 ，手机号码和投票数
//    connect(ui->pagechange,&QPushButton::clicked,[=](){
//       if(page == 2){
//           ui->labelupleft->setText(QString("用户名"));
//           ui->labelupright->setText(QString("投票次数"));
//           showWhichPage(2);/////这里加上页面用户名 ，手机号码和投票数
//           page = 1;
//       }else if (page == 1) {
//           ui->labelupleft->setText(QString("排名"));
//           ui->labelupright->setText(QString("票数"));
//           showWhichPage(1);//这里加上投票信息，我觉得和那个用户界面的一样，可以直接拿来用
//           page = 2;
//       }
//    });
///////////////////////////////////////////////////////////////////////////////////////////////////////////


    if(activityNumber == 0 )     ///没有创建过活动
       return ;

    for (int i = 1; i <= activityNumber; i++) {
        ActivityStream >> activityCode >> activityFirstDate >>activitySeconeDate >> activityThirdDate ;
    }
    checkActivity->close();
    this -> thisActivityCode = activityCode ;

    {
        QFile *file = new QFile( PATH + QString("").number(activityCode) + endPATH );
        QDataStream stream(file);
        file->open(QIODevice::ReadOnly);
        QString ActivitName ;                                                                                                         //
        QDate firstDate;                                                                                                              //
        QDate secondDate;                                                                                                             //
        QDate thirdDate;                                                                                                              //
        QChar ifEveryDayCan ;                                                                                                         //
        int howManyVotes;                                                                                                             //
        stream >> activityCode                                                                                                       //
               >> ActivitName                                                                                                         //
               >> firstDate                                                                                                           //
               >> secondDate                                                                                                          //
               >> thirdDate                                                                                                           //
               >> ifEveryDayCan                                                                                                       //
               >> howManyVotes;
        file->close();

//---------------------下面是判断“今天”是哪一天，活动之前还是之后-------------------------//                                                                     //
        if(Today<firstDate){   /////////////活动之前，但是有活动发布                                                                        //
                                                                                                  //
        }else {                                                                                                                          //
            if(Today>=firstDate && Today<=secondDate ){ ///////////////报名环节
                whetherPass();//这里显示审核的东西-----------------------------------------------
            }else {                                                                                                                       //
                if(Today>=secondDate && Today<=thirdDate){ /////////////////投票环节                                                       //
//                    connect(ui->pagechange,&QPushButton::clicked,[=](){
//                       if(page == 2){
//                           ui->labelupleft->setText(QString("用户名"));
//                           ui->labelupright->setText(QString("投票次数"));
//                           showWhichPage(2);/////这里加上页面用户名 ，手机号码和投票数
//                           page = 1;
//                       }else if (page == 1) {
//                           ui->labelupleft->setText(QString("排名"));
//                           ui->labelupright->setText(QString("票数"));
//                           showWhichPage(1);//这里加上投票信息，我觉得和那个用户界面的一样，可以直接拿来用
//                           page = 2;
//                       }
//                    });//这里显示信息-----------------------------------------------------
                }else{                                                                                                                 //
//这里发布信息，不过我觉得没必要-------------------------------------                                                                           //
                }                                                                                                                      //
            }                                                                                                                          //
        }                                                                                                                              //
    } //////////////打开对应活动，读取文件即可的结束处
}








//------------这个其实是显示，另外创建函数进行文件操作-------------------------//
void administrator::whetherPass(  ){
    cc = new QWidget(this->ui->contentDown);
    cc -> setGeometry(0,20,421,240);
    cc -> show();
    QFile *file = new QFile(QString("./data/administor.dat"));
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);
    int a , activity ;
    int humans;
    stream >> a >> activity >> humans;
    qDebug() << "审核人数：" << humans ;

    for ( int i = 1 , j=1 ; i <= humans ; i++ ) {

        long long int phone ;
        stream >> phone ;

        if(phone!=0){
            administorview *one = new administorview(cc,getUserName(phone),phone,0,30*(j++));////////////////
            connect(one,&administorview::yes,[=](){     ///审核通过了的
                sheIsPassed( phone , i);///////////////////////////////审核通过的，需要打开文件操作的函数放这里
                //whetherPass();
            });
        }
    }

    file->close();
}


void administrator::deletCC(){
    delete cc ;
}

//这里才是对文件的操作，就是审核过了需要操作哪些文件
void administrator::sheIsPassed(long long herPhone , int is ){
    //也是需要分三步走，改变管理员的，改变用户的，改变活动的
    //第一步，改变管理员的,放在槽函数中试试
    {
        QFile *file = new QFile(QString("./data/administor.dat"));
        QDataStream stream(file);
        file -> open(QIODevice::ReadOnly | QIODevice::WriteOnly);
        int a , b , c ;
        stream >> a >> b >> c ;
         long long int readphone  = 0 ;
        for (int i = 1 ; i < is ; i++ ) {

            stream >> readphone ;
            qDebug() << "还需要审核的："<<readphone ;

        }
        readphone = 0 ;
        stream << readphone ;
        file -> close();
    }

    //第二步，改变用户文件的
    {
        QFile *file = new QFile( PATH + QString("").number(herPhone) + endPATH );
        QDataStream stream(file);
        file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);
        long long int a;
        QString b ;
        int c ;
        stream >> a >> b >> c ;
        stream << JOIN_PASS ;
        file->close();
    }

    //改变活动文件的
    {
        {
            QFile *file = new QFile( PATH + QString("").number(thisActivityCode) + endPATH );
            QDataStream stream(file);
            file->open(QIODevice::ReadOnly);

            int a , g ;
            QString b ;
            QDate c ,d ,e ;
            QChar f ;
            int people ;

            stream >> a >> b >> c >> d >> e >> f >> g     //没用的信息
                   >> people ;
            file->close();
            file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);
            stream >> a >> b >> c >> d >> e >> f >> g;
            stream << (people+1) ;
            for ( int x = 1 ; x <= people ; x++) {
                long long int p ;
                int q ;
                stream >> p >> q ;
            }
            stream << herPhone << 0 ;
            file->close();
        }
    }
}

void administrator::rankVotes( PeoPle human[] , int num ){
    for ( int i = 0 ; i < num ; i++) {
        int max = human[i].votes ;
        for (int j = i+1 ; j < num ; j++ ) {
            if( human[j].votes > max ){
                PeoPle temp ;
                temp = human[j] ;
                human[j] = human[i] ;
                human[i] = temp;
            }
        }
        human[i].rangking = i+1 ;
    }
}
