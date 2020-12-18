#include "mybutton.h"
#include "ui_mybutton.h"

mybutton::mybutton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mybutton)
{
    ui->setupUi(this);
}
void mybutton::enterEvent(QEvent *event){
    emit hasEnter();
}
void mybutton::setPushbuttonGeometry(int x, int y, int w , int h){
    ui->pushButton->setGeometry(x,y ,w ,h );
}

mybutton::~mybutton()
{
    delete ui;
}
