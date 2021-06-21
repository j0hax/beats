CC = gcc
CFLAGS = -Wall
PREFIX = /usr/local

beats: clean
	$(CC) beats.c -o beats

install: beats
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mv beats $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/beats

clean:
	rm -fv beats *.o *.a *.so

check:
	./beats
