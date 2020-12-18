/********************************************************************************
** Form generated from reading UI file 'administorview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTORVIEW_H
#define UI_ADMINISTORVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_administorview
{
public:
    QLabel *labelusername;
    QLabel *labeluserphone;
    QPushButton *btnpass;

    void setupUi(QWidget *administorview)
    {
        if (administorview->objectName().isEmpty())
            administorview->setObjectName(QString::fromUtf8("administorview"));
        administorview->resize(400, 40);
        administorview->setMinimumSize(QSize(400, 40));
        administorview->setMaximumSize(QSize(400, 40));
        labelusername = new QLabel(administorview);
        labelusername->setObjectName(QString::fromUtf8("labelusername"));
        labelusername->setGeometry(QRect(9, 9, 45, 16));
        labeluserphone = new QLabel(administorview);
        labeluserphone->setObjectName(QString::fromUtf8("labeluserphone"));
        labeluserphone->setGeometry(QRect(160, 10, 141, 16));
        btnpass = new QPushButton(administorview);
        btnpass->setObjectName(QString::fromUtf8("btnpass"));
        btnpass->setGeometry(QRect(340, 10, 50, 22));
        btnpass->setMinimumSize(QSize(50, 22));
        btnpass->setMaximumSize(QSize(50, 22));

        retranslateUi(administorview);

        QMetaObject::connectSlotsByName(administorview);
    } // setupUi

    void retranslateUi(QWidget *administorview)
    {
        administorview->setWindowTitle(QCoreApplication::translate("administorview", "Form", nullptr));
        labelusername->setText(QCoreApplication::translate("administorview", "\347\224\250\346\210\267\345\220\215", nullptr));
        labeluserphone->setText(QCoreApplication::translate("administorview", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        btnpass->setText(QCoreApplication::translate("administorview", "\351\200\232\350\277\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class administorview: public Ui_administorview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTORVIEW_H
