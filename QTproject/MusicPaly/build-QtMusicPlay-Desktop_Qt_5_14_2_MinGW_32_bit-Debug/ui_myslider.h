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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySlider
{
public:
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QWidget *MySlider)
    {
        if (MySlider->objectName().isEmpty())
            MySlider->setObjectName(QString::fromUtf8("MySlider"));
        MySlider->resize(300, 40);
        MySlider->setMinimumSize(QSize(300, 40));
        MySlider->setMaximumSize(QSize(300, 40));
        MySlider->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider = new QSlider(MySlider);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(50, 5, 250, 30));
        horizontalSlider->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(MySlider);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 50, 40));

        retranslateUi(MySlider);

        QMetaObject::connectSlotsByName(MySlider);
    } // setupUi

    void retranslateUi(QWidget *MySlider)
    {
        MySlider->setWindowTitle(QCoreApplication::translate("MySlider", "Form", nullptr));
        label->setText(QCoreApplication::translate("MySlider", "02:30", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MySlider: public Ui_MySlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSLIDER_H
