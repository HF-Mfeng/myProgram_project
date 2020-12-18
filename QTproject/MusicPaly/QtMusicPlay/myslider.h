#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>
#include <QSlider>

namespace Ui {
class MySlider;
}

class MySlider : public QSlider
{
    Q_OBJECT
signals:
    void MySliderMouseClicked();
public:
    explicit MySlider(QWidget *parent = nullptr);
    ~MySlider();
    void mouseMoveEvent(QMouseEvent *event) ;
private:
    Ui::MySlider *ui;
};

#endif // MYSLIDER_H
