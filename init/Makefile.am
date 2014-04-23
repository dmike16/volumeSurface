## Process this file with Automake
bin_PROGRAMS = volSurface
volSurface_SOURCES = main.c ../include ../lib
volSurface_CFLAGS = -W -Wall -pedantic -ansi -std=gnu99
volSurface_CPPFLAGS = -I../include -I../lib/include $(AM_CPPFLAGS)
volSurface_LDADD = ../class/libclass.a ../lib/libooc.a 
volSurface_DEPENDENCIES = ../lib/libooc.a 