#!/bin/sh
yacc parse.y -o parse.c
$CC $CFLAGS -I. -o cwm $(pkg-config --libs --cflags freetype2 x11 xft xinerama xrandr) *.c