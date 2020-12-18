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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yigejiemian
{
public:
    QFormLayout *formLayout;
    QDoubleSpinBox *doubleSpinBox;
    QScrollBar *verticalScrollBar;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QDial *dial;
    QDateEdit *dateEdit_2;

    void setupUi(QWidget *yigejiemian)
    {
        if (yigejiemian->objectName().isEmpty())
            yigejiemian->setObjectName(QString::fromUtf8("yigejiemian"));
        yigejiemian->resize(400, 300);
        formLayout = new QFormLayout(yigejiemian);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        doubleSpinBox = new QDoubleSpinBox(yigejiemian);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);

        verticalScrollBar = new QScrollBar(yigejiemian);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        formLayout->setWidget(1, QFormLayout::FieldRole, verticalScrollBar);

        tabWidget = new QTabWidget(yigejiemian);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        formLayout->setWidget(2, QFormLayout::LabelRole, tabWidget);

        lineEdit = new QLineEdit(yigejiemian);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit);

        dateEdit = new QDateEdit(yigejiemian);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, dateEdit);

        dial = new QDial(yigejiemian);
        dial->setObjectName(QString::fromUtf8("dial"));

        formLayout->setWidget(7, QFormLayout::LabelRole, dial);

        dateEdit_2 = new QDateEdit(yigejiemian);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        formLayout->setWidget(8, QFormLayout::FieldRole, dateEdit_2);


        retranslateUi(yigejiemian);

        QMetaObject::connectSlotsByName(yigejiemian);
    } // setupUi

    void retranslateUi(QWidget *yigejiemian)
    {
        yigejiemian->setWindowTitle(QCoreApplication::translate("yigejiemian", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("yigejiemian", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("yigejiemian", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yigejiemian: public Ui_yigejiemian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YIGEJIEMIAN_H
