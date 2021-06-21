CC = gcc
CFLAGS = -Wall

beats: clean
	$(CC) beats.c -o beats

clean:
	rm -fv beats *.o *.a *.so

check:
	./beats
