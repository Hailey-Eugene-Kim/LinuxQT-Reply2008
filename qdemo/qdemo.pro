#-------------------------------------------------
#
# Project created by QtCreator 2022-04-05T17:25:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qdemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    musicdialog.cpp \
    cameradialog.cpp \
    musicthread.cpp \
    songdialog.cpp

HEADERS  += mainwindow.h \
    musicdialog.h \
    cameradialog.h \
    musicthread.h \
    songdialog.h

FORMS    += mainwindow.ui \
    musicdialog.ui \
    cameradialog.ui \
    songdialog.ui

RESOURCES += \
    MyResources.qrc
