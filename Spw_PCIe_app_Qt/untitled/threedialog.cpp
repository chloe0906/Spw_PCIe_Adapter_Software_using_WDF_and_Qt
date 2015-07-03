#include "threedialog.h"
#include "ui_threedialog.h"

#include "hellowindow.h"

#include <QtGui\5.4.2\QtGui\qpa/qplatformintegration.h>

#include <QGuiApplication>

ThreeDialog::ThreeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreeDialog)
{

    ui->setupUi(this);



}

ThreeDialog::~ThreeDialog()
{
    delete ui;
}

void ThreeDialog::show3D()
{

    QSurfaceFormat format;
    format.setDepthBufferSize(16);
    QSharedPointer<Renderer> rendererA(new Renderer(format));

    HelloWindow *windowA = new HelloWindow(rendererA);
    windowA->setTitle(QStringLiteral("triaxial accelerometer"));
    windowA->setVisible(true);
   // this->show();
}
