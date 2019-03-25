
include(../../configuration.pri)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
CONFIG += staticlib
DESTDIR  = $$IDE_APP_PATH
CONFIG(debug, debug|release) {
    TARGET = MainViewd
} else {
    TARGET = MainView
}

HEADERS += \
    IViewInterface.h \
    MainView.h \
    ViewMediator.h \
    ViewColleague.h

SOURCES += \
    MainView.cpp \
    ViewMediator.cpp \
    ViewColleague.cpp


