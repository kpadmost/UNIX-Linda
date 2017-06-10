TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/shared/Tuple.cpp \
    src/shared/TupleMessage.cpp \
    src/shared/TupleValue.cpp \
    src/client/main.cpp \
    src/client/Client.cpp

HEADERS += \
    src/shared/Tuple.h \
    src/shared/TupleMessage.h \
    src/shared/TupleValue.h \
    src/client/Client.h
