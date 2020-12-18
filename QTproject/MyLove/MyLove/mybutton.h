#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class mybutton;
}

class mybutton : public QWidget
{
    Q_OBJECT

public:
    explicit mybutton(QWidget *parent = nullptr);
    ~mybutton();

    void enterEvent(QEvent *event) override;
    void setPushbuttonGeometry(int ,int ,int ,int);

signals:
    void hasEnter();

private:
    Ui::mybutton *ui;
};

#endif // MYBUTTON_H
