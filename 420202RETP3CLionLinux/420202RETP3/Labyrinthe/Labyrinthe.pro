TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS+=-L/usr/local/lib -L$$PWD/../ -l420202RETP3  -lSDL2 -lSDL2main

SOURCES += \
        main.cpp
