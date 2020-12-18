#include "matrix.h"

#include <QDebug>

matrix::matrix(int row , int col)
{
    this->col = col ;
    this->row = row ;
}
matrix::matrix(){

}


//获取行和列
int matrix::getcol(){
    return this->col;
}
int matrix::getrow(){
    return this->row;
}

//赋值函数
void matrix::creatMatrix( int a , int position){
    rowcol[position] = a ;
}

//设置行列函数
void matrix::setcol(int col){
    this->col = col ;
}
void matrix::setrow(int row){
    this->row = row ;
}

//获取某个位置矩阵的值
int matrix::getNumber( int position){
    return rowcol[position];
}

//创建一个新的矩阵空间用来存储矩阵
void matrix::newMatrix(){
    this->rowcol = new int[col*row];
}

//重载 +- 运算符，简便代码
matrix matrix::operator+(matrix b){
    matrix c(row,col);
    c.newMatrix();
    for(int i = 0 ; i < col*row ; i++){
        int sum = (b.getNumber(i)) + (this->getNumber(i)) ;
        c.creatMatrix( sum , i);
        qDebug() << "下面是矩阵和中a的第" << i << "个值：" << c.getNumber(i) ;
    }
    return c ;
}
matrix matrix::operator-(matrix b){
    matrix c(row,col);
    c.newMatrix();
    for(int i = 0 ; i < col*row ; i++){
        int sum = (b.getNumber(i)) - (this->getNumber(i)) ;
        qDebug() << "下面是matrix中a的第" << i << "个值：" << (this->getNumber(i)) ;
        c.creatMatrix( sum , i);
    }
    return c ;
}

matrix::~matrix(){
    delete rowcol;
}
