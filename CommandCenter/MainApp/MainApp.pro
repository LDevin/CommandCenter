#-------------------------------------------------
#
# Project created by DevinLai 2017-11-06T10:27:42
# @author DevinLai
# @email  laidawang@zds-t.com
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommandApp
TEMPLATE = app

DebugBuild {
    TARGET = $${TARGET}d
    DESTDIR  = $${PWD}/../bin/debug
} else {
    DESTDIR  = $${PWD}/../bin/release
}

win32 {
    win32-msvc2013 | win32-msvc2015 | win32-msvc2017{
        message("Visual Studio version supported!")
    } else {
        error("Visual Studio version must greaterThan 2013!")
    }

    !equals(QT_MAJOR_VERSION, 5) | !greaterThan(QT_MINOR_VERSION, 8) {
       error("Unsupported Qt version, 5.9.x or greater is required")
    } else {
       message(the Qt version is $$[QT_VERSION])
    }
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    hsftestdialog.cpp \
    zktestdialog.cpp \
    xktestdialog.cpp

HEADERS += \
        mainwindow.h \
    hsftestdialog.h \
    zktestdialog.h \
    xktestdialog.h

FORMS += \
        mainwindow.ui \
    hsftestdialog.ui \
    zktestdialog.ui \
    xktestdialog.ui


INCLUDEPATH += $$PWD/../Link/

DebugBuild {
    LIBS += -L$${DESTDIR} -lLinkd
    LIBS += -L$${DESTDIR} -lUid
    LIBS += -L$${DESTDIR} -lDbd
} else {
    LIBS += -L$${DESTDIR} -lLink
    LIBS += -L$${DESTDIR} -lUi
    LIBS += -L$${DESTDIR} -lDb
}

include($$PWD/toolbox/toolbox.pri)
