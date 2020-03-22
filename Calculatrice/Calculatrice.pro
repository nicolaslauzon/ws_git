TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        inputoutput.cpp \
        main.cpp \
        opchar.cpp \
        pushstrtoopchar.cpp \
        sampler.cpp \
        token.cpp \
        tokeniser.cpp \
        tokensimplifier.cpp \
        tokenvalidity.cpp \
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
    pushstrtoopchar.h \
    sampler.h \
    token.h \
    tokeniser.h \
    tokensimplifier.h \
    tokenvalidity.h \
    validequation.h
