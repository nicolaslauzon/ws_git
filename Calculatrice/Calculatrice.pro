TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        inputoutput.cpp \
        main.cpp \
        opchar.cpp \
        sampler.cpp \
        validequation.cpp

HEADERS += \
    ArrayQueue.h \
    ArrayStack.h \
    Queue.h \
    SlIterator.h \
    SlNode.h \
    Stack.h \
    inputoutput.h \
    opchar.h \
    sampler.h \
    validequation.h
