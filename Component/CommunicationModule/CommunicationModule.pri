INCLUDEPATH += $$IDE_SOURCE_TREE/Component/CommunicationModule
DEPENDPATH += $$IDE_SOURCE_TREE/Component/CommunicationModule
LIBS *= -L$$IDE_PLUGINS_DEPEND_PATH

CONFIG(debug, debug|release): LIBS *= -lCommunicationModuled
CONFIG(release, debug|release): LIBS *= -lCommunicationModule

message($$LIBS)
