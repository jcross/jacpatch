patches = $(wildcard patches/*.jac)

all: dos linux

clean:
	rm -r binl
	rm -r bind

linux:
	mkdir -p binl
	gcc src/main.c -W -Wall -s -Os -o binl/jacpatch

dos:
	mkdir -p bind
	ia16-elf-gcc -W -Wall -s -Os -march=any_186 -mtune=v20  -mcmodel=medium src/main.c -o bind/jacpatch.exe -li86

run: linux
	./binl/jacpatch

# ln -s patches/example.jac hardInput; xxd -i hardInput > src/hardInput.h
