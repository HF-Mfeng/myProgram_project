/********************************************************************************
** Form generated from reading UI file 'changecode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGECODE_H
#define UI_CHANGECODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeCode
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *uplineedit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *midlineedit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *downlineedit;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *sureBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *changeCode)
    {
        if (changeCode->objectName().isEmpty())
            changeCode->setObjectName(QString::fromUtf8("changeCode"));
        changeCode->resize(400, 300);
        changeCode->setMinimumSize(QSize(400, 300));
        changeCode->setMaximumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        changeCode->setFont(font);
        changeCode->setCursor(QCursor(Qt::ArrowCursor));
        changeCode->setMouseTracking(true);
        gridLayout = new QGridLayout(changeCode);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        uplineedit = new QLineEdit(changeCode);
        uplineedit->setObjectName(QString::fromUtf8("uplineedit"));
        uplineedit->setMaxLength(8);
        uplineedit->setFrame(false);
        uplineedit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(uplineedit, 0, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        midlineedit = new QLineEdit(changeCode);
        midlineedit->setObjectName(QString::fromUtf8("midlineedit"));
        midlineedit->setMaxLength(8);
        midlineedit->setFrame(false);
        midlineedit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(midlineedit, 1, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(93, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        downlineedit = new QLineEdit(changeCode);
        downlineedit->setObjectName(QString::fromUtf8("downlineedit"));
        downlineedit->setMaxLength(8);
        downlineedit->setFrame(false);
        downlineedit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(downlineedit, 2, 1, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 3, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(179, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 0, 1, 2);

        sureBtn = new QPushButton(changeCode);
        sureBtn->setObjectName(QString::fromUtf8("sureBtn"));
        sureBtn->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(sureBtn, 3, 2, 1, 2);

        cancelBtn = new QPushButton(changeCode);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 3, 4, 1, 1);


        retranslateUi(changeCode);

        QMetaObject::connectSlotsByName(changeCode);
    } // setupUi

    void retranslateUi(QWidget *changeCode)
    {
        changeCode->setWindowTitle(QCoreApplication::translate("changeCode", "\346\233\264\346\224\271\345\257\206\347\240\201", nullptr));
        uplineedit->setPlaceholderText(QCoreApplication::translate("changeCode", "\350\257\267\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201", nullptr));
        midlineedit->setPlaceholderText(QCoreApplication::translate("changeCode", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        downlineedit->setPlaceholderText(QCoreApplication::translate("changeCode", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        sureBtn->setText(QCoreApplication::translate("changeCode", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QCoreApplication::translate("changeCode", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeCode: public Ui_changeCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGECODE_H
