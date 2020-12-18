#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"

#include <QTime>
#include <QRandomGenerator>
#include <QPushButton>
#include <QMessageBox>

//void get_random_number()
//{
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    int a = qrand()%9;   //随机生成0到9的随机数
//    qDebug()<< a;
//}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mode = 1 ;
    nowXuhao = 9;
    QTime time ;
    time = time.currentTime();
    QTime noon = QTime(12,0,0,0);
    QTime afternoon = QTime(14,0,0,0);
    QTime night = QTime(19,0,0,0);
    if(time < noon)
        this->setWindowTitle(QString("宝贝,上午好"));
    else {
        if(time >= noon && time <= afternoon)
          this->setWindowTitle(QString("宝贝,中午好"));
        else {
            if(time > afternoon && time < night)
                this->setWindowTitle(QString("宝贝,下午好"));
            else
                this->setWindowTitle(QString("宝贝,晚上好"));
        }
    }

    connect(ui->widget, &mybutton::hasEnter,[=](){
        int x = randNumber('x');
        int y = randNumber('y');
        int m = QRandomGenerator::global()->bounded(2,8);
        if(m < nowXuhao)
            nowXuhao = m ;
        else
            nowXuhao = m + 1;
        talk(nowXuhao);
        ui->widget->setGeometry(x ,y , 100 , 40);
    });
    connect(ui->btnLove, &QPushButton::clicked,[=](){
        mode = 520 ;
        this->close();
    });
}


int Widget::randNumber(char c){
    int myRandNumber = 0 ;
    int i ;
    switch (c) {
    case 'x':
    case 'X':
        i = QRandomGenerator::global()->bounded(0,200);
        if(i < ui->widget->x())
            myRandNumber = i ;
        else if (i >= ui->widget->x())
            myRandNumber = i + ui->widget->width();
        break;
    case 'y':
    case 'Y':
        i = QRandomGenerator::global()->bounded(200,220);
        if(i < ui->widget->y())
            myRandNumber = i;
        else if (i >= ui->widget->y())
            myRandNumber = i + ui->widget->height();
        break ;
    }
    return  myRandNumber;
//    return  QRandomGenerator::global()->bounded(min,max);
}

void Widget::changeEvent(QEvent *event){
    if(event->type() != QEvent::WindowStateChange)
        return ;
    //最小化
    if(this->windowState() == Qt::WindowMinimized){
        talk(Widget::MIN);
        this->setWindowState(Qt::WindowNoState);
    }
}
void Widget::enterEvent(QEvent *event){
    talk(QString("你的鼠标在说你爱我，我也爱你！！！"));
}
void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->pos().y() <= 400 && event->pos().y() >= 300 ){
        talk(QString("按下去，我爱你"));
    }
}
void Widget::leaveEvent(QEvent *event){
    talk(QString("鼠标都不愿意多待会吗？我爱你！"));
}
void Widget::closeEvent(QCloseEvent *event){
    if(mode == 520){
        QMessageBox *box = new QMessageBox();
        box->setWindowTitle(QString("我说："));
        box->setText(QString("宝贝，我也爱你，么么哒!!!"));
        box->setStandardButtons(QMessageBox::Ok);
        box->button(QMessageBox::Ok)->setText(QString("爱你"));
        box->show();
        return ;
    }
    talk(Widget::CLOSE);
    event->ignore();
}
void Widget::talk(QString str){
    ui->labelText->setText(str);
}
void Widget::talk(int m){
    switch (m) {
    case Widget::MIN:
        talk(QString("想不看我？没门，我爱你！"));
        break ;
    case Widget::CLOSE:
        talk(QString("我爱你！别关闭"));
        break ;
    case 2:
        talk(QString("我真的爱你！"));
        break ;
    case 3:
        talk(QString("保大，我爱你！"));
        break ;
    case 4:
        talk(QString("工资上交，我爱你！"));
        break ;
    case 5:
        talk(QString("天天说晚安，我爱你！"));
        break ;
    case 6:
        talk(QString("天天说早安，我爱你！"));
        break ;
    case 7:
        talk(QString("不要这样，我爱你！"));
        break ;
    case 8:
        talk(QString("做我女朋友！！！"));
        break ;
    case 9:
        talk(QString("^3^,亲亲！！！"));
        break ;
    }
}
Widget::~Widget()
{
    delete ui;
}

