QT       += core gui widgets

TARGET = ymv
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp

HEADERS += \
        src/mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
