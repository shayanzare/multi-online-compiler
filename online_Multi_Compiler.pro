#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T21:16:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = online_Multi_Compiler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    highlight.cpp

HEADERS  += mainwindow.h \
    highlight.h

FORMS    += mainwindow.ui

RESOURCES += \
    style.qrc \
    file.qrc
