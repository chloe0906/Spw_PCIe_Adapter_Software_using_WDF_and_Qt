#include "pciedialog.h"
#include "ui_pciedialog.h"
#include "datafrompcie.h"
#include <QProcess>
#include <QTextStream>

extern QStringList strMain;
PCIeDialog::PCIeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCIeDialog)
{
    ui->setupUi(this);
    initActionsConnections();
    //initAcionsConnections();
}

PCIeDialog::~PCIeDialog()
{
    delete ui;
}
void PCIeDialog::write()
{
    //dataPCIe = ui->lineEdit_writedata->text();
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
    str << ui->lineEdit_writedata->text();
    process->start("D:\\Spw_PCIe\\write.exe",str);
    //执行写数据进程
    process->waitForStarted();
    process->waitForFinished();

    QByteArray qb=process->readAll();
    QString str22(qb);
    QTextStream cout(stdout);
    ui->textBrowser_readdata->append(str22);
    //将写数据进程输出信息打印出来
    //cout<<str22<<endl;
}
void PCIeDialog::writeAddoffset()
{
    //dataPCIe = ui->lineEdit_writedata->text();
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
    str << ui->lineEdit_addoffset->text();
    process->start("D:\\Spw_PCIe\\writeAddOffset.exe",str);
    //执行写偏移地址进程
    process->waitForStarted();
    process->waitForFinished();

    QByteArray qb=process->readAll();
    QString str22(qb);
    QTextStream cout(stdout);
    ui->textBrowser_readdata->append(str22);
    //将写数据进程输出信息打印出来
    //cout<<str22<<endl;
}
void PCIeDialog::read()
{
    QProcess *process=new QProcess();
    QStringList str;
    str.clear();
    str << ui->lineEdit_addoffset->text();
    process->start("D:\\Spw_PCIe\\read.exe",str);
    //执行读偏移地址进程
    process->waitForStarted();
    process->waitForFinished();

    QByteArray qb=process->readAll();
    QString str22(qb);
    QTextStream cout(stdout);
    ui->textBrowser_readdata->append(str22);
}
void PCIeDialog::initActionsConnections()
{
    connect(ui->pushButton_PCIeWrite,SIGNAL(clicked()),this,SLOT(write()));
    connect(ui->pushButton_PCIeRead,SIGNAL(clicked()),this,SLOT(read()));
    connect(ui->pushButton_PCIeWriteAddOffset,SIGNAL(clicked()),this,SLOT(writeAddoffset()));
}
