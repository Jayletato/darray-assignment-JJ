CC = gcc-14
CFLAGS = -Wall -Wextra -Iinclude -std=c2x

TARGET = lib/darray.a

all: build release bin/darray_test 

.PHONY: release
release: CFLAGS += -O3
release: $(TARGET) tests

debug: CFLAGS += -O0 -g
debug: $(TARGET) tests

.PHONY: build
build:
	mkdir -p build
	mkdir -p bin/tests
	mkdir -p lib

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf lib bin build

.PHONY: tests
tests: LDLIBS += -lcheck -lsubunit
tests: test/cpy-tests.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) test/darray-test.c $(TARGET) -o bin/tests/darray-tests

$(TARGET): src/darray.o
	ar rcs $(TARGET) build/darray.o

src/darray.o: src/darray.c include/darray.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -c src/darray.c -o build/darray.o