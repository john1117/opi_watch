#-------------------------------------------------
#
# Project created by QtCreator 2014-07-13T17:38:06
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opi_watch
TEMPLATE = app


SOURCES += main.cpp\
        opiwatch.cpp \
    analogclock.cpp \
    messageinfo.cpp

HEADERS  += opiwatch.h \
    analogclock.h \
    messageinfo.h

FORMS    += \
    messageinfo.ui
