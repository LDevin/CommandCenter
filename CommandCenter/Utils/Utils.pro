#-------------------------------------------------
#
# Project created by QtCreator 2017-11-24T10:44:48
#
#-------------------------------------------------

QT          -= gui

TARGET      = Utils
TEMPLATE    = lib

DEFINES     += UTILS_LIBRARY

DebugBuild {
    TARGET  = $${TARGET}d
    DESTDIR = $${PWD}/../bin/debug
} else {
    DESTDIR = $${PWD}/../bin/release
}


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES     += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        utils.cpp

HEADERS += \
        utils.h \
        utils_global.h \ 
    utils_defines.h \
    templates.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include($$PWD/helper/helper.pri)
