#ifndef USER_H
#define USER_H

#define PATH QString("./data/")
#define endPATH QString(".dat")

#include <QWidget>
#include<QDate>
#include<QInputDialog>

#include"changecode.h"

namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr );

    ~user();

    void UserInitialization( long long int UserPhone );
     void deleteCan();


signals:
    void exitlogin();

private:
    Ui::user *ui;
    QDate Today;

    const QChar YES = 'Y';
    const QChar NO = 'N';
    void signup();
    long long int phone ;
    QChar NOJOIN = 'A' , JOIN_NOPASS = 'B' , JOIN_PASS = 'C' , NOPASS = 'D' ;
    int thisActivityCode ;

    typedef   struct pp{
        int votes ;
        long long phone ;
        QString name ;
        double precentage ;
        int rangking ;
        struct pp *next ;
    } PeoPle;


    void zeroActivity();
    int heVotesToHer(long long hisphone);
    void applyDate(); //报名
    void voteDate();  //投票
    void rankVotes( PeoPle human[] , int num );
    void voteForHer( long long int MyPhone , long long int HerPhone , int thisActivity );
    bool ItisVoteSuccess();
    QWidget *can ;

    void beauty();

    changeCode *change ;


     QString getUserName( long long int userPhone); //得到用户名
     QInputDialog *input;

};

#endif // USER_H
