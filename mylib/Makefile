
all:
	gcc -fpic -c dir.c
	gcc -shared -Wl,-soname,mylib.so -o mylib.so dir.o

clean:
	rm -rf mylib.so dir.o

