/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionThree;
    QAction *actionPCIe;
    QAction *actionHelp;
    QAction *actionVersion;
    QWidget *centralWidget;
    QPushButton *pushButton_openDev;
    QTextBrowser *textBrowser;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser_9;
    QWidget *tab_2;
    QTextBrowser *textBrowser_8;
    QWidget *tab_3;
    QTextBrowser *textBrowser_7;
    QWidget *tab_4;
    QTextBrowser *textBrowser_6;
    QWidget *tab_5;
    QTextBrowser *textBrowser_5;
    QWidget *tab_6;
    QTextBrowser *textBrowser_4;
    QWidget *tab_7;
    QTextBrowser *textBrowser_3;
    QWidget *tab_8;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_linkEnable;
    QPushButton *pushButton_linkreset;
    QPushButton *pushButton_foundnet;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_readData;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(810, 451);
        actionThree = new QAction(MainWindow);
        actionThree->setObjectName(QStringLiteral("actionThree"));
        actionPCIe = new QAction(MainWindow);
        actionPCIe->setObjectName(QStringLiteral("actionPCIe"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_openDev = new QPushButton(centralWidget);
        pushButton_openDev->setObjectName(QStringLiteral("pushButton_openDev"));
        pushButton_openDev->setGeometry(QRect(20, 30, 91, 41));
        pushButton_openDev->setCheckable(false);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 140, 191, 251));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 120, 54, 12));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(230, 120, 561, 271));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser_9 = new QTextBrowser(tab);
        textBrowser_9->setObjectName(QStringLiteral("textBrowser_9"));
        textBrowser_9->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textBrowser_8 = new QTextBrowser(tab_2);
        textBrowser_8->setObjectName(QStringLiteral("textBrowser_8"));
        textBrowser_8->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        textBrowser_7 = new QTextBrowser(tab_3);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        textBrowser_6 = new QTextBrowser(tab_4);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        textBrowser_5 = new QTextBrowser(tab_5);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        textBrowser_4 = new QTextBrowser(tab_6);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        textBrowser_3 = new QTextBrowser(tab_7);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        textBrowser_2 = new QTextBrowser(tab_8);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 555, 246));
        tabWidget->addTab(tab_8, QString());
        pushButton_linkEnable = new QPushButton(centralWidget);
        pushButton_linkEnable->setObjectName(QStringLiteral("pushButton_linkEnable"));
        pushButton_linkEnable->setGeometry(QRect(130, 30, 91, 41));
        pushButton_linkEnable->setCheckable(false);
        pushButton_linkreset = new QPushButton(centralWidget);
        pushButton_linkreset->setObjectName(QStringLiteral("pushButton_linkreset"));
        pushButton_linkreset->setGeometry(QRect(240, 30, 91, 41));
        pushButton_linkreset->setCheckable(false);
        pushButton_foundnet = new QPushButton(centralWidget);
        pushButton_foundnet->setObjectName(QStringLiteral("pushButton_foundnet"));
        pushButton_foundnet->setGeometry(QRect(350, 30, 91, 41));
        pushButton_foundnet->setCheckable(false);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(590, 50, 81, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 30, 54, 12));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 90, 31, 20));
        label_3->setText(QStringLiteral(""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(295, 90, 31, 20));
        label_4->setText(QStringLiteral(""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 90, 31, 20));
        label_5->setText(QStringLiteral(""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(405, 90, 31, 20));
        label_6->setText(QStringLiteral(""));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 90, 31, 20));
        label_7->setText(QStringLiteral(""));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(515, 90, 31, 20));
        label_8->setText(QStringLiteral(""));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(570, 90, 31, 20));
        label_9->setText(QStringLiteral(""));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(625, 90, 31, 20));
        label_10->setText(QStringLiteral(""));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/red.png")));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(700, 20, 91, 71));
        QFont font;
        font.setFamily(QStringLiteral("Modern No. 20"));
        font.setPointSize(12);
        font.setItalic(true);
        label_11->setFont(font);
        pushButton_readData = new QPushButton(centralWidget);
        pushButton_readData->setObjectName(QStringLiteral("pushButton_readData"));
        pushButton_readData->setGeometry(QRect(460, 30, 91, 41));
        pushButton_readData->setCheckable(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 810, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionThree);
        menu_2->addAction(actionPCIe);
        menu_3->addSeparator();
        menu_3->addAction(actionHelp);
        menu_3->addAction(actionVersion);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SpaceWire-PCIe\346\216\245\345\217\243\345\215\241\346\216\247\345\210\266\350\275\257\344\273\266", 0));
        actionThree->setText(QApplication::translate("MainWindow", "\344\270\211\350\275\264\345\212\240\351\200\237\345\272\246\350\256\241", 0));
        actionPCIe->setText(QApplication::translate("MainWindow", "PCIe", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\345\270\256\345\212\251", 0));
        actionVersion->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        pushButton_openDev->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\256\276\345\244\207", 0));
        label->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\344\277\241\346\201\257", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\347\253\257\345\217\2431", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\347\253\257\345\217\2432", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\347\253\257\345\217\2433", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\347\253\257\345\217\2434", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "\347\253\257\345\217\2435", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "\347\253\257\345\217\2436", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "\347\253\257\345\217\2437", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "\347\253\257\345\217\2438", 0));
        pushButton_linkEnable->setText(QApplication::translate("MainWindow", "\351\223\276\350\267\257\344\275\277\350\203\275", 0));
        pushButton_linkreset->setText(QApplication::translate("MainWindow", "\351\223\276\350\267\257\345\244\215\344\275\215", 0));
        pushButton_foundnet->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\345\217\221\347\216\260", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "200Mbps", 0)
         << QApplication::translate("MainWindow", "100Mbps", 0)
         << QApplication::translate("MainWindow", "50Mbps", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "\344\274\240\350\276\223\351\200\237\345\272\246", 0));
        label_11->setText(QApplication::translate("MainWindow", "HIT-ATCI", 0));
        pushButton_readData->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\225\260\346\215\256", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
