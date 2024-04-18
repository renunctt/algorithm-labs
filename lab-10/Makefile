.PHONY: all clean run

all: build

build: main.cpp matrix.cpp matrix.h utilities.cpp utilities.h
	clang++ main.cpp matrix.cpp utilities.cpp -o main.o

clean:
	rm -rf main.o

run: build
	./main.o
