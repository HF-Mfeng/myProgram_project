#include "user.h"
#include "ui_user.h"
#include"userview.h"
#include"changecode.h"


#include<QPushButton>
#include<QRegExp>
#include<QRegularExpressionValidator>
#include<QScrollArea>
#include<QDialog>
#include<QString>
#include<qlineedit.h>
#include<QFile>
#include<QDataStream>
#include<QMessageBox>
#include<QDebug>

#include<QPainter>

//#include<QGridLayout>

user::user(QWidget *parent  ) :
    QWidget(parent),
    ui(new Ui::user)
{
   // this->Today = Today.currentDate();
    ui->setupUi(this);

    //this->setWindowTitle(QString("尊敬的"));

    //设置只能输入电话号码
    QRegExp regx("1([0-9]+)");
    QValidator *validator = new QRegExpValidator(regx,ui->searchinput);
    ui->searchinput->setValidator(validator);
    //设置只能输入电话号码





//    ui->backmainbtn->resize(64,64);
//    ui->backmainbtn -> setStyleSheet("#backmainbtn{border:0px ;}");
//    ui->backmainbtn->setStyleSheet("#backmainbtn{border-image:url(:/resource/off.png);}");


//    connect(ui->backmainbtn ,&QPushButton::pressed,[=](){
//        ui->backmainbtn -> setStyleSheet("#backmainbtn{border-image:url(:/resource/on.png);}");
//    });
//    connect(ui->backmainbtn ,&QPushButton::released, [=](){
//        ui->backmainbtn -> setStyleSheet("#backmainbtn{border-image:url(:/resource/off.png);}");
//    });
    //返回登陆窗口
    connect(ui->backmainbtn,&QPushButton::clicked,[=](){
        emit exitlogin();
    });

    //搜索功能
    connect(ui->searchbtn ,&QPushButton::clicked , [=](){
       QFile *file = new QFile( PATH + ui->searchinput->text() +endPATH );
       QDataStream stream(file);
       if(!file->open(QIODevice::ReadOnly)){
           QMessageBox *box = new QMessageBox();
           box->critical(this , QString("警告"),QString("没有这个人"));
           box->setButtonText(QMessageBox::Ok,QString("重试"));
       }else {
           QString hername ;
           {
               long long int herphone ;
               int a ; QChar b ; int c ; int herranking ;
               int hervotes ;
               stream >> herphone >> hername
                       >> a >> b >> c >> herranking
                       >> hervotes ;
               file->close();
           }


           long long int herphone = ui->searchinput->text().toLongLong();
           QFile *file = new QFile( PATH + QString("").number(this->thisActivityCode) + endPATH );
           QDataStream stream(file);
           file->open(QIODevice::ReadOnly);
           int a ; QString b ; QDate c , d , e ; QChar f ; int g ; int peopleNumber ;
           stream >> a >> b >> c >> d >> e >> f >> g >> peopleNumber ;
           file->close();
           for ( int i = 0 ; i < peopleNumber ; i++ ) {
               if(human[i].phone == herphone ){
                   QMessageBox *box = new QMessageBox(this);
                   box->setText(QString("用户名：") +hername + QString("；排名是：")
                                + QString("").number(human[i].rangking) + QString("；他的票数是：")
                                +QString("").number(human[i].votes));
                   box->show();
                   break ;
               }
           }
           ui->searchinput->setText(QString(""));
       }
    });
}//-----------------------------------------构造函数结束处           ------------------------------------//


void user::beauty(){
    QTime dietime = QTime::currentTime().addMSecs(200);
    while(QTime::currentTime()<dietime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}


user::~user()
{
    delete change ;
    delete ui;
}




QString user::getUserName( long long int userPhone ) {
    QFile *file = new QFile( PATH + QString("").number(userPhone) + endPATH );
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly);

    long long int a ;
    QString name ;
    stream >> a >> name ;
    file->close();
    return  name;
}


/*{
 * QInputDialog *input = new QInputDialog () ;
    bool IsOK = true ;
    QString str = input -> getText(this , QString("更改用户名") ,QString("请输入："),QLineEdit::Normal ,QString("请按照用户名要求输入"), &IsOK ,0);
 * }*/






//-------------------------------------这里是用户初始化全部内容
void user::UserInitialization( long long int UserPhone ){
    //首先，检验是否存在一个活动，并且是界面初始化,设定角色
    //然后读取文件
    //最后，存在活动就打印

    this->phone = UserPhone ;
    Today = Today.currentDate();//初始化今天的日子
    qDebug() << "登录的用户电话是：" << phone ;

    setWindowTitle( (this -> getUserName(this->phone)  )  + QString("，您好！")) ;


    //更改密码：
    change = new changeCode();
    change->setPhone(this->phone);
    qDebug() <<"user类中的电话是：" << this->phone ;
    connect(ui->changecodebtn ,&QPushButton::clicked , [=](){
        change->show();
        beauty();
        this->hide();
    });
    connect(change , &changeCode::yesBack , [=](){
        if(change->changeUser()){
            change->close();
            emit exitlogin();
        }
    });
    connect(change , &changeCode::cancelBack ,[=](){
        this->show();
        beauty();
        change->close();
        change->init();
    });

    //更改用户名
    input = new QInputDialog () ;
    connect(ui->changenamebtn ,&QPushButton::clicked,[=](){
        bool IsOK = true ;
        QString str = input -> getText(this , QString("更改") ,QString("请输入："),QLineEdit::Normal ,QString("请按照用户名要求输入"), &IsOK ,0);

        if(IsOK == true){
            long long int a ; int c ;
            QFile *p = new QFile( PATH + QString("").number(this->phone) + endPATH );
            QDataStream st(p);
            QString b ;
            p->open(QIODevice::ReadOnly|QIODevice::WriteOnly);
            st >> a >> b >>  c ;
            p->close();
            p->open(QIODevice::ReadOnly | QIODevice::WriteOnly);
            st << a << str << c ;
            p->close();
            qDebug() << "手机：" << a ;
            qDebug() << "名字：" << b ;
            qDebug() << "密码：" << c ;
            QMessageBox *mes = new QMessageBox ;
            mes->information(this ,QString("提示") ,QString("更改成功，重新登录就会刷新"));
            mes->setButtonText(QMessageBox::Ok , QString("确定"));
        }
    });


    QFile *checkActivity = new QFile(QString("./data/activities.dat"));
    QDataStream ActivityStream(checkActivity);
    checkActivity->open(QIODevice::ReadOnly);
    int activityNumber , activityCode ; //活动数量和活动编码
    QDate activityFirstDate , activitySeconeDate , activityThirdDate ;
    ActivityStream >> activityNumber;

    if(activityNumber == 0 ){       ///没有创建过活动
        zeroActivity();
        return ;
    }


    for (int i = 1; i <= activityNumber; i++) {
        ActivityStream >> activityCode >> activityFirstDate >>activitySeconeDate >> activityThirdDate ;
    }
    checkActivity->close();
    this -> thisActivityCode = activityCode ;

    //打开对应活动文件，读取信息即可
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
        ui->activityName->setText(ActivitName);                                                                                       //
        //-------------下面是判断“今天”是哪一天，活动之前还是之后--------//
        if(firstDate == secondDate && Today>=firstDate && Today <= thirdDate){
            applyDate();//
            voteDate();///////////                                                   记得删除，现在测试
            ui->voteOrregister->setText(QString("报名+投票=报票"));                                                                          //
            ui->passDay->setText(QString("请报名或投票!"));                                                                            //
            ui->remaindDay->setText(QString("距结束还有")+QString("").number( Today.daysTo(thirdDate))+QString("天") );
        }else {
            if(Today<firstDate){   /////////////活动之前，但是有活动发布                                                                        //
                ui->voteOrregister->setText(QString("无"));                                                                                  //
                ui->passDay->setText(QString("敬请期待"));                                                                                     //
                ui->remaindDay->setText(QString("距活动还有")+QString("").number( Today.daysTo(firstDate))+QString("天") );                     //
                ui->activityName->setText(QString(""));                                                                                       //
            }else {                                                                                                                          //
                if(Today>=firstDate && Today<secondDate ){ //////////////////////               报名环节
                    applyDate();//

                    ui->voteOrregister->setText(QString("报名环节"));                                                                          //
                    ui->passDay->setText(QString("请尽快报名吧!!!"));                                                                            //
                    ui->remaindDay->setText(QString("距结束还有")+QString("").number( Today.daysTo(secondDate))+QString("天") );                 //
                }else {                                                                                                                       //
                    if(Today>=secondDate && Today<=thirdDate){ /////////////////                    投票环节
                        voteDate();
                        ui->voteOrregister->setText(QString("投票环节"));                                                                      //
                        ui->passDay->setText(QString("请投票吧!!!"));                                                                          //
                        ui->remaindDay->setText(QString("距结束还有")+QString("").number( Today.daysTo(thirdDate))+QString("天") );              //
                        //
                        /////////////////////////////                       投票环节告诉用户是否每天能投，能投多少票的//////////////////////////                                            //
                        if(ifEveryDayCan == YES){                                                                                          //
                            QMessageBox *box = new QMessageBox();
                            box->information(this , QString("提示") , QString("您每天都可以投")+QString("").number(howManyVotes)+QString("票") ,QMessageBox::Ok ,QMessageBox::Ok);
                            box->setButtonText(QMessageBox::Ok , QString("朕知道了"));                                                                                                   //
                        }else if(ifEveryDayCan == NO ){                                                                                    //
                            QMessageBox *box = new QMessageBox();
                            box->information(this , QString("提示") , QString("您总共可以投")+QString("").number(howManyVotes)+QString("票") ,QMessageBox::Ok ,QMessageBox::Ok);
                            box->setButtonText(QMessageBox::Ok , QString("臣妾明白"));                                                                      //
                                                                                                                              //
                        }                                                                                                                  //
                        //////////////////////////////////////////////////////////////////////////                                                          //
                        //
                    }else{                                                                                                                 //
                        ui->voteOrregister->setText(QString("无"));                                                                         //
                        ui->passDay->setText(QString("敬请期待"));                                                                           //
                        ui->remaindDay->setText(QString("距离上轮活动已过")+QString("").number(-(Today.daysTo(thirdDate)))+QString("天") );     //
                        ui->activityName->setText(QString(""));                                                                            //
                    }                                                                                                                      //
                }                                                                                                                          //
            }                                                                                                                              //
        }
    }//////////////打开对应活动，读取文件即可的结束处





} ///////////初始化函数结束处

bool user::ItisVoteSuccess(){
    QFile *file = new QFile( PATH + QString("").number(thisActivityCode) + endPATH);
    QDataStream stream(file);
    file -> open(QIODevice::ReadOnly);
    int a ; QString b ;QDate c,d,e ;
    QChar everyDay ;
    int howManyVotes ;
    stream >> a>>b>>c>>d>>e>> everyDay >> howManyVotes ;
    file -> close();
    qDebug() << "为了检验投票，读文件效果怎么样 ： "<< a<<b<<c<<d<<e<<everyDay<<howManyVotes;

    if( this->heVotesToHer(this->phone) >= howManyVotes )
    {
        QMessageBox *box = new QMessageBox();
        box->information(this , QString("提示") , QString("投票已到上限") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("知道啦！"));
        return  false ;
    }



    return true;

}











void user::applyDate(){
    connect(ui->signUpbtn,&QPushButton::clicked,[=](){  //报名环节按了报名按钮
        //分2步走，自己的文件要改成报名状态
        //管理员的文件要加审核
        //这里还要检查是否重复报名，未检测

        {
            QFile *file = new QFile( PATH + QString("").number(this->phone) + endPATH );
            QDataStream stream(file);
            file -> open(QIODevice::ReadOnly);
            long long int a ;
            QString B;
            int c ;
            QChar zhuangtai ;
            stream >> a >> B >> c  >> zhuangtai ;
            file->close();
            if( zhuangtai != NOJOIN ){
                //                QMessageBox *box = new QMessageBox(this);
                //                box->setText(QString("不能重复报名啊！！！"));
                //                box->show();
                return ;
            }
        }


        //第一步，自己的加上
        {
            QFile *file = new QFile( PATH + QString("").number(this->phone) + endPATH );
            QDataStream stream(file);
            file -> open(QIODevice::WriteOnly|QIODevice::ReadOnly);

            long long int a ;
            QString B;
            int c ;
            stream >> a >> B >> c ;
            stream << JOIN_NOPASS << thisActivityCode ;
            file->close();
        }
        //第二步，管理员的加上审核
        {
            QFile *file = new QFile(QString("./data/administor.dat"));
            QDataStream stream(file);

            file -> open(QIODevice::ReadOnly|QIODevice::WriteOnly);
            int a , b , people ;
            long long aPhone;
            stream >> a >> b >> people;
            qDebug () << "a,b,people = " << a << ',' << b << ',' << people;
            for (int i = 1 ; i <= people ; i++ ) {
                long long int y ;
                stream  >> y ;
                qDebug()<<"报名函数中的for循环次数" << i << "此时" << y ;
            }
            stream << (this->phone) ;
            file->close();

            file -> open(QIODevice::ReadOnly|QIODevice::WriteOnly);
            stream >> a >> b ;
            qDebug() << "people+1=" << people+1 ;
            stream << people+1 ;
            qDebug()<<"报名函数中的测试2"<< this->phone;
            file->close();

            file->open(QIODevice::ReadOnly|QIODevice::WriteOnly);
            stream >>a >> b >> people >> aPhone  ;
            qDebug() << "活动：" << b << "，总需审核：" << people << "人，第一个需要审核的：" << aPhone;
            file->close();
        }

        QMessageBox *box = new QMessageBox();
        box->information(this , QString("提示") , QString("报名成功了哟！") ,QMessageBox::Ok ,QMessageBox::Ok);
        box->setButtonText(QMessageBox::Ok , QString("朕知晓了"));
    });
}

void user::voteDate(){
    //读取某活动的信息
    //先创建链表
    //排序
    //并显示在上面

    can = new QWidget(ui->scrollAreaWidgetContents );
    can ->setGeometry(0,0,500,900);
    can ->show();
    QFile *file = new QFile( PATH + QString("").number(this->thisActivityCode) + endPATH );
    QDataStream stream(file);
    file->open(QIODevice::ReadOnly);
    int a , allvotes = 0;
    QString b;
    QDate c ,d ,e ;
    QChar f;
    int g , number ;
    stream >> a >> b >>c >>d >>e >> f >> g >> number ;
//    PeoPle human[number];
    for ( int i = 0 ; i < number ; i++ ) {
        long long readPhone ;
        int readVotes ;
        stream >> readPhone >> readVotes ;
        human[i].phone = readPhone ;
        human[i].votes = readVotes ;
        human[i].rangking = 0 ;
        allvotes += readVotes ;
    }
    file->close();
    rankVotes( human , number );
    for ( int i = 0 ; i < number ; i++ ) {
        if(allvotes==0) human[i].precentage = 0 ;
        else human[i].precentage = 100*(human[i].votes * 1.0 / allvotes) ;
        userview *one = new userview( can ,
                                      human[i].phone ,
                                      human[i].votes,
                                      human[i].rangking,
                                      human[i].precentage,
                                      0 , 46 * (i) );
        long long int a = human[i].phone ;
        connect(one , &userview::yes , [=](){
            if( this->ItisVoteSuccess() && a != this->phone ){                                                         //这里是点击了投票按钮的，投票的检测和改变,并看能不能实时更新
                this -> voteForHer(  phone ,  a ,  thisActivityCode );
                one->addVotes();                        //为了能实施改变票数
            }

            if( a == this -> phone ){
                QMessageBox *box = new QMessageBox();
                box->critical (this , QString("禁止这样⚠") , QString("不要为自己投票"),QMessageBox::Ok ,QMessageBox::Ok);
                box->setButtonText(QMessageBox::Ok , QString("我错了！"));
            }
        });
    }
}



void user::deleteCan(){
    delete can;
}

void user::rankVotes( PeoPle human[] , int num ){
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


void user::voteForHer( long long int MyPhone , long long int HerPhone , int thisActivity ){

    //分三步，我的文件要改，他的文件也要改，活动的文件还要改
    //第一步，我的文件
    {
        QFile *file = new QFile( PATH + QString("").number(MyPhone) + endPATH );
        QDataStream stream(file);
        file -> open(QIODevice:: ReadOnly  );
        long long int a; QString b ; int c ; QChar d ; int e ; int f ;
        int g ; int havaVotedVotes;

        stream >>a>>b>>c>>d>>e>>f>>g  >> havaVotedVotes ;
        file -> close();
        file -> open(QIODevice:: ReadOnly | QIODevice::WriteOnly );
        stream >>a>>b>>c>>d>>e>>f>>g ;
        stream << ( havaVotedVotes+1);
        for (int i = 1 ;i <= havaVotedVotes ; i++) {
            long long int readphone ;
            stream >> readphone ;
        }
        stream << HerPhone ;
        file -> close();
    }

    //////第二步，改变她的文件
    {
        QFile *file = new QFile( PATH + QString("").number(MyPhone) + endPATH );
        QDataStream stream(file);
        file -> open(QIODevice:: ReadOnly);
        long long int a ; QString b ; int c ; QChar d ; int e ; int f ;
        int herVotes;
        stream >>a>>b>>c>>d>>e>>f ;
        stream >> herVotes ;
        file -> close();
        file -> open(QIODevice:: ReadOnly | QIODevice::WriteOnly );
        stream >>a>>b>>c>>d>>e>>f ;
        stream << ( herVotes+1);
        file->close();
    }

    //第三步，改变活动的文件
    {
        QFile *file = new QFile( PATH + QString("").number(thisActivity) + endPATH );
        QDataStream stream(file);
        file -> open(QIODevice:: ReadOnly);
        int a ; QString b ; QDate c ,d , e ;QChar f;int g , h ;
        stream  >>a>>b>>c>>d>>e>>f>>g>>h ;
        int hervotes ;
        for ( int i = 1 ; i <= h; i++ ) {
            long long readphone ;
            stream >> readphone >> hervotes ;
            if( readphone == HerPhone )
                break;
        }
        file->close();
        file -> open(QIODevice:: ReadOnly | QIODevice::WriteOnly );
        stream  >>a>>b>>c>>d>>e>>f>>g>>h ;
        for ( int i = 1 ; i <= h; i++ ) {
            long long readphone ;
            int vote ;
            stream >> readphone ;
            if( readphone == HerPhone )
                break;
            stream >> vote ;
        }
        stream << (hervotes+1) ;
        file->close();
    }
}



void user::zeroActivity(){
    ui->activityName->setText(QString("无活动"));
    ui->passDay->setText(QString(""));
    ui->remaindDay->setText(QString(""));
    ui->voteOrregister->setText(QString(""));
}



int user::heVotesToHer(long long hisphone){
    QFile *file = new QFile( PATH + QString("").number(hisphone) + endPATH );
    QDataStream stream(file);
    file -> open( QIODevice:: ReadOnly);
    long long int a ; QString b ; int c ;QChar d;
    int e , f , g , information ;
    stream >> a >> b >> c >> d >> e >> f >> g >>information ;
    file -> close();
    return information ;
}
