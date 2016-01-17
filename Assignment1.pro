QT += core network
QT -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = Assignment1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    controller.cpp \
    worker.cpp \
    pthreadworker.cpp \
    processworker.cpp \

HEADERS += \
    controller.h \
    worker.h \
    pthreadworker.h \
    processworker.h \

