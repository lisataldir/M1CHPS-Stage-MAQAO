CC=gcc
LDFLAGS=-shared -fPIC -lm

all: mylib/liba.so mylib/libb.so

mylib/liba.so: mylib/a.c
	$(CC) $(LDFLAGS) -o $@ $<

mylib/libb.so: mylib/b.c
	$(CC) $(LDFLAGS) -o $@ $<

clean:
	rm -rf mylib/*.so sqrt

.PHONY: clean