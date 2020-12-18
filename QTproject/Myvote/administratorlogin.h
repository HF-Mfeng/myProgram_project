#ifndef ADMINISTRATORLOGIN_H
#define ADMINISTRATORLOGIN_H

#define PATH QString("./data/")
#define endPATH QString(".dat")

#include <QWidget>

namespace Ui {
class administratorlogin;
}

class administratorlogin : public QWidget
{
    Q_OBJECT

public:
    explicit administratorlogin(QWidget *parent = nullptr);
    ~administratorlogin();
signals:
    void backmain();
    void login();

private:
    Ui::administratorlogin *ui;
    bool checkMyCode();
};

#endif // ADMINISTRATORLOGIN_H
