#include "myslider.h"
#include "ui_myslider.h"

#include <QGraphicsOpacityEffect>
#include <QMouseEvent>
#include <QDebug>

MySlider::MySlider(QWidget *parent) :
    QSlider(parent),
    ui(new Ui::MySlider)
{
    ui->setupUi(this);

   QGraphicsOpacityEffect *g = new QGraphicsOpacityEffect;
   ui->horizontalSlider->setGraphicsEffect(g);
   g->setOpacity(0.9);


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
//    this->setAttribute(Qt::WA_TransparentForMouseEvents);
//    ui->horizontalSlider->hide();
    ui->horizontalSlider->setWindowOpacity(0.5);
    if( (ui->horizontalSlider->isHidden()) ){
        ui->horizontalSlider->setAttribute(Qt::WA_TransparentForMouseEvents);
        this->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void MySlider::mouseMoveEvent(QMouseEvent *event){
//    int currentx = event->pos().x();
//    double per = currentx * 1.0 / this->width();
//    int value = per*(this->ui->horizontalSlider->maximum() - this->ui->horizontalSlider->minimum()) + ui->horizontalSlider->minimum();
//    qDebug() << value ;
//    ui->horizontalSlider->setValue(value);
//    emit sliderReleased();

    QSlider::mouseMoveEvent(event);
    double pos = event->pos().x()/(double)width();
    ui->horizontalSlider->setValue(pos*( ui->horizontalSlider->maximum() - ui->horizontalSlider->minimum() ) + ui->horizontalSlider->minimum() );
    emit MySliderMouseClicked();

}



MySlider::~MySlider()
{
    delete ui;
}
