#ifndef REGISTRATIONWINDOWS_H
#define REGISTRATIONWINDOWS_H

#include <QDialog>
#include<QString>

namespace Ui {
class registrationWindows;
}

class registrationWindows : public QDialog
{
    Q_OBJECT

public:
    explicit registrationWindows(QWidget *parent = nullptr);
    ~registrationWindows();
    long long int getPhone();
    void clearLineEdit();

signals:
    void registrationtomain();
    void successRegistration();

private:
    Ui::registrationWindows *ui;
    bool checkPhone(QString phoneNumber);
    bool checkCode(QString setCode , QString verifyCode);

    QChar NOJOIN = 'A' , JOIN_NOPASS = 'B' , JOIN_PASS = 'C' , NOPASS = 'D' ;
};

#endif // REGISTRATIONWINDOWS_H
