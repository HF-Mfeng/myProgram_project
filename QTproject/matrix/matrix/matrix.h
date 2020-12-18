#ifndef MATRIX_H
#define MATRIX_H


class matrix
{
public:
    matrix(int row , int col);
    matrix();
    ~matrix();
    int getrow();
    int getcol();
    void setrow( int row ) ;
    void setcol(int col);
    void creatMatrix( int a , int position);
    void newMatrix();
    int getNumber(int position);
    matrix operator+(matrix b);
    matrix operator-(matrix b);
    /*matrix transpose(matrix input);*/
private:
    int row , col ;
    int *rowcol;
};

#endif // MATRIX_H
