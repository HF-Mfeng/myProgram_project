/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *activityName;
    QPushButton *signUpbtn;
    QPushButton *searchbtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *searchinput;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *voteOrregister;
    QLabel *remaindDay;
    QLabel *passDay;
    QPushButton *changecodebtn;
    QPushButton *changenamebtn;
    QPushButton *backmainbtn;

    void setupUi(QWidget *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(540, 480);
        user->setMinimumSize(QSize(540, 480));
        user->setMaximumSize(QSize(540, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        user->setFont(font);
        widget_3 = new QWidget(user);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 80, 311, 41));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(user);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setGeometry(QRect(0, 120, 441, 361));
        scrollArea->setMinimumSize(QSize(441, 361));
        scrollArea->setMaximumSize(QSize(441, 361));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 440, 900));
        scrollAreaWidgetContents->setMinimumSize(QSize(440, 900));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(user);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 581, 89));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        activityName = new QLabel(layoutWidget);
        activityName->setObjectName(QString::fromUtf8("activityName"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        activityName->setFont(font1);
        activityName->setMouseTracking(false);

        gridLayout->addWidget(activityName, 0, 1, 1, 1);

        signUpbtn = new QPushButton(layoutWidget);
        signUpbtn->setObjectName(QString::fromUtf8("signUpbtn"));

        gridLayout->addWidget(signUpbtn, 0, 3, 1, 1);

        searchbtn = new QPushButton(layoutWidget);
        searchbtn->setObjectName(QString::fromUtf8("searchbtn"));

        gridLayout->addWidget(searchbtn, 1, 3, 1, 1);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        searchinput = new QLineEdit(widget_2);
        searchinput->setObjectName(QString::fromUtf8("searchinput"));
        searchinput->setMaxLength(11);
        searchinput->setFrame(false);

        horizontalLayout->addWidget(searchinput);


        gridLayout->addWidget(widget_2, 1, 0, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 5, 1, 1);

        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        voteOrregister = new QLabel(widget_4);
        voteOrregister->setObjectName(QString::fromUtf8("voteOrregister"));

        verticalLayout_2->addWidget(voteOrregister);

        remaindDay = new QLabel(widget_4);
        remaindDay->setObjectName(QString::fromUtf8("remaindDay"));

        verticalLayout_2->addWidget(remaindDay);

        passDay = new QLabel(widget_4);
        passDay->setObjectName(QString::fromUtf8("passDay"));

        verticalLayout_2->addWidget(passDay);


        gridLayout->addWidget(widget_4, 0, 4, 2, 2);

        changecodebtn = new QPushButton(user);
        changecodebtn->setObjectName(QString::fromUtf8("changecodebtn"));
        changecodebtn->setGeometry(QRect(450, 250, 83, 28));
        changenamebtn = new QPushButton(user);
        changenamebtn->setObjectName(QString::fromUtf8("changenamebtn"));
        changenamebtn->setGeometry(QRect(450, 330, 83, 28));
        backmainbtn = new QPushButton(user);
        backmainbtn->setObjectName(QString::fromUtf8("backmainbtn"));
        backmainbtn->setGeometry(QRect(450, 420, 83, 28));

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QWidget *user)
    {
        user->setWindowTitle(QCoreApplication::translate("user", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("user", "\345\217\202\351\200\211\345\257\271\350\261\241", nullptr));
        label_3->setText(QCoreApplication::translate("user", "\347\245\250\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("user", "\346\216\222\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("user", "\347\231\276\345\210\206\346\257\224", nullptr));
        label_6->setText(QCoreApplication::translate("user", "\345\275\223\345\211\215\346\264\273\345\212\250\357\274\232", nullptr));
        activityName->setText(QString());
        signUpbtn->setText(QCoreApplication::translate("user", "\346\212\245\345\220\215", nullptr));
        searchbtn->setText(QCoreApplication::translate("user", "\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("user", "\346\220\234\347\264\242\357\274\232", nullptr));
        searchinput->setText(QString());
        searchinput->setPlaceholderText(QCoreApplication::translate("user", "\350\257\267\350\276\223\345\205\245\345\256\214\346\225\264\347\224\265\350\257\235\345\217\267\347\240\201\346\237\245\350\257\242", nullptr));
        voteOrregister->setText(QString());
        remaindDay->setText(QString());
        passDay->setText(QString());
        changecodebtn->setText(QCoreApplication::translate("user", "\346\224\271\345\257\206\347\240\201", nullptr));
        changenamebtn->setText(QCoreApplication::translate("user", "\346\224\271\347\224\250\346\210\267\345\220\215", nullptr));
        backmainbtn->setText(QCoreApplication::translate("user", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
