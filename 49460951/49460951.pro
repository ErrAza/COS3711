#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T11:08:35
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 49460951
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    importer.cpp \
    student.cpp \
    studentlist.cpp \
    xmlparser.cpp \
    studentmodel.cpp

HEADERS  += mainwindow.h \
    importer.h \
    student.h \
    studentlist.h \
    xmlparser.h \
    studentmodel.h

FORMS    += mainwindow.ui
