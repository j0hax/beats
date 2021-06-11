CC = gcc
CFLAGS = -Wall

beats: libbeat
	$(CC) -I lib beats.c libbeat.a -o beats

libbeat:
	$(CC) -c lib/libbeat.c
	ar rcs libbeat.a libbeat.o

clean:
	rm -fv beats *.o *.a

check:
	./beats
