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
    messageinfo.cpp \
    callinfo.cpp

HEADERS  += opiwatch.h \
    analogclock.h \
    messageinfo.h \
    callinfo.h

FORMS    += \
    messageinfo.ui \
    callinfo.ui
