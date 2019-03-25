
include(../../configuration.pri)

QT       += core

TEMPLATE = lib
CONFIG += staticlib
DESTDIR  = $$IDE_APP_PATH

CONFIG(debug, debug|release) {
    TARGET = CommunicationModuled
} else {
    TARGET = CommunicationModule
}

HEADERS += \
    ICommunication.h \
    MainCommunication.h \
    ServerConnect.h

SOURCES += \
    MainCommunication.cpp \
    ServerConnect.cpp


