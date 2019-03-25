
include(../configuration.pri)

QT       += core

TEMPLATE = lib
CONFIG += staticlib
#TARGET = $$qtLibraryTarget(LogicManage)
DESTDIR  = $$IDE_APP_PATH
CONFIG(debug, debug|release) {
    TARGET = LogicManaged
} else {
    TARGET = LogicManage
}

HEADERS += \
    ILogicInterface.h \
    MainLogic.h

SOURCES += \
    MainLogic.cpp

