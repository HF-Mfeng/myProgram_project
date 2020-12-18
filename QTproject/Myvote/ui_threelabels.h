/********************************************************************************
** Form generated from reading UI file 'threelabels.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREELABELS_H
#define UI_THREELABELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_threeLabels
{
public:
    QLabel *leftlable;
    QLabel *midlabel;
    QLabel *rightlabel;

    void setupUi(QWidget *threeLabels)
    {
        if (threeLabels->objectName().isEmpty())
            threeLabels->setObjectName(QString::fromUtf8("threeLabels"));
        threeLabels->resize(418, 40);
        threeLabels->setMinimumSize(QSize(418, 40));
        threeLabels->setMaximumSize(QSize(418, 40));
        leftlable = new QLabel(threeLabels);
        leftlable->setObjectName(QString::fromUtf8("leftlable"));
        leftlable->setGeometry(QRect(9, 9, 72, 16));
        midlabel = new QLabel(threeLabels);
        midlabel->setObjectName(QString::fromUtf8("midlabel"));
        midlabel->setGeometry(QRect(170, 10, 72, 16));
        rightlabel = new QLabel(threeLabels);
        rightlabel->setObjectName(QString::fromUtf8("rightlabel"));
        rightlabel->setGeometry(QRect(351, 10, 41, 20));

        retranslateUi(threeLabels);

        QMetaObject::connectSlotsByName(threeLabels);
    } // setupUi

    void retranslateUi(QWidget *threeLabels)
    {
        threeLabels->setWindowTitle(QCoreApplication::translate("threeLabels", "Form", nullptr));
        leftlable->setText(QCoreApplication::translate("threeLabels", "TextLabel", nullptr));
        midlabel->setText(QCoreApplication::translate("threeLabels", "TextLabel", nullptr));
        rightlabel->setText(QCoreApplication::translate("threeLabels", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class threeLabels: public Ui_threeLabels {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREELABELS_H
