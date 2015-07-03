/********************************************************************************
** Form generated from reading UI file 'threedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREEDIALOG_H
#define UI_THREEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ThreeDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *ThreeDialog)
    {
        if (ThreeDialog->objectName().isEmpty())
            ThreeDialog->setObjectName(QStringLiteral("ThreeDialog"));
        ThreeDialog->resize(400, 300);
        label = new QLabel(ThreeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 12, 91, 20));

        retranslateUi(ThreeDialog);

        QMetaObject::connectSlotsByName(ThreeDialog);
    } // setupUi

    void retranslateUi(QDialog *ThreeDialog)
    {
        ThreeDialog->setWindowTitle(QApplication::translate("ThreeDialog", "Dialog", 0));
        label->setText(QApplication::translate("ThreeDialog", "\344\270\211\350\275\264\345\212\240\351\200\237\345\272\246\350\256\241", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreeDialog: public Ui_ThreeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEDIALOG_H
