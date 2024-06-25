CC=clang
OFLAGS=-O2
LDFLAGS=-g -shared -fPIC -grecord-gcc-switches

all: mylib/liba.so mylib/libb.so

mylib/liba.so: mylib/a.c mylib/mylib_a.h
	$(CC) $(OFLAGS) $(LDFLAGS) -o $@ $<

mylib/libb.so: mylib/b.c mylib/mylib_b.h
	$(CC) $(OFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -rf mylib/*.so dgemm

.PHONY: clean