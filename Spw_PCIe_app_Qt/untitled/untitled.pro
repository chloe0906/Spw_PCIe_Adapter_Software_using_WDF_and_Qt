#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T08:20:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    threedialog.cpp \
    pciedialog.cpp \
    helpdialog.cpp \
    hellowindow.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    threedialog.h \
    pciedialog.h \
    helpdialog.h \
    hellowindow.h \
    ui_pciedialog.h \
    datafrompcie.h \
    ui_helpdialog.h

FORMS    += mainwindow.ui \
    threedialog.ui \
    pciedialog.ui \
    helpdialog.ui

RESOURCES += \
    untitled.qrc

DISTFILES +=
RC_FILE += Spw_PCIe.rc
