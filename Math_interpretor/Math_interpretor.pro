TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        infixtopostfix.cpp \
        inputoutput.cpp \
        main.cpp \
        postfixtoresult.cpp

HEADERS += \
    ArrayQueue.h \
    ArrayStack.h \
    infixtopostfix.h \
    inputoutput.h \
    postfixtoresult.h
