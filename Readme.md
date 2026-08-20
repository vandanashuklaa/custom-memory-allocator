# Custom Memory Allocator

A simple custom memory allocator implemented in C.

This project demonstrates how dynamic memory allocation works internally by implementing basic functionality similar to `malloc()` and `free()`.

## Features

- Custom memory allocation
- Memory deallocation
- Free list management
- Block splitting
- Adjacent free block merging
- Memory usage statistics
- Basic unit tests

## Project Structure

```text
custom-memory-allocator/
├── include/
│   └── memory_allocator.h
├── src/
│   ├── memory_allocator.cpp
│   └── main.cpp
├── tests/
│   └── test_allocator.cpp
├── CMakeLists.txt
├── README.md
└── .gitignore