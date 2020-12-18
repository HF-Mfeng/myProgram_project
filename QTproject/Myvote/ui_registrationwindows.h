/********************************************************************************
** Form generated from reading UI file 'registrationwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOWS_H
#define UI_REGISTRATIONWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registrationWindows
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *usernameinput;
    QLabel *usernamelabel;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *recodeinput;
    QLineEdit *codeinput;
    QSpacerItem *verticalSpacer_4;
    QLabel *codelabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *recodelabel;
    QLineEdit *phoneinput;
    QLabel *phonelabel;
    QPushButton *registrationbtn;
    QPushButton *backmainbtn;

    void setupUi(QDialog *registrationWindows)
    {
        if (registrationWindows->objectName().isEmpty())
            registrationWindows->setObjectName(QString::fromUtf8("registrationWindows"));
        registrationWindows->resize(540, 480);
        QFont font;
        font.setPointSize(12);
        registrationWindows->setFont(font);
        widget = new QWidget(registrationWindows);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 40, 391, 202));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        widget->setFont(font1);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        usernameinput = new QLineEdit(widget);
        usernameinput->setObjectName(QString::fromUtf8("usernameinput"));
        QFont font2;
        font2.setPointSize(9);
        usernameinput->setFont(font2);
        usernameinput->setMouseTracking(false);
        usernameinput->setMaxLength(9);
        usernameinput->setFrame(false);

        gridLayout->addWidget(usernameinput, 3, 1, 1, 1);

        usernamelabel = new QLabel(widget);
        usernamelabel->setObjectName(QString::fromUtf8("usernamelabel"));
        usernamelabel->setFont(font1);

        gridLayout->addWidget(usernamelabel, 3, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 4, 1, 1, 1);

        recodeinput = new QLineEdit(widget);
        recodeinput->setObjectName(QString::fromUtf8("recodeinput"));
        QFont font3;
        font3.setPointSize(10);
        recodeinput->setFont(font3);
        recodeinput->setMouseTracking(false);
        recodeinput->setMaxLength(8);
        recodeinput->setFrame(false);
        recodeinput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(recodeinput, 7, 1, 1, 1);

        codeinput = new QLineEdit(widget);
        codeinput->setObjectName(QString::fromUtf8("codeinput"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(10);
        codeinput->setFont(font4);
        codeinput->setMouseTracking(false);
        codeinput->setMaxLength(8);
        codeinput->setFrame(false);
        codeinput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(codeinput, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 1, 1, 1);

        codelabel = new QLabel(widget);
        codelabel->setObjectName(QString::fromUtf8("codelabel"));
        codelabel->setFont(font1);

        gridLayout->addWidget(codelabel, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 4, 0, 1, 1);

        recodelabel = new QLabel(widget);
        recodelabel->setObjectName(QString::fromUtf8("recodelabel"));
        recodelabel->setFont(font1);

        gridLayout->addWidget(recodelabel, 7, 0, 1, 1);

        phoneinput = new QLineEdit(widget);
        phoneinput->setObjectName(QString::fromUtf8("phoneinput"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(9);
        phoneinput->setFont(font5);
        phoneinput->setMouseTracking(false);
        phoneinput->setMaxLength(11);
        phoneinput->setFrame(false);

        gridLayout->addWidget(phoneinput, 0, 1, 1, 1);

        phonelabel = new QLabel(widget);
        phonelabel->setObjectName(QString::fromUtf8("phonelabel"));
        phonelabel->setFont(font1);

        gridLayout->addWidget(phonelabel, 0, 0, 1, 1);

        registrationbtn = new QPushButton(registrationWindows);
        registrationbtn->setObjectName(QString::fromUtf8("registrationbtn"));
        registrationbtn->setGeometry(QRect(40, 280, 109, 29));
        registrationbtn->setFont(font1);
        backmainbtn = new QPushButton(registrationWindows);
        backmainbtn->setObjectName(QString::fromUtf8("backmainbtn"));
        backmainbtn->setGeometry(QRect(30, 390, 129, 29));
        backmainbtn->setFont(font1);

        retranslateUi(registrationWindows);

        QMetaObject::connectSlotsByName(registrationWindows);
    } // setupUi

    void retranslateUi(QDialog *registrationWindows)
    {
        registrationWindows->setWindowTitle(QCoreApplication::translate("registrationWindows", "Dialog", nullptr));
        usernameinput->setText(QString());
        usernameinput->setPlaceholderText(QCoreApplication::translate("registrationWindows", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\357\274\2149\345\255\227\344\273\245\345\206\205", nullptr));
        usernamelabel->setText(QCoreApplication::translate("registrationWindows", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        recodeinput->setPlaceholderText(QCoreApplication::translate("registrationWindows", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
        codeinput->setText(QString());
        codeinput->setPlaceholderText(QCoreApplication::translate("registrationWindows", "\350\257\267\350\276\223\345\205\2454~8\344\275\215\346\225\260\345\255\227", nullptr));
        codelabel->setText(QCoreApplication::translate("registrationWindows", "\345\257\206\347\240\201\357\274\232", nullptr));
        recodelabel->setText(QCoreApplication::translate("registrationWindows", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        phoneinput->setText(QString());
        phoneinput->setPlaceholderText(QCoreApplication::translate("registrationWindows", "\350\257\267\350\276\223\345\205\245\344\273\2451\345\274\200\345\244\264\347\232\20411\344\275\215\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        phonelabel->setText(QCoreApplication::translate("registrationWindows", "\346\211\213\346\234\272\345\217\267\347\240\201\357\274\232", nullptr));
        registrationbtn->setText(QCoreApplication::translate("registrationWindows", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        backmainbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registrationWindows: public Ui_registrationWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOWS_H
