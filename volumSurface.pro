TEMPLATE = app
CONFIG += debug
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += MEMTRACE
SOURCES += main.c \
    surface.c \
    surfacesphere.c \
    implicitForm.c \
    grid.c

LIBS += -lm
unix:!macx: LIBS += -L$$PWD/../../lib-ooc/build-libooc-Desktop-Debug/ -llibooc

INCLUDEPATH += $$PWD/../../lib-ooc/libooc/include
DEPENDPATH += $$PWD/../../lib-ooc/libooc/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../lib-ooc/build-libooc-Desktop-Debug/liblibooc.a

HEADERS += \
    surface.h \
    surface.r \
    surfaceSphere.h \
    surfaceSphere.r \
    implicitForm.h \
    implicitForm.r \
    grid.r \
    grid.h
