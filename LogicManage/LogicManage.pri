INCLUDEPATH += $$IDE_SOURCE_TREE/LogicManage
DEPENDPATH += $$IDE_SOURCE_TREE/LogicManage
LIBS *= -L$$IDE_PLUGINS_DEPEND_PATH
CONFIG(debug, debug|release): LIBS *= -lLogicManaged
CONFIG(release, debug|release): LIBS *= -lLogicManage

message($$LIBS)
