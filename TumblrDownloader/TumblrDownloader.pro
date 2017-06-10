#-------------------------------------------------
#
# Project created by QtCreator 2017-06-10T13:53:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TumblrDownloader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pythonthread.cpp

HEADERS  += mainwindow.h \
    pythonthread.h

FORMS    += mainwindow.ui
