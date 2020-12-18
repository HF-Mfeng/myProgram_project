#ifndef YIGEJIEMIAN_H
#define YIGEJIEMIAN_H

#include <QWidget>

namespace Ui {
class yigejiemian;
}

class yigejiemian : public QWidget
{
    Q_OBJECT

public:
    explicit yigejiemian(QWidget *parent = nullptr);
    ~yigejiemian();

private:
    Ui::yigejiemian *ui;
};

#endif // YIGEJIEMIAN_H
