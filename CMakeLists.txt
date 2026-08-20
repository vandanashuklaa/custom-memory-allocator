CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/memory_allocator.c

TARGET = memory_allocator

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

test:
	$(CC) $(CFLAGS) tests/test_allocator.c src/memory_allocator.c -o test_allocator
	./test_allocator

clean:
	rm -f $(TARGET) test_allocator *.exe