
all:
	gcc -fpic -c dir.c
	gcc -shared -Wl,-soname,mylib.so -o mylib.so dir.o

clean:
	rm -rf mylib.so dir.o

install:
	install -m 755 mylib.so /usr/local/lib/lua/5.1

uninstall:
	rm -rf /usr/local/lib/lua/5.1/mylib.so

