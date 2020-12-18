#ifndef MYVOLUM_H
#define MYVOLUM_H

#include <QWidget>

namespace Ui {
class MyVolum;
}

class MyVolum : public QWidget
{
    Q_OBJECT

public:
    explicit MyVolum(QWidget *parent = nullptr);
    ~MyVolum();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

signals:
    void mySize(int w, int h);
    void volumChange(int value);



private:
    Ui::MyVolum *ui;
    int volumValue;
};

#endif // MYVOLUM_H
