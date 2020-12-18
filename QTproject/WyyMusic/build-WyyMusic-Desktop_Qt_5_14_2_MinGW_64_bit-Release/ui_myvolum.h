/********************************************************************************
** Form generated from reading UI file 'myvolum.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYVOLUM_H
#define UI_MYVOLUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyVolum
{
public:
    QLabel *label;
    QSlider *verticalSlider;

    void setupUi(QWidget *MyVolum)
    {
        if (MyVolum->objectName().isEmpty())
            MyVolum->setObjectName(QString::fromUtf8("MyVolum"));
        MyVolum->resize(42, 200);
        MyVolum->setMinimumSize(QSize(42, 20));
        MyVolum->setMaximumSize(QSize(42, 200));
        MyVolum->setStyleSheet(QString::fromUtf8("border:0;"));
        label = new QLabel(MyVolum);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 180, 42, 20));
        label->setMinimumSize(QSize(42, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("text-align:center;"));
        verticalSlider = new QSlider(MyVolum);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(9, 0, 22, 180));
        verticalSlider->setOrientation(Qt::Vertical);

        retranslateUi(MyVolum);

        QMetaObject::connectSlotsByName(MyVolum);
    } // setupUi

    void retranslateUi(QWidget *MyVolum)
    {
        MyVolum->setWindowTitle(QCoreApplication::translate("MyVolum", "Form", nullptr));
        label->setText(QCoreApplication::translate("MyVolum", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyVolum: public Ui_MyVolum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYVOLUM_H
