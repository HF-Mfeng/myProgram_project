#ifndef CREATEACTIVITY_H
#define CREATEACTIVITY_H

#define PATH QString("./data/")
#define endPATH QString(".dat")


#include <QWidget>
#include<QDate>

namespace Ui {
class createActivity;
}

class createActivity : public QWidget
{
    Q_OBJECT

public:
    explicit createActivity(QWidget *parent = nullptr);
    ~createActivity();

signals:
    void backAdministrator();
    void successCreat();

private:
    Ui::createActivity *ui;
    void creatAnActivity();
    const QChar YES = 'Y';
    const QChar NO = 'N';
    bool checkSetting();
    QDate today;
};

#endif // CREATEACTIVITY_H
