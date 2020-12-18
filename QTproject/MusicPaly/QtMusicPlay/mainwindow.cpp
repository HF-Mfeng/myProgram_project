#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myslider.h"

#include <QPushButton>
#include <QMediaPlayer>
#include <QUrl>
#include <QSlider>
#include <QMediaMetaData> //用来获取音乐文件的信息
#include <QDebug>


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

void MainWindow::volum(int v){
    if(v < 90){
        v = v + 10;
    }
    player->setVolume(v);
    player->play();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MySlider* mySlider = new MySlider();
    mySlider->setGeometry(100,334,3,3);
    player = new QMediaPlayer;
//   ui->pushButton->setWindowOpacity(0.1);
//    this->setWindowOpacity(0.1);

//    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setAttribute(Qt::WA_TranslucentBackground);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        player->setMedia(QUrl::fromLocalFile("D:/fade.mp3"));
        player->setVolume(10);
        player->play();
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
          player->setVolume(90);
          Time = player->duration();
          qDebug() << "总时长为：" << Time ;

    });

    connect(ui->pushButton_3, &QPushButton::clicked, [=](){
        player->setVolume(10);
        mySlider->show();
    });
    connect(ui->horizontalSlider, &QAbstractSlider::valueChanged, this, &MainWindow::changeProcess);
}

void MainWindow::changeProcess(){
    qint64 m ;
    int x ;
    x = ui->horizontalSlider->value();
    qDebug() << x ;
    m = 1.0 * Time * x / 100.0;
    player->setPosition(m);
}

MainWindow::~MainWindow()
{
    delete ui;
}

