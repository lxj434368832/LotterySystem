
include(../configuration.pri)

QT       += core

TEMPLATE = lib
CONFIG += staticlib
DESTDIR  = $$IDE_APP_PATH
CONFIG(debug, debug|release) {
    TARGET = ModelManaged
} else {
    TARGET = ModelManage
}

HEADERS += \
    IModelInterface.h \
    MainModel.h

SOURCES += \
    MainModel.cpp
