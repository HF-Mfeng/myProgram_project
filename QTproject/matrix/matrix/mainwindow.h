#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int matrixNumber  ;
    QLineEdit * line1 , *line2 ;
    int row , col ;
    void creatBtn();
    matrix matrix1 , matrix2 ;
    void setMatrix(matrix matrixn,QLineEdit *lineEdit);
    void matrixAdd();
    void matrixRelease();
    void tranpose(matrix matrixn);

};
#endif // MAINWINDOW_H
