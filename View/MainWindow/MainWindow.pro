
include(../../configuration.pri)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
CONFIG += staticlib
DESTDIR  = $$IDE_APP_PATH
CONFIG(debug, debug|release) {
    TARGET = MainWindowd
} else {
    TARGET = MainWindow
}

HEADERS += \
   MMainWindow.h \
    formAddData.h \
    FormLotteryNumber.h \
    FormLotteryNumber.h \
    FormFiveMinuteRaceStatistic.h \
    FormThreePointsQuikly.h

SOURCES += \
    MMainWindow.cpp \
    formAddData.cpp \
    FormLotteryNumber.cpp \
    FormLotteryNumber.cpp \
    FormFiveMinuteRaceStatistic.cpp \
    FormThreePointsQuikly.cpp

FORMS += \
    MMainWindow.ui \
    formAddData.ui \
    FormLotteryNumber.ui \
    FormLotteryNumber.ui \
    FormFiveMinuteRaceStatistic.ui \
    FormThreePointsQuikly.ui

