/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *phoneinput;
    QLineEdit *codeinput;
    QLabel *codelabel;
    QLabel *phonelabel;
    QPushButton *enterBtn;
    QPushButton *registeredBtn;
    QPushButton *administratorBtn;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(540, 480);
        MainWindow->setMinimumSize(QSize(540, 480));
        MainWindow->setMaximumSize(QSize(540, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 310, 341, 171));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        phoneinput = new QLineEdit(widget);
        phoneinput->setObjectName(QString::fromUtf8("phoneinput"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        phoneinput->setFont(font1);
        phoneinput->setMaxLength(11);
        phoneinput->setFrame(false);
        phoneinput->setCursorPosition(0);
        phoneinput->setDragEnabled(false);
        phoneinput->setReadOnly(false);

        gridLayout->addWidget(phoneinput, 1, 1, 1, 1);

        codeinput = new QLineEdit(widget);
        codeinput->setObjectName(QString::fromUtf8("codeinput"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(11);
        codeinput->setFont(font2);
        codeinput->setText(QString::fromUtf8(""));
        codeinput->setMaxLength(8);
        codeinput->setFrame(false);
        codeinput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(codeinput, 2, 1, 1, 1);

        codelabel = new QLabel(widget);
        codelabel->setObjectName(QString::fromUtf8("codelabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        codelabel->setFont(font3);

        gridLayout->addWidget(codelabel, 2, 0, 1, 1);

        phonelabel = new QLabel(widget);
        phonelabel->setObjectName(QString::fromUtf8("phonelabel"));
        phonelabel->setFont(font3);

        gridLayout->addWidget(phonelabel, 1, 0, 1, 1);

        enterBtn = new QPushButton(centralwidget);
        enterBtn->setObjectName(QString::fromUtf8("enterBtn"));
        enterBtn->setGeometry(QRect(420, 280, 93, 29));
        enterBtn->setFont(font);
        registeredBtn = new QPushButton(centralwidget);
        registeredBtn->setObjectName(QString::fromUtf8("registeredBtn"));
        registeredBtn->setGeometry(QRect(420, 370, 93, 29));
        registeredBtn->setFont(font);
        administratorBtn = new QPushButton(centralwidget);
        administratorBtn->setObjectName(QString::fromUtf8("administratorBtn"));
        administratorBtn->setGeometry(QRect(410, 450, 109, 29));
        administratorBtn->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 471, 251));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/Vote1.png")));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        phoneinput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        codeinput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
        codelabel->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201:", nullptr));
        phonelabel->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267\347\240\201:", nullptr));
        enterBtn->setText(QString());
        registeredBtn->setText(QString());
        administratorBtn->setText(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
