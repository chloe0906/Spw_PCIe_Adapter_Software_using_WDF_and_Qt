/********************************************************************************
** Form generated from reading UI file 'pciedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCIEDIALOG_H
#define UI_PCIEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_PCIeDialog
{
public:
    QLabel *label;
    QTextBrowser *textBrowser_readdata;
    QLineEdit *lineEdit_addoffset;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_writedata;
    QLabel *label_4;
    QPushButton *pushButton_PCIeWriteAddOffset;
    QPushButton *pushButton_PCIeRead;
    QPushButton *pushButton_PCIeWrite;

    void setupUi(QDialog *PCIeDialog)
    {
        if (PCIeDialog->objectName().isEmpty())
            PCIeDialog->setObjectName(QStringLiteral("PCIeDialog"));
        PCIeDialog->resize(400, 227);
        label = new QLabel(PCIeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(153, 10, 71, 20));
        textBrowser_readdata = new QTextBrowser(PCIeDialog);
        textBrowser_readdata->setObjectName(QStringLiteral("textBrowser_readdata"));
        textBrowser_readdata->setGeometry(QRect(220, 70, 131, 71));
        lineEdit_addoffset = new QLineEdit(PCIeDialog);
        lineEdit_addoffset->setObjectName(QStringLiteral("lineEdit_addoffset"));
        lineEdit_addoffset->setGeometry(QRect(30, 70, 113, 20));
        label_2 = new QLabel(PCIeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 54, 12));
        label_3 = new QLabel(PCIeDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 54, 12));
        lineEdit_writedata = new QLineEdit(PCIeDialog);
        lineEdit_writedata->setObjectName(QStringLiteral("lineEdit_writedata"));
        lineEdit_writedata->setGeometry(QRect(30, 120, 113, 20));
        label_4 = new QLabel(PCIeDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 50, 54, 12));
        pushButton_PCIeWriteAddOffset = new QPushButton(PCIeDialog);
        pushButton_PCIeWriteAddOffset->setObjectName(QStringLiteral("pushButton_PCIeWriteAddOffset"));
        pushButton_PCIeWriteAddOffset->setGeometry(QRect(30, 160, 91, 41));
        pushButton_PCIeRead = new QPushButton(PCIeDialog);
        pushButton_PCIeRead->setObjectName(QStringLiteral("pushButton_PCIeRead"));
        pushButton_PCIeRead->setGeometry(QRect(290, 160, 91, 41));
        pushButton_PCIeWrite = new QPushButton(PCIeDialog);
        pushButton_PCIeWrite->setObjectName(QStringLiteral("pushButton_PCIeWrite"));
        pushButton_PCIeWrite->setGeometry(QRect(160, 160, 91, 41));

        retranslateUi(PCIeDialog);

        QMetaObject::connectSlotsByName(PCIeDialog);
    } // setupUi

    void retranslateUi(QDialog *PCIeDialog)
    {
        PCIeDialog->setWindowTitle(QApplication::translate("PCIeDialog", "PCIe\346\216\247\345\210\266\351\235\242\346\235\277", 0));
        label->setText(QApplication::translate("PCIeDialog", "PCIe\346\216\247\345\210\266\351\235\242\346\235\277", 0));
        label_2->setText(QApplication::translate("PCIeDialog", "\345\201\217\347\247\273\345\234\260\345\235\200", 0));
        label_3->setText(QApplication::translate("PCIeDialog", "\345\206\231\345\205\245\346\225\260\346\215\256", 0));
        label_4->setText(QApplication::translate("PCIeDialog", "\346\230\276\347\244\272\344\277\241\346\201\257", 0));
        pushButton_PCIeWriteAddOffset->setText(QApplication::translate("PCIeDialog", "\350\256\276\347\275\256\345\201\217\347\247\273\345\234\260\345\235\200", 0));
        pushButton_PCIeRead->setText(QApplication::translate("PCIeDialog", "\350\257\273\345\217\226\346\225\260\346\215\256", 0));
        pushButton_PCIeWrite->setText(QApplication::translate("PCIeDialog", "\345\206\231\345\205\245\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class PCIeDialog: public Ui_PCIeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCIEDIALOG_H
