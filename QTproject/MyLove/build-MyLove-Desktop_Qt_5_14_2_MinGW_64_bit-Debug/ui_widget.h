/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mybutton.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnLove;
    QLabel *label;
    QLabel *labelText;
    mybutton *widget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 400);
        Widget->setMinimumSize(QSize(400, 400));
        Widget->setMaximumSize(QSize(400, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        Widget->setFont(font);
        btnLove = new QPushButton(Widget);
        btnLove->setObjectName(QString::fromUtf8("btnLove"));
        btnLove->setGeometry(QRect(0, 300, 400, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(28);
        btnLove->setFont(font1);
        btnLove->setStyleSheet(QString::fromUtf8("border:0;"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 400, 80));
        QFont font2;
        font2.setPointSize(41);
        label->setFont(font2);
        labelText = new QLabel(Widget);
        labelText->setObjectName(QString::fromUtf8("labelText"));
        labelText->setGeometry(QRect(0, 80, 400, 120));
        QFont font3;
        font3.setPointSize(15);
        labelText->setFont(font3);
        widget = new mybutton(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 210, 100, 40));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnLove->setText(QCoreApplication::translate("Widget", "\345\226\234\346\254\242", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\275\240\345\226\234\346\254\242\346\210\221\345\220\227\357\274\237", nullptr));
        labelText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
