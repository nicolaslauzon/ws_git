#TEMPLATE = app
CONFIG += console c++17
#CONFIG -= app_bundle
#CONFIG -= qt
INCLUDEPATH+=/usr/include
DEFINES += QT_DEPRECATED_WARNINGS
QT       += core gui

LIBS +=  -L./ -llib420202RETP5 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2

SOURCES += \
        binarytree.cpp \
        main.cpp

HEADERS += \
    BSTNode.h \
    Sort.h \
    Window.hpp \
    binarytree.h
