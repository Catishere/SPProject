#-------------------------------------------------
#
# Project created by QtCreator 2021-05-12T19:24:39
#
#-------------------------------------------------

QT       -= core gui
QMAKE_CXXFLAGS += -std=c++11

TARGET = shmemlib
TEMPLATE = lib
CONFIG += staticlib c++11

DESTDIR = $$PWD

LIBS += -lpthread

SOURCES += sharedmemory.cpp \
    mutex.cpp

HEADERS += sharedmemory.h \
    data.h \
    mutex.h \
    mutexexception.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
