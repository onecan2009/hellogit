#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T10:02:43
#
#-------------------------------------------------

QT       += core gui
QT       += sql     #from Mr. Wei

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyTest
TEMPLATE = app
INCLUDEPATH += "C:\Program Files\MySQL\MySQL Server 5.6\include"        #from Mr. Wei
LIBS    += "C:\Program Files\MySQL\MySQL Server 5.6\lib\libmysql.lib"   #from Mr. Wei


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui
