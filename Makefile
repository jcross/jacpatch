patches = $(wildcard patches/*.jac)

all: main

clean:
	rm -r binl
	rm -r bind

main:
	mkdir -p binl
	mkdir -p bind
	gcc src/main.c -s -Os -o binl/jacpatch
	ia16-elf-gcc  -s -Os -march=any_186 -mtune=v20  -mcmodel=medium src/main.c -o bind/jacpatch

run: ./binl/jacpatch
	./binl/jacpatch

# ln -s patches/example.jac hardInput; xxd -i hardInput > src/hardInput.h
