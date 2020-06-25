patches = $(wildcard patches/*.jac)

all: main

clean:
	rm -r bin.linux
	rm -r bin.dos

main:
	mkdir -p bin.linux
	mkdir -p bin.dos
	cc src/main.c -o bin.linux/jacpatch

run: ./bin.linux/jacpatch
	./bin.linux/jacpatch

# ln -s patches/example.jac hardInput; xxd -i hardInput > src/hardInput.h
