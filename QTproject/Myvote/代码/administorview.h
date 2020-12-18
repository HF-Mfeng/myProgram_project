#ifndef ADMINISTORVIEW_H
#define ADMINISTORVIEW_H

#include <QWidget>
#include<QString>

namespace Ui {
class administorview;
}

class administorview : public QWidget
{
    Q_OBJECT

public:
    explicit administorview(QWidget *parent = nullptr);
    explicit administorview(QWidget *parent  , QString hisname , long long int hisphone , int movex , int movey);
    ~administorview();
    //enum{UserInformation,VoterInformation,AuditVoter};
signals:
    void yes();


private:
    Ui::administorview *ui;


};

class threelabels : public QWidget{
    Q_OBJECT
public:
    explicit threelabels(QWidget *parent , QString anName , long long int aPhone , int givevotes , int movex ,int movey);
    explicit threelabels(QWidget *parent , int rank ,long long int aPhone , int manyvotes , int movex ,int movey);
    ~threelabels();
};

#endif // ADMINISTORVIEW_H
