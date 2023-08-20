QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    encryption.cpp \
    formregistration.cpp \
    main.cpp \
    mainwindow.cpp \
    protocolDH.cpp \
    socket.cpp \
    style.cpp

HEADERS += \
    clientservercommandindex.h \
    encryption.h \
    formregistration.h \
    mainwindow.h \
    protocolDH.h \
    socket.h \
    style.h

FORMS += \
    formregistration.ui \
    mainwindow.ui

win32:RC_FILE = icon.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
