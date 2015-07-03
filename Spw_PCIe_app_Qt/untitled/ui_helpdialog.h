/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QStringLiteral("HelpDialog"));
        HelpDialog->resize(400, 300);
        label = new QLabel(HelpDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 54, 12));
        label_2 = new QLabel(HelpDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 361, 20));
        label_3 = new QLabel(HelpDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 361, 20));

        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "\344\275\277\347\224\250\345\270\256\345\212\251", 0));
        label->setText(QApplication::translate("HelpDialog", "\344\275\277\347\224\250\345\270\256\345\212\251", 0));
        label_2->setText(QApplication::translate("HelpDialog", "1.\345\205\210\347\202\271\345\207\273\346\211\223\345\274\200\350\256\276\345\244\207\346\214\211\351\222\256\357\274\214\345\246\202\346\236\234\346\211\223\345\274\200\350\256\276\345\244\207\345\244\261\350\264\245\350\257\267\346\237\245\347\234\213\346\216\245\345\217\243\350\256\276\345\244\207\345\217\212\351\251\261\345\212\250", 0));
        label_3->setText(QApplication::translate("HelpDialog", "2.\347\204\266\345\220\216\347\202\271\345\207\273\351\223\276\350\267\257\346\214\211\351\222\256\357\274\214\345\246\202\346\236\234\351\223\276\350\267\257\344\275\277\350\203\275\345\244\261\350\264\245\350\257\267\346\237\245\347\234\213\344\270\216\346\216\245\345\217\243\345\215\241\350\277\236\346\216\245\347\232\204\350\256\276\345\244\207", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
