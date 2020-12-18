/********************************************************************************
** Form generated from reading UI file 'userview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERVIEW_H
#define UI_USERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userview
{
public:
    QLabel *phone;
    QLabel *votes;
    QLabel *ranking;
    QLabel *percentage;
    QPushButton *votebtn;

    void setupUi(QWidget *userview)
    {
        if (userview->objectName().isEmpty())
            userview->setObjectName(QString::fromUtf8("userview"));
        userview->resize(416, 40);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        userview->setFont(font);
        phone = new QLabel(userview);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(9, 9, 101, 16));
        votes = new QLabel(userview);
        votes->setObjectName(QString::fromUtf8("votes"));
        votes->setGeometry(QRect(135, 9, 31, 16));
        ranking = new QLabel(userview);
        ranking->setObjectName(QString::fromUtf8("ranking"));
        ranking->setGeometry(QRect(192, 9, 21, 20));
        percentage = new QLabel(userview);
        percentage->setObjectName(QString::fromUtf8("percentage"));
        percentage->setGeometry(QRect(245, 9, 71, 20));
        votebtn = new QPushButton(userview);
        votebtn->setObjectName(QString::fromUtf8("votebtn"));
        votebtn->setGeometry(QRect(330, 10, 81, 28));

        retranslateUi(userview);

        QMetaObject::connectSlotsByName(userview);
    } // setupUi

    void retranslateUi(QWidget *userview)
    {
        userview->setWindowTitle(QCoreApplication::translate("userview", "Form", nullptr));
        phone->setText(QCoreApplication::translate("userview", "18692860733", nullptr));
        votes->setText(QCoreApplication::translate("userview", "195", nullptr));
        ranking->setText(QCoreApplication::translate("userview", "19", nullptr));
        percentage->setText(QCoreApplication::translate("userview", "30%", nullptr));
        votebtn->setText(QCoreApplication::translate("userview", "\344\270\272ta\346\212\225\347\245\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userview: public Ui_userview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERVIEW_H
