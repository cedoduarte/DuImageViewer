#-------------------------------------------------
#
# Project created by QtCreator 2015-11-09T20:14:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuImageViewer
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

QMAKE_CXXFLAGS += -std=gnu++14
