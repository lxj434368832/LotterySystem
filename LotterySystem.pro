
TEMPLATE = subdirs
CONFIG   += ordered

exists($$PWD/Utility/Utility.pro):SUBDIRS += Utility

SUBDIRS +=  CommonFile \
    ViewManage \
    ModelManage \
    LogicManage \
    MainClient \
    Component
