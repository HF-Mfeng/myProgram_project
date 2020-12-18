#ifndef CHANGECODE_H
#define CHANGECODE_H

#include <QWidget>

namespace Ui {
class changeCode;
}

class changeCode : public QWidget
{
    Q_OBJECT

public:
    explicit changeCode(QWidget *parent = nullptr);
    ~changeCode();
    bool changeUser();
    bool changeAdministory();
    void setPhone( long long phone );

    void init();

signals:
    void yesBack();
    void cancelBack();
private:
    Ui::changeCode *ui;
    long long int thisPhone ;

};

#endif // CHANGECODE_H
