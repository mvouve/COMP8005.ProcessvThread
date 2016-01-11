QT += core network
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = Assignment1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    utility.cpp \
    controller.cpp \
    worker.cpp \
    blockingqueue.cpp \
    threadsafequeue.cpp

HEADERS += \
    utility.h \
    controller.h \
    worker.h \
    blockingqueue.h \
    threadsafequeue.h

