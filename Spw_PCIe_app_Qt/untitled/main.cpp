#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
 //   QstringList strMain;

    QApplication a(argc, argv);

    a.setWindowIcon(QIcon("Spw_PCIe.ico"));
    MainWindow w;

    //strMain.clear();

    w.show();

    return a.exec();
}
