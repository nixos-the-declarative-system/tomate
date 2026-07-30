CC      ?= cc
CFLAGS  ?= -O2 -Wall -Wextra
PREFIX  ?= /usr/local

tomate: tomate.c
	$(CC) $(CFLAGS) -o $@ $<

install: tomate
	install -Dm755 tomate $(DESTDIR)$(PREFIX)/bin/tomate

clean:
	rm -f tomate

.PHONY: install clean
