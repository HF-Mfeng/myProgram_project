#include "myslider.h"
#include "ui_myslider.h"

#include <QMouseEvent>

MySlider::MySlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySlider)
{
    ui->setupUi(this);
    ui->horizontalSlider->setAttribute(Qt::WA_TransparentForMouseEvents);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MySlider::emitMySignals);
}



void MySlider::setSliderValue(int value){
    ui->horizontalSlider->setValue(value);
}
void MySlider::setSliderMax(int max){
    ui->horizontalSlider->setMaximum(max);
}
int MySlider::getSliderValue(){
    return ui->horizontalSlider->value();
}
void MySlider::setTimeShow(QTime *thetime){
    ui->pushButton->setText(thetime->toString(QString("mm:ss")));
}
void MySlider::showAllTiem(QTime *time){
    ui->label->setText(time->toString(QString("mm:ss")));
}


//鼠标按下事件
void MySlider::mousePressEvent(QMouseEvent *ev){
    double proportion;
    proportion = (double)(ev->pos().x() - ui->horizontalSlider->x())
            / ui->horizontalSlider->width();
    double num ;
    num = proportion * ( ui->horizontalSlider->maximum() - ui->horizontalSlider->minimum() ) + ui->horizontalSlider->minimum();
    value = num + 0.5 ;
    if(value > ui->horizontalSlider->maximum()){
        value = ui->horizontalSlider->maximum();
    }
    if(value < ui->horizontalSlider->minimum()){
        value = ui->horizontalSlider->minimum();
    }
    ui->horizontalSlider->setValue(value);
}

//鼠标移动事件
void MySlider::mouseMoveEvent(QMouseEvent *ev){
//    disconnect(ui->horizontalSlider, &QSlider::valueChanged, this, &MySlider::emitMySignals);
    double proportion;
    proportion = (double)(ev->pos().x() - ui->horizontalSlider->x())
            / ui->horizontalSlider->width();
    double num ;
    num = proportion * ( ui->horizontalSlider->maximum() - ui->horizontalSlider->minimum() ) + ui->horizontalSlider->minimum();
    value = num + 0.5 ;
    if(value > ui->horizontalSlider->maximum()){
        value = ui->horizontalSlider->maximum();
    }
    if(value < ui->horizontalSlider->minimum()){
        value = ui->horizontalSlider->minimum();
    }
    ui->horizontalSlider->setValue(value);
//    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MySlider::emitMySignals);
}

//鼠标松开事件
void MySlider::mouseReleaseEvent(QMouseEvent *ev){

    double proportion;
    proportion = (double)(ev->pos().x() - ui->horizontalSlider->x())
            / ui->horizontalSlider->width();
    double num ;
    num = proportion * ( ui->horizontalSlider->maximum() - ui->horizontalSlider->minimum() ) + ui->horizontalSlider->minimum();
    value = num + 0.5 ;
    if(value > ui->horizontalSlider->maximum()){
        value = ui->horizontalSlider->maximum();
    }
    if(value < ui->horizontalSlider->minimum()){
        value = ui->horizontalSlider->minimum();
    }
    ui->horizontalSlider->setValue(value);
}


MySlider::~MySlider()
{
    delete ui;
}
