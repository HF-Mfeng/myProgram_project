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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include <myslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnPlay;
    QPushButton *btnAddVolum;
    QPushButton *btnNextSong;
    QPushButton *btnReleaseVolum;
    QPushButton *btnLastSong;
    QPushButton *btnAddMusicList;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btnList;
    MySlider *aMySlider;

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
        btnAddVolum = new QPushButton(centralwidget);
        btnAddVolum->setObjectName(QString::fromUtf8("btnAddVolum"));
        btnAddVolum->setGeometry(QRect(400, 410, 93, 28));
        btnAddVolum->setCursor(QCursor(Qt::PointingHandCursor));
        btnAddVolum->setStyleSheet(QString::fromUtf8("border:0"));
        btnNextSong = new QPushButton(centralwidget);
        btnNextSong->setObjectName(QString::fromUtf8("btnNextSong"));
        btnNextSong->setGeometry(QRect(390, 560, 93, 28));
        btnNextSong->setCursor(QCursor(Qt::PointingHandCursor));
        btnNextSong->setStyleSheet(QString::fromUtf8("border:0"));
        btnReleaseVolum = new QPushButton(centralwidget);
        btnReleaseVolum->setObjectName(QString::fromUtf8("btnReleaseVolum"));
        btnReleaseVolum->setGeometry(QRect(400, 460, 93, 28));
        btnReleaseVolum->setCursor(QCursor(Qt::PointingHandCursor));
        btnReleaseVolum->setStyleSheet(QString::fromUtf8("border:0"));
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
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnPlay->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
        btnAddVolum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnNextSong->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
        btnReleaseVolum->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnLastSong->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
        btnAddMusicList->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\255\214\346\233\262", nullptr));
        btnList->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
