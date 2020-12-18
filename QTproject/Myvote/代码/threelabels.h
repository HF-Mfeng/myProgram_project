#ifndef THREELABELS_H
#define THREELABELS_H

#include <QWidget>

namespace Ui {
class threeLabels;
}

class threeLabels : public QWidget
{
    Q_OBJECT

public:
    explicit threeLabels(QWidget *parent , QString left , QString mid ,QString right , int movex , int movey );
    ~threeLabels();

private:
    Ui::threeLabels *ui;
};

#endif // THREELABELS_H
