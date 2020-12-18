/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_administrator
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pagechange;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer;
    QPushButton *creatbtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *changecodebtn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *backmainbtn;
    QScrollArea *scrollAreaup;
    QWidget *contentUp;
    QWidget *widget_2;
    QLabel *labelupleft;
    QLabel *labelupmid;
    QLabel *labelupright;
    QScrollArea *scrollAreadown;
    QWidget *contentDown;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *administrator)
    {
        if (administrator->objectName().isEmpty())
            administrator->setObjectName(QString::fromUtf8("administrator"));
        administrator->setEnabled(true);
        administrator->resize(540, 480);
        administrator->setMinimumSize(QSize(540, 480));
        administrator->setMaximumSize(QSize(540, 480));
        widget = new QWidget(administrator);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(420, -3, 117, 481));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pagechange = new QPushButton(widget);
        pagechange->setObjectName(QString::fromUtf8("pagechange"));
        pagechange->setEnabled(false);
        pagechange->setAutoDefault(false);

        verticalLayout->addWidget(pagechange);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        creatbtn = new QPushButton(widget);
        creatbtn->setObjectName(QString::fromUtf8("creatbtn"));

        verticalLayout->addWidget(creatbtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        changecodebtn = new QPushButton(widget);
        changecodebtn->setObjectName(QString::fromUtf8("changecodebtn"));

        verticalLayout->addWidget(changecodebtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        backmainbtn = new QPushButton(widget);
        backmainbtn->setObjectName(QString::fromUtf8("backmainbtn"));

        verticalLayout->addWidget(backmainbtn);

        scrollAreaup = new QScrollArea(administrator);
        scrollAreaup->setObjectName(QString::fromUtf8("scrollAreaup"));
        scrollAreaup->setGeometry(QRect(0, 0, 421, 240));
        scrollAreaup->setMinimumSize(QSize(421, 240));
        scrollAreaup->setMaximumSize(QSize(421, 240));
        scrollAreaup->setWidgetResizable(true);
        contentUp = new QWidget();
        contentUp->setObjectName(QString::fromUtf8("contentUp"));
        contentUp->setGeometry(QRect(0, 0, 419, 1000));
        contentUp->setMinimumSize(QSize(419, 1000));
        widget_2 = new QWidget(contentUp);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 421, 31));
        labelupleft = new QLabel(widget_2);
        labelupleft->setObjectName(QString::fromUtf8("labelupleft"));
        labelupleft->setGeometry(QRect(9, 9, 83, 16));
        labelupmid = new QLabel(widget_2);
        labelupmid->setObjectName(QString::fromUtf8("labelupmid"));
        labelupmid->setGeometry(QRect(160, 10, 60, 16));
        labelupright = new QLabel(widget_2);
        labelupright->setObjectName(QString::fromUtf8("labelupright"));
        labelupright->setGeometry(QRect(330, 10, 60, 16));
        scrollAreaup->setWidget(contentUp);
        scrollAreadown = new QScrollArea(administrator);
        scrollAreadown->setObjectName(QString::fromUtf8("scrollAreadown"));
        scrollAreadown->setGeometry(QRect(0, 240, 421, 240));
        scrollAreadown->setMinimumSize(QSize(421, 240));
        scrollAreadown->setMaximumSize(QSize(421, 240));
        scrollAreadown->setWidgetResizable(true);
        contentDown = new QWidget();
        contentDown->setObjectName(QString::fromUtf8("contentDown"));
        contentDown->setGeometry(QRect(0, 0, 419, 1000));
        contentDown->setMinimumSize(QSize(419, 1000));
        label_2 = new QLabel(contentDown);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 10, 60, 16));
        label = new QLabel(contentDown);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 45, 16));
        scrollAreadown->setWidget(contentDown);

        retranslateUi(administrator);

        pagechange->setDefault(false);


        QMetaObject::connectSlotsByName(administrator);
    } // setupUi

    void retranslateUi(QWidget *administrator)
    {
        administrator->setWindowTitle(QCoreApplication::translate("administrator", "Form", nullptr));
        pagechange->setText(QCoreApplication::translate("administrator", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        creatbtn->setText(QCoreApplication::translate("administrator", "\345\210\233\345\273\272\346\226\260\346\212\225\347\245\250", nullptr));
        changecodebtn->setText(QCoreApplication::translate("administrator", "\346\224\271\345\257\206\347\240\201", nullptr));
        backmainbtn->setText(QCoreApplication::translate("administrator", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        labelupleft->setText(QCoreApplication::translate("administrator", "\347\224\250\346\210\267\345\220\215", nullptr));
        labelupmid->setText(QCoreApplication::translate("administrator", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        labelupright->setText(QCoreApplication::translate("administrator", "\346\212\225\347\245\250\346\254\241\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("administrator", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("administrator", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class administrator: public Ui_administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
