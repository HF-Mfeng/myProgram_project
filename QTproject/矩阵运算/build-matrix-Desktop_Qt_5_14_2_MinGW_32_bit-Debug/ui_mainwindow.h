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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_add;
    QPushButton *btn_minus;
    QPushButton *btn_transpose;
    QPushButton *btn_exit;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_row;
    QLabel *label;
    QLineEdit *lineEdit_col;
    QPushButton *btn_creat;
    QLabel *label_information;
    QLabel *label1;
    QLabel *label2;
    QWidget *widget1;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 480);
        MainWindow->setMinimumSize(QSize(720, 480));
        MainWindow->setMaximumSize(QSize(720, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(230, 298, 491, 191));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 100, 141, 381));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_add = new QPushButton(widget_2);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        verticalLayout->addWidget(btn_add);

        btn_minus = new QPushButton(widget_2);
        btn_minus->setObjectName(QString::fromUtf8("btn_minus"));

        verticalLayout->addWidget(btn_minus);

        btn_transpose = new QPushButton(widget_2);
        btn_transpose->setObjectName(QString::fromUtf8("btn_transpose"));

        verticalLayout->addWidget(btn_transpose);

        btn_exit = new QPushButton(widget_2);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));

        verticalLayout->addWidget(btn_exit);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(230, 30, 90, 70));
        widget_3->setMinimumSize(QSize(90, 70));
        widget_3->setMaximumSize(QSize(90, 70));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 3);

        lineEdit_row = new QLineEdit(widget_3);
        lineEdit_row->setObjectName(QString::fromUtf8("lineEdit_row"));
        lineEdit_row->setMaxLength(1);

        gridLayout->addWidget(lineEdit_row, 0, 0, 1, 1);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        lineEdit_col = new QLineEdit(widget_3);
        lineEdit_col->setObjectName(QString::fromUtf8("lineEdit_col"));
        lineEdit_col->setMaxLength(1);

        gridLayout->addWidget(lineEdit_col, 0, 2, 1, 1);

        btn_creat = new QPushButton(centralwidget);
        btn_creat->setObjectName(QString::fromUtf8("btn_creat"));
        btn_creat->setGeometry(QRect(320, 70, 51, 28));
        label_information = new QLabel(centralwidget);
        label_information->setObjectName(QString::fromUtf8("label_information"));
        label_information->setGeometry(QRect(0, 60, 231, 41));
        label_information->setFont(font);
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(160, 160, 61, 20));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(160, 360, 72, 15));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(229, 100, 491, 191));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 290, 491, 2));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "\347\237\251\351\230\265\347\233\270\345\212\240", nullptr));
        btn_minus->setText(QCoreApplication::translate("MainWindow", "\347\237\251\351\230\265\347\233\270\345\207\217", nullptr));
        btn_transpose->setText(QCoreApplication::translate("MainWindow", "\347\237\251\351\230\265\350\275\254\347\275\256", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\241\214 \303\227\345\210\227", nullptr));
        lineEdit_row->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        btn_creat->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220", nullptr));
        label_information->setText(QCoreApplication::translate("MainWindow", "\350\257\267\345\205\210\350\276\223\345\205\245\347\254\254\344\270\200\344\270\252\347\237\251\351\230\265\345\244\247\345\260\217\357\274\232", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "\347\237\251\351\230\2651\357\274\232", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "\347\237\251\351\230\2652\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "--------------------------------------------------------------", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
