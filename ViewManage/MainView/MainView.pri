INCLUDEPATH += $$IDE_SOURCE_TREE/ViewManage/MainView
DEPENDPATH += $$IDE_SOURCE_TREE/ViewManage/MainView
LIBS *= -L$$IDE_PLUGINS_DEPEND_PATH
CONFIG(debug, debug|release): LIBS *= -lMainViewd
CONFIG(release, debug|release): LIBS *= -lMainView

message($$LIBS)
