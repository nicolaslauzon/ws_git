TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        HuffmanEncoding.cpp \
        main.cpp

HEADERS += \
    HuffmanEncoding.h \
    HuffmanNode.h \
    PQIterator.h \
    PriorityNode.h \
    PriorityQueue.h
