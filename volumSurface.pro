TEMPLATE = app
CONFIG += debug
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#DEFINES += MEMTRACE
SOURCES += \
    init/main.c \
    class/grid/grid.c \
    class/implicitForm/implicitForm.c \
    class/surface/surface.c \
    class/surface/surfaceSphere/surfacesphere.c
LIBS += -lm
INCLUDEPATH += ./include
HEADERS += \
    include/surfaceSphere.r \
    include/surfaceSphere.h \
    include/surface.r \
    include/surface.h \
    include/implicitForm.r \
    include/implicitForm.h \
    include/grid.r \
    include/grid.h

unix:!macx: LIBS += -L$$PWD/lib/ -llibooc

INCLUDEPATH += $$PWD/lib/include
DEPENDPATH += $$PWD/lib/include

unix:!macx: PRE_TARGETDEPS += $$PWD/lib/liblibooc.a
