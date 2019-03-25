
TEMPLATE = subdirs

exists($$PWD/DatabaseModule/DatabaseModule.pro):SUBDIRS += DatabaseModule

SUBDIRS +=  \
    CommunicationModule
#    MessageModule
