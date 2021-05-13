TEMPLATE = subdirs
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SUBDIRS = shmemlib \
          server   \
          client

DESTDIR = $$PWD/build

client.depends = shmemlib
server.depends = shmemlib

