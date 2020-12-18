#include "myvolum.h"
#include "ui_myvolum.h"

#include <QDebug>
#include <QMouseEvent>
#include <QString>
#include <QKeyEvent>
#include <QWheelEvent>

MyVolum::MyVolum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyVolum)
{
    ui->setupUi(this);
    ui->verticalSlider->setAttribute(Qt::WA_TransparentForMouseEvents);
    //    this->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->verticalSlider->hide();
    ui->label->setAlignment(Qt::AlignHCenter);
    connect(ui->verticalSlider, &QSlider::valueChanged, [=](){
        emit this->volumChange(ui->verticalSlider->value());
    });
    this->setFocusPolicy(Qt::StrongFocus);
    ui->label->setText(QString().number(ui->verticalSlider->value()));
}

MyVolum::~MyVolum()
{
    delete ui;
}
void MyVolum::wheelEvent(QWheelEvent *event){
    if(event->delta() > 0){
        this->volumValue += 3 ;
        if(this->volumValue > 100) this->volumValue = 100;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
    }
    if(event->delta() < 0){
        this->volumValue -= 3 ;
        if(this->volumValue < 0 ) this->volumValue = 0 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
    }
}
void MyVolum::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left:   ///音量+
    case Qt::Key_Up:
    case '+':
        if(this->volumValue < 100 ){
            ui->verticalSlider->setValue(++(this->volumValue));
            ui->label->setText(QString("").number(this->volumValue));
        }
        break ;

    case Qt::Key_Right :  ///音量-
    case Qt::Key_Down :
    case '-':
        if(this->volumValue > 0 ){
            ui->verticalSlider->setValue(--(this->volumValue));
            ui->label->setText(QString("").number(this->volumValue));
        }
        break ;
    case Qt::Key_0 :
        this->volumValue = 0 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_1 :
        this->volumValue = 10 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_2 :
        this->volumValue = 20 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_3 :
        this->volumValue = 30 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_4 :
        this->volumValue = 40 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_5 :
        this->volumValue = 50 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_6 :
        this->volumValue = 60 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_7 :
        this->volumValue = 70 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_8:
        this->volumValue = 80 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    case Qt::Key_9 :
        this->volumValue = 90 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
        break ;
    }
}


void MyVolum::mouseMoveEvent(QMouseEvent *event) {
    if(!(ui->verticalSlider->isHidden())){
        double propotrion;
        propotrion =(double) event->pos().y() / ui->verticalSlider->height();
        this->volumValue = ui->verticalSlider->maximum() - propotrion * ui->verticalSlider->maximum() + 0.5;
        if(this->volumValue > 100) this->volumValue = 100;
        if(this->volumValue < 0 ) this->volumValue = 0 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
    }
}
void MyVolum::mousePressEvent(QMouseEvent *event){
    if(!(ui->verticalSlider->isHidden())){
        double propotrion;
        propotrion =(double) event->pos().y() / ui->verticalSlider->height();
        this->volumValue = ui->verticalSlider->maximum() - propotrion * ui->verticalSlider->maximum() + 0.5;
        if(this->volumValue > 100) this->volumValue = 100;
        if(this->volumValue < 0 ) this->volumValue = 0 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
    }
}
void MyVolum::mouseReleaseEvent(QMouseEvent *event){
    if(!(ui->verticalSlider->isHidden())){
        double propotrion;
        propotrion =(double) event->pos().y() / ui->verticalSlider->height();
        this->volumValue = ui->verticalSlider->maximum() - propotrion * ui->verticalSlider->maximum() + 0.5;
        if(this->volumValue > 100) this->volumValue = 100;
        if(this->volumValue < 0 ) this->volumValue = 0 ;
        ui->verticalSlider->setValue(this->volumValue);
        ui->label->setText(QString("").number(this->volumValue));
    }
}

void MyVolum::enterEvent(QEvent *event) {
    this->resize(42,200);
    ui->verticalSlider->show();
    ui->label->setGeometry(0,180,42,20);
    ui->verticalSlider->setGeometry(9,0,22,180);
    emit mySize(42, 200);
}
void MyVolum::leaveEvent(QEvent *event) {
    ui->verticalSlider->hide();
    this->resize(42,20);
    ui->label->setGeometry(0,0,42,20);
    emit mySize(42, 20);
}
