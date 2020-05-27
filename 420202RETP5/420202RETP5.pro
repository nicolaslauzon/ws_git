TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L. -l420202RETP5 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2

SOURCES += \
        HuffmanEncoding.cpp \
        directory.cpp \
        folder.cpp \
        initandclose.cpp \
        main.cpp \
        note.cpp

HEADERS += \
    BSTNode.h \
    BSTree.h \
    HuffmanEncoding.h \
    HuffmanNode.h \
    PQIterator.h \
    PriorityNode.h \
    PriorityQueue.h \
    SlNode.h \
    Sort.h \
    Stack.h \
    Window.hpp \
    directory.h \
    folder.h \
    initandclose.h \
    note.h
