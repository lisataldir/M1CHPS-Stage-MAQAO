CC=gcc
OFLAGS=-O3 
CFLAGS=-g

all: bin/splat

bin/splat: bin/main.o bin/splat.o
	$(CC) $(CFLAGS) -o $@ $^

bin/main.o: src/main.c include/splat.h
	$(CC) $(OFLAGS) $(CFLAGS) -c -o $@ $<

bin/splat.o: src/splat.c include/splat.h
	$(CC) $(OFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf bin/*.o bin/splat

.PHONY: clean
