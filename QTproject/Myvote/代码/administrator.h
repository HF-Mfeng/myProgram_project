#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<QDate>
#include <QWidget>

namespace Ui {
class administrator;
}

class administrator : public QWidget
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = nullptr);
    ~administrator();
    void auditShow();

    void administratorInitialization();
     void deletCC();











signals:
    void backMain();
    void changeMyCode();

private:
    Ui::administrator *ui;
    void beauty();

   // void havePassed(int reminderPeople ,long long int HisPhone, int activityCode);
    QChar NOJOIN = 'A' , JOIN_NOPASS = 'B' , JOIN_PASS = 'C' , NOPASS = 'D' ;
    QString getUserName( long long int userPhone);
   // void auditPass( long long int userPhone , int activityCode );






    QDate Today ;
    int thisActivityCode;
     void whetherPass(  );
     void sheIsPassed( long long int herPhone  , int i );
     int page  ;
     void showWhichPage(int WhichPage);

     typedef   struct pp{
         int votes ;
         long long phone ;
         QString name ;
         double precentage ;
         int rangking ;
         struct pp *next ;
     } PeoPle;

     void rankVotes( PeoPle human[] , int num );
     int heVotesToHer( long long int hisphone );

    QWidget *cc;
    long long int AllPhones[];



};

#endif // ADMINISTRATOR_H
