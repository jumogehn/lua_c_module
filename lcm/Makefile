
all:
	gcc -fpic -c dir.c
	gcc -shared -Wl,-soname,fs.so -o fs.so dir.o

clean:
	rm -rf fs.so dir.o

install:
	install -m 755 fs.so /usr/local/lib/lua/5.1/lcm

uninstall:
	rm -rf /usr/local/lib/lua/5.1/lcm/fs.so

