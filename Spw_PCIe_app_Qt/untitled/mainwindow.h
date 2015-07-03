#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class ThreeDialog;
class PCIeDialog;
class HelpDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  //  void openThreeDialog();
    void version();
    void openDev();
    void linkEnable();
    void linkReset();
    void netFound();
    void readData();
private:
    void initActionsConnections();


    Ui::MainWindow *ui;
    ThreeDialog *three;
    PCIeDialog *pcie;
    HelpDialog *help;
};

#endif // MAINWINDOW_H
