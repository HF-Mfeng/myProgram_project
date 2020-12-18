#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEvent>
#include <QCloseEvent>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //进入事件，关闭事件，最小化事件
    void enterEvent(QEvent *event) override;
    void changeEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::Widget *ui;
    int randNumber(char c);
    int mode ;
    void talk(QString str);
    void talk(int m);
    enum{MIN,CLOSE};
    int nowXuhao;
};
#endif // WIDGET_H
