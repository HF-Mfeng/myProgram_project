/********************************************************************************
** Form generated from reading UI file 'createactivity.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACTIVITY_H
#define UI_CREATEACTIVITY_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createActivity
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *firstTime;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDateEdit *secondTime;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDateEdit *thirdTime;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QPushButton *cancelbtn;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *yesbtn;
    QRadioButton *nobtn;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *setVotes;
    QPushButton *creatbtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *createActivity)
    {
        if (createActivity->objectName().isEmpty())
            createActivity->setObjectName(QString::fromUtf8("createActivity"));
        createActivity->resize(540, 480);
        createActivity->setMinimumSize(QSize(540, 480));
        createActivity->setMaximumSize(QSize(540, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        createActivity->setFont(font);
        gridLayout_2 = new QGridLayout(createActivity);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_6 = new QWidget(createActivity);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout = new QVBoxLayout(widget_6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        firstTime = new QDateEdit(widget_3);
        firstTime->setObjectName(QString::fromUtf8("firstTime"));
        firstTime->setMaximumDateTime(QDateTime(QDate(2100, 1, 1), QTime(23, 59, 59)));
        firstTime->setMinimumDateTime(QDateTime(QDate(2020, 5, 25), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(firstTime);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        secondTime = new QDateEdit(widget_4);
        secondTime->setObjectName(QString::fromUtf8("secondTime"));
        secondTime->setMaximumDateTime(QDateTime(QDate(2100, 1, 1), QTime(23, 59, 59)));
        secondTime->setMinimumDateTime(QDateTime(QDate(2020, 5, 25), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(secondTime);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        thirdTime = new QDateEdit(widget_5);
        thirdTime->setObjectName(QString::fromUtf8("thirdTime"));
        thirdTime->setMaximumDate(QDate(2100, 1, 1));
        thirdTime->setMinimumDate(QDate(2020, 5, 25));

        horizontalLayout_4->addWidget(thirdTime);


        verticalLayout->addWidget(widget_5);


        gridLayout_2->addWidget(widget_6, 3, 1, 1, 1);

        widget_7 = new QWidget(createActivity);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEdit = new QLineEdit(widget_7);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFrame(false);

        horizontalLayout_5->addWidget(lineEdit);


        gridLayout_2->addWidget(widget_7, 0, 1, 1, 1);

        cancelbtn = new QPushButton(createActivity);
        cancelbtn->setObjectName(QString::fromUtf8("cancelbtn"));

        gridLayout_2->addWidget(cancelbtn, 4, 3, 1, 1);

        widget = new QWidget(createActivity);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        yesbtn = new QRadioButton(widget);
        yesbtn->setObjectName(QString::fromUtf8("yesbtn"));

        gridLayout->addWidget(yesbtn, 0, 1, 2, 1);

        nobtn = new QRadioButton(widget);
        nobtn->setObjectName(QString::fromUtf8("nobtn"));

        gridLayout->addWidget(nobtn, 2, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget, 1, 1, 1, 2);

        widget_2 = new QWidget(createActivity);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        setVotes = new QSpinBox(widget_2);
        setVotes->setObjectName(QString::fromUtf8("setVotes"));
        setVotes->setFrame(false);
        setVotes->setMaximum(9);

        horizontalLayout->addWidget(setVotes);


        gridLayout_2->addWidget(widget_2, 2, 1, 1, 1);

        creatbtn = new QPushButton(createActivity);
        creatbtn->setObjectName(QString::fromUtf8("creatbtn"));

        gridLayout_2->addWidget(creatbtn, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);


        retranslateUi(createActivity);

        QMetaObject::connectSlotsByName(createActivity);
    } // setupUi

    void retranslateUi(QWidget *createActivity)
    {
        createActivity->setWindowTitle(QCoreApplication::translate("createActivity", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("createActivity", "\346\212\245\345\220\215\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("createActivity", "\346\212\225\347\245\250\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("createActivity", "\346\210\252\346\255\242\346\227\266\351\227\264\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("createActivity", "\346\264\273\345\212\250\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("createActivity", "\350\257\267\351\231\220\345\210\2669\344\270\252\345\255\227\347\254\246\344\273\245\345\206\205", nullptr));
        cancelbtn->setText(QCoreApplication::translate("createActivity", "\345\217\226\346\266\210", nullptr));
        yesbtn->setText(QCoreApplication::translate("createActivity", "\346\230\257", nullptr));
        nobtn->setText(QCoreApplication::translate("createActivity", "\345\220\246", nullptr));
        label->setText(QCoreApplication::translate("createActivity", "\346\230\257\345\220\246\346\233\264\346\226\260\346\212\225\347\245\250\350\200\205\346\257\217\345\244\251\350\203\275\346\212\225\347\245\250\346\225\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("createActivity", "\347\224\250\346\210\267\347\245\250\346\225\260\357\274\232", nullptr));
        creatbtn->setText(QCoreApplication::translate("createActivity", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createActivity: public Ui_createActivity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACTIVITY_H
