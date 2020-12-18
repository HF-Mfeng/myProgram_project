#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myslider.h"
#include "myvolum.h"


//用来播放本地音乐，把路径改了还可以播放某个网址的音乐
//QMediaPlayer player = new QMediaPlayer;
//player->setMedia(QUrl::fromLocalFile("D:/fade.mp3"));
//player->setVolume(10);
//player->play();

//------------改变进度
//Time = player->duration();
//x = ui->horizontalSlider->value();
//qDebug() << x ;
//m = 1.0 * Time * x / 100.0;
//player->setPosition(m);
//connect(ui->horizontalSlider, &QAbstractSlider::valueChanged, this, &MainWindow::changeProcess);

//设置窗口透明，然后控件不透明
//this->setWindowFlags(Qt::FramelessWindowHint);
//this->setAttribute(Qt::WA_TranslucentBackground);


//设置某一个控件透明
//QGraphicsOpacityEffect *g = new QGraphicsOpacityEffect;
//ui->horizontalSlider->setGraphicsEffect(g);
//g->setOpacity(0.1);

//用QMediaPlayerList来创建放歌列表
//PlayList -> addMedia(QUrl::fromLocalFile(fileNames.at(i)));//将音乐文件逐一加入到播放列表
//songFileName = fileNames.at(i);
//info = QFileInfo(songFileName);
//songName = info.fileName();
//Ted ->append(songName);//添加歌曲名到界面的歌曲列表

//用来打开多个音乐文件
//QStringList str = QFileDialog::getOpenFileNames(this,tr("选择文件"),tr("D:/"),tr("歌曲文件(*.mp3 *.m4a)"));
//                                                      选择文件是窗口标题，d:/是默认打开的路径，*.mp3是筛选MP3文件
//str[n]可以索引到第n位置的元素
//str[n].split(QRegExp("[\\.]"));   以.来分隔str（qstring）
//QFileInfo info = QFileInfo(str[n]);
//QString s = info.fileName();     获取str[n]的文件名（含拓展名）

//检查某个文件是否存在，不存在就创建，一般初始化需要检查的
//QFile *file = new QFile(QString("./data/users.dat"));
//        if(!(file->exists())){
//            QDataStream stream (file);
//            file->open(QIODevice::WriteOnly);
//            stream << 0;
//            file->close();
//        }}

//检查文件夹是否存在，也是用于初始化的检查
//QDir dir;
//if(!dir.exists(PATH)){
//    dir.mkdir(PATH);
//}


//用来做提示框的
//QMessageBox *box  = new QMessageBox();
//box->critical(this , QString("错误⚠") , QString("用户名不正确！！") ,QMessageBox::Ok ,QMessageBox::Ok);
//box->setButtonText(QMessageBox::Ok,QString("重试"));

//复制音乐到路径
//QString str = QFileDialog::getOpenFileName(this,tr("选择文件"),tr("D:/Music/"),tr("歌曲文件(*.mp3 *.m4a)"));
//QFileInfo info(str);
//QString n = info.fileName();
//QFile::copy(str,PATH+n);

//下一首播放
//int currentIndex = PlayList->currentIndex();
//if(++currentIndex == PlayList->mediaCount())
//currentIndex=0;
//PlayList->setCurrentIndex(currentIndex);

//滚动条实现,最后还要确定一下那个是否需要竖直滚动条，竖直滚动条宽16
//for (int i = 0 ; i < 22 ; i++ ) {
//    QPushButton* pushButton = new QPushButton(QString().number(i), ui->scrollAreaWidgetContents);
//    pushButton->setGeometry(0,40*i,50,40);
//}
//ui->scrollArea->setWidgetResizable(false);
//ui->scrollAreaWidgetContents->resize(ui->scrollAreaWidgetContents->width()-100,40*22);

#include <QPushButton>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>
#include <QSlider>
#include <QMediaMetaData> //用来获取音乐文件的信息
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QFileInfo>
#include <QRegExp>
#include <QDir>
#include <QDataStream>
#include <QFile>
#include <QScrollBar>
#include <QScrollArea>
#include <QSizePolicy>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowOpacity(1);
    this->setWindowTitle(QString("网抑云音乐"));
    //初始化声音,初始化播放列表，初始化播放的音乐
    this->volum = 50 ;
    Player = new QMediaPlayer();
    PlayerList = new QMediaPlaylist();
    NameList = new QStringList() ;
    isPlaying = false;
    this->Time = 0 ;
    this->nowTime = new QTime();
    this->playWay = MainWindow::ALLLOOPPLAY ;

    //检查是否有文件夹
    QDir dir;
    if(!dir.exists(PATH)){
        dir.mkdir(PATH);
    }

    scanAllMusic();


    //测试中，声音的那个
    connect(ui->widget, &MyVolum::mySize, this, &MainWindow::changeWidgeSize);
     ui->widget->setGeometry(0,this->height()-200,42,200);
     connect(ui->widget, &MyVolum::volumChange, this, &MainWindow::changeVolum);

    //显示播放列表的
    connect(ui->btnList, &QPushButton::clicked, this, &MainWindow::changePlayList);
    void (MainWindow::* f1)(int) = &MainWindow::numMusic;
    connect(this, f1, this, &MainWindow::playWhichMusic); //用来点击某首歌播放的效果，我觉得可以不用改
    //播放方式
    connect(ui->btnPlayWay, &QPushButton::clicked, this, &MainWindow::changePlayWay);
    //切歌
    connect(ui->btnNextSong, &QPushButton::clicked, this, &MainWindow::nextMusic);
    connect(ui->btnLastSong, &QPushButton::clicked, this, &MainWindow::lastMusic);
    //播放暂停功能
    connect(ui->btnPlay, &QPushButton::clicked, this, &MainWindow::pausePlayingMusic);


    //添加歌曲的一个文件而已
    connect(ui->btnAddMusicList, &QPushButton::clicked, [=](){
        QStringList strs = QFileDialog::getOpenFileNames(this,tr("选择文件"),tr("./data/"),tr("歌曲文件(*.mp3 *.m4a)"));
        for (int i = 0 ; i < strs.length() ; i++) {
            qDebug() << i <<": " << strs[i];
            if( !(PlayerList->addMedia(QUrl::fromLocalFile(strs[i])))){
                qDebug() << "错误信息"; //////后期要用提示来写
            }
            QFileInfo *info = new QFileInfo(strs[i]);
            this->NameList->append(info->fileName());
            qDebug() << NameList->at(i) ;
            QFile *file = new QFile(PATH+NameList->at(i));
            if(!(file->exists()))
                QFile::copy(strs[i], PATH+NameList->at(i));
        }

        //设置播放列表
        for (int i = 0 ; i < strs.length() ; i++ ) {
            QStringList n = (NameList->at(i)).split(QRegExp("[\\.]"));
            QPushButton *btn = new QPushButton(n[0],ui->scrollAreaWidgetContents);
            btn->setGeometry(0,40*i,268,40);
            connect(btn, &QPushButton::clicked, [=](){
                emit numMusic(i);
            });
            btn->setStyleSheet(QString("text-align:left;"));
            btn->show();
        }
        ui->scrollArea->setWidgetResizable(false);
        ui->scrollAreaWidgetContents->resize(255,40*strs.length());
        ui->scrollArea->setStyleSheet(QString("border:rgb(255,0,0);"));
        Player->setPlaylist(PlayerList);
        Player->setVolume(this->volum);
        PlayerList->setCurrentIndex(0);
        Player->play();
        isPlaying = true;
        PlayerList->setPlaybackMode(QMediaPlaylist::Loop);  //循环播放

        //---------------这个是如果歌曲时长改表了就会这样的-------------/////这三个连接应该放在有播放列表的函数里面
        connect(Player, &QMediaPlayer::durationChanged, [=](){
            ui->aMySlider->setSliderValue(0);
            this->Time = Player->duration();
            ui->aMySlider->setSliderMax(this->Time);
            ui->songNamelabel->setText((NameList->at(PlayerList->currentIndex()).split(QRegExp("[\\.]"))).at(0));
            QTime allTime(Player->duration()/1000/60/60%23,Player->duration()/1000/60%60,Player->duration()/1000%60,Player->duration()%1000);
           ui->aMySlider->showAllTiem(&allTime);
        });
        //--------------用来进度条与歌曲时间相互控制--------------------------//
        Player->setNotifyInterval(1000); //设置刷新时间单位ms
        connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::musicControlSlider);
        connect(ui->aMySlider, &MySlider::mySliderChange, this, &MainWindow::sliderControlMusic);
    });

}

//改变播放方式，顺序，循环，单曲，随机
void MainWindow::changePlayWay(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    switch (this->playWay) {
    case MainWindow::ALLPLAY :
        ui->btnPlayWay->setText(QString("循环播放"));
        PlayerList->setPlaybackMode(QMediaPlaylist::Loop);
        this->playWay = MainWindow::ALLLOOPPLAY ;
        break ;
    case MainWindow::ALLLOOPPLAY :
        ui->btnPlayWay->setText(QString("单曲循环"));
        PlayerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        this->playWay = MainWindow::ONELOOPPLAY ;
        break ;
    case MainWindow::ONELOOPPLAY :
        ui->btnPlayWay->setText(QString("随机播放"));
        PlayerList->setPlaybackMode(QMediaPlaylist::Random);
        this->playWay = MainWindow::RANGDOMPLAY ;
        break ;
    case MainWindow::RANGDOMPLAY :
        ui->btnPlayWay->setText(QString("顺序播放"));
        PlayerList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        this->playWay = MainWindow::ALLPLAY ;
        break ;
    }
}

//进度条音乐互相控制，先取消连接，在确定连接，不然会一卡一卡的
void MainWindow::musicControlSlider(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    disconnect(ui->aMySlider, &MySlider::mySliderChange, this, &MainWindow::sliderControlMusic);
    ui->aMySlider->setSliderValue(Player->position());
    connect(ui->aMySlider, &MySlider::mySliderChange, this, &MainWindow::sliderControlMusic);
    nowTime->setHMS(Player->position()/1000/60/60%23,Player->position()/1000/60%60,Player->position()/1000%60,Player->position()%1000);
    ui->aMySlider->setTimeShow(nowTime);
}
void MainWindow::sliderControlMusic(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    disconnect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::musicControlSlider);
    Player->setPosition(ui->aMySlider->getSliderValue());
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::musicControlSlider);
    nowTime->setHMS(Player->position()/1000/60/60%23,Player->position()/1000/60%60,Player->position()/1000%60,Player->position()%1000);
    ui->aMySlider->setTimeShow(nowTime);
}

//点击哪首歌曲播放哪首音乐
void MainWindow::playWhichMusic(int num){
    if(PlayerList->mediaCount() == 0 )
        return ;
    PlayerList->setCurrentIndex(num);
}

//添加歌曲播放列表，未解决
void MainWindow::addMusicList(){

}
//从电脑上导入音乐到本地
void MainWindow::addMusicToLocal(){
    QStringList strs = QFileDialog::getOpenFileNames(this,tr("选择文件"),tr("./data/"),tr("歌曲文件(*.mp3 *.m4a)"));
    for (int i = 0 ; i < strs.length() ; i++) {
        QFile *file = new QFile(PATH+NameList->at(i));
        if(!(file->exists()))
            QFile::copy(strs[i], PATH+NameList->at(i));
    }
}
//开始播放当前音乐，未解决
void MainWindow::startPlayingMusic(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    if( Player ){
        Player->setMedia(QUrl::fromLocalFile("D:/fade.mp3"));
        Player->setVolume(this->volum);
        Player->play();
    }else{
        //没有选择任何音乐
        Player = new QMediaPlayer; //这里后面应该改到那个什么添加音乐队列那里，测试版本就不着急
    }
}

//停止播放当前音乐
void MainWindow::stopPlayingMusic(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    Player->stop();
}

//暂停播放当前音乐
void MainWindow::pausePlayingMusic(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    if(isPlaying){
        Player->pause();
        isPlaying = false;
        ui->btnPlay->setText(QString("播放"));
    }else{
        Player->play();
        isPlaying = true;
        ui->btnPlay->setText(QString("暂停"));
    }
}

//音量+，音量-
void MainWindow::changeVolum(int volum){
    if(PlayerList->mediaCount() == 0 || !(Player))
        return ;
    if( this->volum >= 100 )
        this->volum = 100;
    if( this->volum <= 0 )
        this->volum = 0 ;
    Player->setVolume(volum);
    this->volum = volum ;
}

//播放列表显示与改变
void MainWindow::changePlayList(){
    if(ui->scrollArea->isHidden()){
        ui->scrollArea->show();
    } else {
        ui->scrollArea->hide();
    }
}

//切换歌曲
void MainWindow::nextMusic(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    if(PlayerList->currentIndex() == PlayerList->mediaCount() - 1)
        PlayerList->setCurrentIndex(0);
    else
        PlayerList->setCurrentIndex(PlayerList->currentIndex()+1);
}
void MainWindow::lastMusic(){
    if(PlayerList->mediaCount() == 0 )
        return ;
    if(PlayerList->currentIndex() == 0 )
        PlayerList->setCurrentIndex(PlayerList->mediaCount() - 1);
    else
        PlayerList->setCurrentIndex(PlayerList->currentIndex()-1);
}

void MainWindow::changeWidgeSize(int w, int h){
    ui->widget->setGeometry(0,this->height()-h,w,h);
}

//初始化检查以及初始化赋值,未解决
bool MainWindow::initialCheck(){
    //下面是检查文件夹的
    {
        QFile *file = new QFile(PATH+PATH_INFO);
        if(!(file->exists())){
            if( !(file->open(QIODevice::WriteOnly) ) )
                return false;
            QDataStream stream(file);
            stream << 0 ;
            file->close();
        }
    }
    {
        QFile *file = new QFile(PATH+PATH_LIST1);
        if(!(file->exists())){
            if( !(file->open(QIODevice::WriteOnly) ) )
                return false;
            QDataStream stream(file);
            stream << 0 ;
            file->close();
        }
    }
    {
        QFile *file = new QFile(PATH+PATH_LIST2);
        if(!(file->exists())){
            if( !(file->open(QIODevice::WriteOnly) ) )
                return false;
            QDataStream stream(file);
            stream << 0 ;
            file->close();
        }
    }
    {
        QFile *file = new QFile(PATH+PATH_LIST3);
        if(!(file->exists())){
            if( !(file->open(QIODevice::WriteOnly) ) )
                return false;
            QDataStream stream(file);
            stream << 0 ;
            file->close();
        }
    }

    //给LastAddPath赋值




    return true;
}

//浏览已经导入本地的音乐，未解决
void MainWindow::scanAllMusic(){
    QDir dir(PATH);
    QStringList allName;
    allName << "*.mp3" << "*.m4a";
    QStringList list = dir.entryList(allName,QDir::Files|QDir::Readable,QDir::Name);
    qDebug() << list ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

