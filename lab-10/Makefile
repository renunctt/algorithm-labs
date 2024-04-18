.PHONY: all clean run

all: build

build: main.cpp matrix.cpp matrix.h
	clang++ main.cpp matrix.cpp -o main.o

clean:
	rm -rf main.o

run: build
	./main.o
