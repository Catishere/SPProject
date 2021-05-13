TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = $$PWD/../build/server

SOURCES += main.cpp \
    loginmanager.cpp \
    user.cpp \
    socketmanager.cpp \
    ipentry.cpp \
    controller.cpp

HEADERS += \
    loginmanager.h \
    user.h \
    socketmanager.h \
    ipentry.h \
    controller.h

LIBS += -L$$PWD/../shmemlib/ -lshmemlib
LIBS += -lpthread

DEPENDPATH += $$PWD/../shmemlib
INCLUDEPATH += $$PWD/../shmemlib
DEPENDPATH += $$PWD/../shmemlib

PRE_TARGETDEPS += $$PWD/../shmemlib/libshmemlib.a
