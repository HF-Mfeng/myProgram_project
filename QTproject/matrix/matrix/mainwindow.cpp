#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"

#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QDebug>
#include<QRegExp>
#include<QRegularExpressionValidator>
#include<QLabel>
#include<QWidget>
#include<QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    matrix1.setcol(0); //初始化矩阵1和2的行列
    matrix1.setrow(0);
    matrix2.setcol(0);
    matrix2.setrow(0);

    this->setWindowTitle(QString("矩阵运算")); //设置窗口标题

    this->matrixNumber = 1 ; //初始化矩阵n的值
    QRegExp re("([1-6])");//正则表达式设置矩阵大小为1-6，不然窗口容纳不下

    //设置行列式输入为6*6以内
    QValidator *vo = new QRegExpValidator(re , ui->lineEdit_col);
    ui->lineEdit_col->setValidator(vo);
    ui->lineEdit_row->setValidator(vo);

    //设置生成按钮的连接
    connect(ui->btn_creat , &QPushButton::clicked , [=](){
        this->creatBtn();
    });

    //设置增加按钮的连接
    connect(ui->btn_add,&QPushButton::clicked,[=](){
        if(matrix1.getcol()!=0 && matrix1.getrow()!=0 && matrix1.getcol()==matrix2.getcol() && matrix1.getrow()==matrix2.getrow()){
            this->matrixAdd();
        }
    });

    //设置退出按钮
    connect(ui->btn_exit,&QPushButton::clicked , [=](){
        MainWindow *w = new MainWindow;
        w->setGeometry(this->geometry());
        w->show();

        //设置延迟，使界面切换美观
        QTime dietime = QTime::currentTime().addMSecs(200);
        while(QTime::currentTime()<dietime)
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);

        this->close();
    });

    //设置减少按钮的连接
    connect(ui->btn_minus,&QPushButton::clicked,[=](){
        if(matrix1.getcol()!=0 && matrix1.getrow()!=0 && matrix1.getcol()==matrix2.getcol() && matrix1.getrow()==matrix2.getrow()){
            this->matrixRelease();
        }
    });

    //设置转置按钮的连接
    connect(ui->btn_transpose,&QPushButton::clicked,[=](){
        this->setMatrix(matrix1,line1);
        this->tranpose(matrix1);
    });

}

void MainWindow::creatBtn(){
    QRegExp regx("([0])|([0-9]+)");  //正则表达式限制输入

    if(ui->lineEdit_col->text()!=QString("") && ui->lineEdit_row->text()!=QString("")){  //判断是否行与列都有输入

        //获取行列的值
        col = ui->lineEdit_col->text().toInt();
        row = ui->lineEdit_row->text().toInt();

        if(matrixNumber == 1){ //矩阵1的输入
            line1 = new QLineEdit[row*col]; //矩阵1 的申请和判断是否有剩余空间
            if(line1 == NULL )
                return ;

            for (int i  = 0 ; i < row*col; i++ ) {
                //初始化矩阵1的行列
                this->matrix1.setcol(this->col);
                this->matrix1.setrow(this->row);

                //并开辟足够空间来存储矩阵1的值
                matrix1.newMatrix();

                //生成lineEdit来输入矩阵的值
                line1[i].setParent(ui->widget1);
                line1[i].setGeometry(0+(i%col)*(45) ,0+(i/col)*(190/row) , 40 , 190/row - 3*(row-1));
                line1[i].setMaxLength(2); //设置输入长度为2
                QValidator *validator = new QRegExpValidator(regx,&line1[i]);
                line1[i].setValidator(validator); //设置输入只能为数字
                line1[i].show();
            }
            matrixNumber = 2 ; //将矩阵选择置为2，并且顺便改动显示
            this->ui->label_information->setText(QString("请输入第二个矩阵行与列："));
        }else{
            if(matrixNumber == 2){
                line2 = new QLineEdit[row*col];
                for (int i  = 0 ; i < row*col; i++ ) {//功能方法同上
                    this->matrix2.setcol(this->col);
                    this->matrix2.setrow(this->row);
                    matrix2.newMatrix();
                    line2[i].setParent(ui->widget2);
                    line2[i].setGeometry(0+(i%col)*(45) ,0+(i/col)*(190/row) , 40 , 190/row - 3*(row-1));
                    line2[i].setMaxLength(2);
                    QValidator *validator = new QRegExpValidator(regx,&line2[i]);
                    line2[i].setValidator(validator);
                    line2[i].show();
                }
                matrixNumber = 0 ;
            }
        }
    }

}

void MainWindow::setMatrix(matrix matrixn,QLineEdit *lineEdit){   //将输入的值赋值给对应矩阵
    for( int i=0; i < row*col ; i++ ){
        if(lineEdit[i].text()==QString(""))
            lineEdit[i].setText(QString("").number(0));
        matrixn.creatMatrix( lineEdit[i].text().toInt(), i);
    }
}

void MainWindow::matrixAdd(){ //矩阵相加函数
    this->setMatrix(matrix1,line1); //赋值矩阵1和2
    this->setMatrix(matrix2,line2);
    matrix sum = matrix1+matrix2;

    QLabel *sum_label = new QLabel(this); //设置输出显示，使用的使qwidget中放qlabel来显示的
    sum_label->setGeometry(160,160,60,40);
    sum_label->setText(QString("结果:"));
    sum_label->show();
    QWidget *sum_widget = new QWidget(this);
    sum_widget->setGeometry(229,100,491,191);
    sum_widget->show();
    for (int i = 0 ;i < col*row ;i++) {  //将结果循环显示出来
        QLabel *labels = new QLabel(sum_widget);
        labels->setNum(sum.getNumber(i));
        labels->setGeometry(0+(i%col)*(45) ,0+(i/col)*(190/row) , 40 , 190/row - 3*(row-1));
        labels->show();
    }

    this->ui->label1->hide(); //隐藏刚刚两个矩阵
    this->ui->widget1->hide();
    this->ui->label2->hide();
    this->ui->widget2->hide();
}

void MainWindow::matrixRelease(){  //减法运算，除了使减法，其他都差不多
    this->setMatrix(matrix1,line1);
    this->setMatrix(matrix2,line2);
    matrix sum = matrix2-matrix1;

    QLabel *sum_label = new QLabel(this);
    sum_label->setGeometry(160,160,60,40);
    sum_label->setText(QString("结果:"));
    sum_label->show();
    QWidget *sum_widget = new QWidget(this);
    sum_widget->setGeometry(229,100,491,191);
    sum_widget->show();
    for (int i = 0 ;i < col*row ;i++) {
        QLabel *labels = new QLabel(sum_widget);
        labels->setText(QString::number(sum.getNumber(i)));
        labels->setGeometry(0+(i%col)*(45) ,0+(i/col)*(190/row) , 40 , 190/row - 3*(row-1));
        labels->show();
    }

    this->ui->label1->hide();
    this->ui->widget1->hide();
    this->ui->label2->hide();
    this->ui->widget2->hide();
}

void MainWindow::tranpose(matrix matrixn){  //转置，不用进行，只是将输出的顺序行变成列而已了
    QLabel *sum_label = new QLabel(this);
    sum_label->setGeometry(160,160,60,40);
    sum_label->setText(QString("结果:"));
    sum_label->show();
    QWidget *sum_widget = new QWidget(this);
    sum_widget->setGeometry(229,100,491,191);
    sum_widget->show();
    for (int i = 0 ;i < col*row ;i++) {
        QLabel *labels = new QLabel(sum_widget);
        labels->setText(QString::number(matrixn.getNumber(i)));
        labels->setGeometry(0+(i/col)*(45) ,0+(i%col)*(190/row) , 40 , 190/col - 3*(col-1));
        labels->show();
    }

    this->ui->label1->hide();
    this->ui->widget1->hide();
    this->ui->label2->hide();
    this->ui->widget2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

