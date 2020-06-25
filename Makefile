patches = $(wildcard patches/*.jacpatch)

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
