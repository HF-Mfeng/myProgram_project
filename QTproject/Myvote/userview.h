#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>
#include<QString>

namespace Ui {
class userview;
}

class userview : public QWidget
{
    Q_OBJECT

public:
    explicit userview(QWidget *parent = nullptr);
    explicit userview(QWidget *parent ,long long int Qphone, int Qvotes , int Qranking ,double Qpercentage );
    explicit userview(QWidget *parent ,long long int Qphone, int Qvotes , int Qranking ,double Qpercentage ,int movex,int movey);
    //explicit userview(QWidget *parent ,long long int Qphone, int Qvotes , int Qranking ,                    int movex,int movey,QString btn);
    ~userview();
    void setphone(QString);
    void setvotes(QString);
    void setranking(QString);
    void setpercentage(QString);
    void addVotes();

signals:
    void yes ();

private:
    Ui::userview *ui;
//    long long int phone;
//    int votes , ranking,percentage  ;
};

#endif // USERVIEW_H
