CC=gcc
LDFLAGS=-shared -fPIC -lm

all: mylib/liba.so mylib/libb.so

mylib/liba.so: mylib/a.c
	$(CC) $(LDFLAGS) -o $@ $<

mylib/libb.so: mylib/b.c
	$(CC) $(LDFLAGS) -o $@ $<

sqrt: main.c
	#gcc -o $@ $< -I./mylib -L./mylib -la -lb -lm
	#LD_LIBRARY_PATH=./mylib ./sqrt [r]

clean:
	rm -rf mylib/*.so sqrt

.PHONY: clean