QT       += core gui
RC_ICONS = logo.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administorview.cpp \
    administrator.cpp \
    administratorlogin.cpp \
    changecode.cpp \
    createactivity.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationwindows.cpp \
    threelabels.cpp \
    user.cpp \
    userview.cpp \
    yigejiemian.cpp

HEADERS += \
    administorview.h \
    administrator.h \
    administratorlogin.h \
    changecode.h \
    createactivity.h \
    mainwindow.h \
    registrationwindows.h \
    threelabels.h \
    user.h \
    userview.h \
    yigejiemian.h

FORMS += \
    administorview.ui \
    administrator.ui \
    administratorlogin.ui \
    changecode.ui \
    createactivity.ui \
    mainwindow.ui \
    registrationwindows.ui \
    threelabels.ui \
    user.ui \
    userview.ui \
    yigejiemian.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc