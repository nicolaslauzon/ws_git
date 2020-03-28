TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        inputoutput.cpp \
        main.cpp \
        solver.cpp \
        token.cpp \
        tokeniser.cpp \
        tokensimplifier.cpp \
        tokenvalidity.cpp \

HEADERS += \
    Queue.h \
    SlIterator.h \
    SlNode.h \
    Stack.h \
    inputoutput.h \
    solver.h \
    token.h \
    tokeniser.h \
    tokensimplifier.h \
    tokenvalidity.h
