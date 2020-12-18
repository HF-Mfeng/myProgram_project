#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>
#include <QTime>

namespace Ui {
class MySlider;
}

class MySlider : public QWidget
{
    Q_OBJECT

public:
    explicit MySlider(QWidget *parent = nullptr);

    ~MySlider();


//    void enterEvent(QEvent *event) override;

    void showAllTiem(QTime *time);

    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    int getSliderValue();
    void setSliderValue(int value);
    void setSliderMax(int max);
    void setTimeShow(QTime *time);
signals:
    void mySliderChange();

private:
    Ui::MySlider *ui;
    int value;
    void emitMySignals(){
        emit mySliderChange();
    }


    enum{VOLUM=0,SLIDER};
};

#endif // MYSLIDER_H
