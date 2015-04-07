CC ?= cc
CFLAGS ?= -O2
LDFLAGS ?=
YACC ?= yacc

DESTDIR ?= /
PREFIX ?= usr
BIN_DIR ?= $(PREFIX)/bin
MAN_DIR ?= $(PREFIX)/share/man

SRCS = $(wildcard *.c) parse.c
OBJECTS = $(SRCS:.c=.o) parse.o
HEADERS = $(wildcard *.h)

CFLAGS += -std=gnu99 -Wall -pedantic -D_GNU_SOURCE -D__dead="" \
          $(shell pkg-config --cflags xft freetype2 xinerama xrandr x11 \
                  libbsd-overlay)
LDFLAGS += $(shell pkg-config --libs xft freetype2 xinerama xrandr x11 libbsd)

all: cwm

parse.c: parse.y
	$(YACC) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

cwm: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f cwm *.o parse.c

install: all
	install -D -m 755 cwm $(DESTDIR)/$(BIN_DIR)/cwm
	install -D -m 644 cwm.1 $(DESTDIR)/$(MAN_DIR)/man1/cwm.1
	install -D -m 644 cwmrc.5 $(DESTDIR)/$(MAN_DIR)/man5/cwmrc.5
	install -D -m 644 README $(DESTDIR)/$(DOC_DIR)/README
