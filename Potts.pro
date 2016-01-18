TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    qstatepotts.cpp \
    paralleltempering.cpp \
    randomgenerator.cpp \
    observable.cpp \
    mcrun.cpp \
    options.cpp \
    mcrun_prepare.cpp

HEADERS += \
    qstatepotts.h \
    paralleltempering.h \
    randomgenerator.h \
    observable.h \
    msgtags.h \
    mcresults.h \
    mcrun.h \
    options.h \
    observables_all.h \
    mcrun_prepare.h

