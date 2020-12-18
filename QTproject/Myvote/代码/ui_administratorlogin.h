/********************************************************************************
** Form generated from reading UI file 'administratorlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORLOGIN_H
#define UI_ADMINISTRATORLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_administratorlogin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *loginbtn;
    QPushButton *backbtn;
    QPushButton *forgiveCode;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *administratorlogin)
    {
        if (administratorlogin->objectName().isEmpty())
            administratorlogin->setObjectName(QString::fromUtf8("administratorlogin"));
        administratorlogin->resize(540, 480);
        administratorlogin->setMinimumSize(QSize(540, 480));
        administratorlogin->setMaximumSize(QSize(540, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        administratorlogin->setFont(font);
        gridLayout = new QGridLayout(administratorlogin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(administratorlogin);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(8);
        lineEdit->setFrame(false);
        lineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(administratorlogin);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        loginbtn = new QPushButton(widget);
        loginbtn->setObjectName(QString::fromUtf8("loginbtn"));

        horizontalLayout->addWidget(loginbtn);

        backbtn = new QPushButton(widget);
        backbtn->setObjectName(QString::fromUtf8("backbtn"));

        horizontalLayout->addWidget(backbtn);

        forgiveCode = new QPushButton(widget);
        forgiveCode->setObjectName(QString::fromUtf8("forgiveCode"));

        horizontalLayout->addWidget(forgiveCode);


        verticalLayout->addWidget(widget);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 225, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 2, 1, 1);


        retranslateUi(administratorlogin);

        QMetaObject::connectSlotsByName(administratorlogin);
    } // setupUi

    void retranslateUi(QWidget *administratorlogin)
    {
        administratorlogin->setWindowTitle(QCoreApplication::translate("administratorlogin", "Form", nullptr));
        label->setText(QCoreApplication::translate("administratorlogin", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201\357\274\232", nullptr));
        loginbtn->setText(QCoreApplication::translate("administratorlogin", "\347\231\273\345\275\225", nullptr));
        backbtn->setText(QCoreApplication::translate("administratorlogin", "\350\277\224\345\233\236", nullptr));
        forgiveCode->setText(QCoreApplication::translate("administratorlogin", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class administratorlogin: public Ui_administratorlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORLOGIN_H
