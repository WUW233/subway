QT       += core gui
QT += location

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    lian.cpp \
    line.cpp \
    main.cpp \
    stand.cpp \
    subwaycontainer.cpp \
    subwaywindow.cpp

HEADERS += \
    form.h \
    lian.h \
    line.h \
    stand.h \
    subwaycontainer.h \
    subwaywindow.h

FORMS += \
    form.ui \
    subwaywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
