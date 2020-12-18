/********************************************************************************
** Form generated from reading UI file 'mybutton.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYBUTTON_H
#define UI_MYBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mybutton
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *mybutton)
    {
        if (mybutton->objectName().isEmpty())
            mybutton->setObjectName(QString::fromUtf8("mybutton"));
        mybutton->resize(100, 40);
        pushButton = new QPushButton(mybutton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("border:0;"));

        retranslateUi(mybutton);

        QMetaObject::connectSlotsByName(mybutton);
    } // setupUi

    void retranslateUi(QWidget *mybutton)
    {
        mybutton->setWindowTitle(QCoreApplication::translate("mybutton", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("mybutton", "\344\270\215\345\226\234\346\254\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mybutton: public Ui_mybutton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYBUTTON_H
