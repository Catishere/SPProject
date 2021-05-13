TEMPLATE = app
CONFIG += console c++11 pthread
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = $$PWD/../build/client

SOURCES += main.cpp \
    mockip.cpp

LIBS += -L$$PWD/../shmemlib/ -lshmemlib
LIBS += -lpthread

INCLUDEPATH += $$PWD/../shmemlib
DEPENDPATH += $$PWD/../shmemlib

PRE_TARGETDEPS += $$PWD/../shmemlib/libshmemlib.a

HEADERS += \
    mockip.h
