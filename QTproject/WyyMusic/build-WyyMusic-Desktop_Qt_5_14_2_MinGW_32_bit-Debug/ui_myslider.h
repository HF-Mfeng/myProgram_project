/********************************************************************************
** Form generated from reading UI file 'myslider.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSLIDER_H
#define UI_MYSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySlider
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSlider *horizontalSlider;

    void setupUi(QWidget *MySlider)
    {
        if (MySlider->objectName().isEmpty())
            MySlider->setObjectName(QString::fromUtf8("MySlider"));
        MySlider->resize(500, 40);
        MySlider->setMinimumSize(QSize(500, 40));
        MySlider->setMaximumSize(QSize(500, 40));
        MySlider->setStyleSheet(QString::fromUtf8("border:0"));
        horizontalLayout = new QHBoxLayout(MySlider);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(MySlider);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("border:0"));

        horizontalLayout->addWidget(pushButton);

        horizontalSlider = new QSlider(MySlider);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setStyleSheet(QString::fromUtf8("border:0"));
        horizontalSlider->setMaximum(10000000);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(MySlider);

        QMetaObject::connectSlotsByName(MySlider);
    } // setupUi

    void retranslateUi(QWidget *MySlider)
    {
        MySlider->setWindowTitle(QCoreApplication::translate("MySlider", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MySlider", "00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MySlider: public Ui_MySlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSLIDER_H
