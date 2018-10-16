QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = TCPClient
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11, sdk_no_version_check

SOURCES += \
        main.cpp \
        client.cpp

HEADERS += \
        client.h

FORMS += \
        client.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
