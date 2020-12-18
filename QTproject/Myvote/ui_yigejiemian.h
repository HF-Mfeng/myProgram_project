/********************************************************************************
** Form generated from reading UI file 'yigejiemian.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YIGEJIEMIAN_H
#define UI_YIGEJIEMIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yigejiemian
{
public:
    QFormLayout *formLayout;

    void setupUi(QWidget *yigejiemian)
    {
        if (yigejiemian->objectName().isEmpty())
            yigejiemian->setObjectName(QString::fromUtf8("yigejiemian"));
        yigejiemian->resize(400, 335);
        formLayout = new QFormLayout(yigejiemian);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        retranslateUi(yigejiemian);

        QMetaObject::connectSlotsByName(yigejiemian);
    } // setupUi

    void retranslateUi(QWidget *yigejiemian)
    {
        yigejiemian->setWindowTitle(QCoreApplication::translate("yigejiemian", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yigejiemian: public Ui_yigejiemian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YIGEJIEMIAN_H
