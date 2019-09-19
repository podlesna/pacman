#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T20:52:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Triangle_3
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    triangle.cpp \
    pacmanboard.cpp \
    node.cpp

HEADERS  += widget.h \
    triangle.h \
    pacmanboard.h \
    node.h

FORMS    += widget.ui

win32-msvc*{
    LIBS += -luser32
}
