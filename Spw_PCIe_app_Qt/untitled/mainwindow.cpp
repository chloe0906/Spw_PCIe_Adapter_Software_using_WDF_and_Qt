#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "threedialog.h"
#include "pciedialog.h"
#include "helpdialog.h"
#include <QProcess>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    three = new ThreeDialog;
    pcie = new PCIeDialog;
    help = new HelpDialog;
    initActionsConnections();
}

MainWindow::~MainWindow()
{
    delete three;
    delete pcie;
    delete help;
    delete ui;
}

void MainWindow::version()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                           tr("The <b>Simple Terminal</b> example demonstrates how to "
                              "use the Qt Serial Port module in modern GUI applications "
                              "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::openDev()
{
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
     //   char *str00 = ui->lineEdit->text();
    //str << ui->lineEdit->text() << "b" ;
    process->start("D:\\Spw_PCIe\\openDev.exe",str);
        process->waitForStarted();
        process->waitForFinished();
        QByteArray qb=process->readAll();
        QString str22(qb);
        QTextStream cout(stdout);
        ui->textBrowser->append(str22);
   //     cout<<str22<<endl;
}

void MainWindow::linkEnable()
{
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
     //   char *str00 = ui->lineEdit->text();
    //str << ui->lineEdit->text() << "b" ;
    process->start("D:\\Spw_PCIe\\enableLink.exe",str);
        process->waitForStarted();
        process->waitForFinished();
        QByteArray qb=process->readAll();
        QString str22(qb);
        QTextStream cout(stdout);
        ui->textBrowser->append(str22);
}
void MainWindow::linkReset()
{
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
     //   char *str00 = ui->lineEdit->text();
    //str << ui->lineEdit->text() << "b" ;
    process->start("D:\\Spw_PCIe\\disenableLink.exe",str);
        process->waitForStarted();
        process->waitForFinished();
        QByteArray qb=process->readAll();
        QString str22(qb);
        QTextStream cout(stdout);
        ui->textBrowser->append(str22);
}
void MainWindow::netFound()
{
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
     //   char *str00 = ui->lineEdit->text();
    //str << ui->lineEdit->text() << "b" ;
    process->start("D:\\Spw_PCIe\\netFound1.exe",str);
    process->waitForStarted();
    process->waitForFinished();
        QByteArray qb=process->readAll();
        QString str22(qb);
        QTextStream cout(stdout);
        ui->textBrowser->append(str22);

        QProcess *process1=new QProcess();
      //  QStringList str;
       // str.clear();
         //   char *str00 = ui->lineEdit->text();
        //str << ui->lineEdit->text() << "b" ;
        process1->start("D:\\Spw_PCIe\\netFound2.exe",str);
        process1->waitForStarted();
        process1->waitForFinished();
            QByteArray qb1=process1->readAll();
            QString str222(qb1);
        //    QTextStream cout(stdout);
            ui->textBrowser->append(str222);
}
void MainWindow::readData()
{
    QString str1("未发现网络...");
    ui->textBrowser->append(str1);
}
void MainWindow::initActionsConnections()
{
    connect(ui->actionThree,SIGNAL(triggered()),three,SLOT(show3D()));
    connect(ui->actionPCIe,SIGNAL(triggered()),pcie,SLOT(show()));
    connect(ui->actionHelp,SIGNAL(triggered()),help,SLOT(show()));
    connect(ui->actionVersion,SIGNAL(triggered()),this,SLOT(version()));

    connect(ui->pushButton_openDev,SIGNAL(clicked()),this, SLOT(openDev()));
    connect(ui->pushButton_linkEnable,SIGNAL(clicked()),this, SLOT(linkEnable()));
    connect(ui->pushButton_linkreset,SIGNAL(clicked()),this, SLOT(linkReset()));
    connect(ui->pushButton_foundnet,SIGNAL(clicked()),this, SLOT(netFound()));
}
