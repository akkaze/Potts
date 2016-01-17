TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    qstatepotts.cpp \
    paralleltempering.cpp \
    randomgenerator.cpp

HEADERS += \
    qstatepotts.h \
    paralleltempering.h \
    randomgenerator.h

