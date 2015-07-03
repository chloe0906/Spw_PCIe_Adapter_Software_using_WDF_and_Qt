/********************************************************************************
** Form generated from reading UI file 'mainwindow3d.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW3D_H
#define UI_MAINWINDOW3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow3d
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow3d)
    {
        if (MainWindow3d->objectName().isEmpty())
            MainWindow3d->setObjectName(QStringLiteral("MainWindow3d"));
        MainWindow3d->resize(800, 600);
        menubar = new QMenuBar(MainWindow3d);
        menubar->setObjectName(QStringLiteral("menubar"));
        MainWindow3d->setMenuBar(menubar);
        centralwidget = new QWidget(MainWindow3d);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow3d->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow3d);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow3d->setStatusBar(statusbar);

        retranslateUi(MainWindow3d);

        QMetaObject::connectSlotsByName(MainWindow3d);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow3d)
    {
        MainWindow3d->setWindowTitle(QApplication::translate("MainWindow3d", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow3d: public Ui_MainWindow3d {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW3D_H
