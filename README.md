
# Custom Memory Allocator in C

A simple custom memory allocator implemented in C.

This project demonstrates how dynamic memory allocation works internally by implementing a basic allocator similar to `malloc()` and `free()`.

## Features

- Custom memory allocation
- Memory deallocation
- Fixed-size memory pool
- First-fit allocation strategy
- Memory block splitting
- Adjacent free block merging
- Memory usage statistics
- Basic test cases

## Project Structure

```text
custom-memory-allocator/
│
├── README.md
├── Makefile
├── .gitignore
│
├── include/
│   └── memory_allocator.h
│
├── src/
│   ├── memory_allocator.c
│   └── main.c
│
└── tests/
    └── test_allocator.c
