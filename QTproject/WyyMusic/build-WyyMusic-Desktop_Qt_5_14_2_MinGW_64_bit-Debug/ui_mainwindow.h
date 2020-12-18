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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include <myslider.h>
#include <myvolum.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnPlay;
    QPushButton *btnNextSong;
    QPushButton *btnLastSong;
    QPushButton *btnAddMusicList;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btnList;
    MySlider *aMySlider;
    QPushButton *btnPlayWay;
    QLabel *songNamelabel;
    MyVolum *widget;
    QPushButton *btnAddFromPC;
    QPushButton *btnFromData;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 600);
        MainWindow->setMinimumSize(QSize(500, 600));
        MainWindow->setMaximumSize(QSize(500, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 198, 228);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnPlay = new QPushButton(centralwidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setGeometry(QRect(400, 370, 93, 28));
        btnPlay->setCursor(QCursor(Qt::PointingHandCursor));
        btnPlay->setStyleSheet(QString::fromUtf8("border:0"));
        btnNextSong = new QPushButton(centralwidget);
        btnNextSong->setObjectName(QString::fromUtf8("btnNextSong"));
        btnNextSong->setGeometry(QRect(390, 560, 93, 28));
        btnNextSong->setCursor(QCursor(Qt::PointingHandCursor));
        btnNextSong->setStyleSheet(QString::fromUtf8("border:0"));
        btnLastSong = new QPushButton(centralwidget);
        btnLastSong->setObjectName(QString::fromUtf8("btnLastSong"));
        btnLastSong->setGeometry(QRect(400, 520, 93, 28));
        btnLastSong->setCursor(QCursor(Qt::PointingHandCursor));
        btnLastSong->setStyleSheet(QString::fromUtf8("border:0"));
        btnAddMusicList = new QPushButton(centralwidget);
        btnAddMusicList->setObjectName(QString::fromUtf8("btnAddMusicList"));
        btnAddMusicList->setGeometry(QRect(390, 330, 93, 28));
        btnAddMusicList->setCursor(QCursor(Qt::PointingHandCursor));
        btnAddMusicList->setStyleSheet(QString::fromUtf8("border:0"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 250, 280, 350));
        scrollArea->setMinimumSize(QSize(280, 350));
        scrollArea->setMaximumSize(QSize(280, 350));
        scrollArea->setStyleSheet(QString::fromUtf8("border:0;"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setEnabled(true);
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 280, 350));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(35);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 198, 228);"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        btnList = new QPushButton(centralwidget);
        btnList->setObjectName(QString::fromUtf8("btnList"));
        btnList->setGeometry(QRect(390, 280, 93, 28));
        btnList->setStyleSheet(QString::fromUtf8("border:0"));
        aMySlider = new MySlider(centralwidget);
        aMySlider->setObjectName(QString::fromUtf8("aMySlider"));
        aMySlider->setGeometry(QRect(0, 90, 501, 31));
        btnPlayWay = new QPushButton(centralwidget);
        btnPlayWay->setObjectName(QString::fromUtf8("btnPlayWay"));
        btnPlayWay->setGeometry(QRect(390, 240, 93, 28));
        btnPlayWay->setStyleSheet(QString::fromUtf8("border:0;"));
        songNamelabel = new QLabel(centralwidget);
        songNamelabel->setObjectName(QString::fromUtf8("songNamelabel"));
        songNamelabel->setGeometry(QRect(0, 65, 501, 21));
        widget = new MyVolum(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 220, 42, 31));
        btnAddFromPC = new QPushButton(centralwidget);
        btnAddFromPC->setObjectName(QString::fromUtf8("btnAddFromPC"));
        btnAddFromPC->setGeometry(QRect(362, 410, 121, 28));
        btnAddFromPC->setStyleSheet(QString::fromUtf8("border:0;"));
        btnFromData = new QPushButton(centralwidget);
        btnFromData->setObjectName(QString::fromUtf8("btnFromData"));
        btnFromData->setGeometry(QRect(362, 450, 111, 28));
        btnFromData->setStyleSheet(QString::fromUtf8("border:0;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnPlay->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        btnNextSong->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
        btnLastSong->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
        btnAddMusicList->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\255\214\346\233\262", nullptr));
        btnList->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        btnPlayWay->setText(QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257\346\222\255\346\224\276", nullptr));
        songNamelabel->setText(QString());
        btnAddFromPC->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\234\254\345\234\260\345\257\274\345\205\245\346\255\214\346\233\262", nullptr));
        btnFromData->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
