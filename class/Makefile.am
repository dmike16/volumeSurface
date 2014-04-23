## Process this file with Automake
noinst_LIBRARIES = libclass.a
libclass_a_SOURCES = grid/grid.c implicitForm/implicitForm.c surface/surface.c \
surface/surfaceSphere/surfacesphere.c surface/surfaceTorus/surfaceTorus.c
libclass_a_CFLAGS = -W -Wall -pedantic -ansi -std=gnu99
libclass_a_CPPFLAGS = -I ../include -I../lib/include $(AM_CPPFLAGS)
