#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PATH QString("./data/")
#define endPATH QString(".dat")

#include <QMainWindow>
#include<QDate>

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
    void beauty();
    void InitialCheck();
    QDate aDay;
    bool successlog(QString phone , QString code );
};
#endif // MAINWINDOW_H

