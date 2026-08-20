#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include <stddef.h>

#define MEMORY_POOL_SIZE (1024 * 1024)

typedef struct Block
{
    size_t size;
    int is_free;
    struct Block *next;

} Block;


/* Initialize memory allocator */
void memory_init(void);


/* Allocate memory */
void *memory_allocate(size_t size);


/* Free allocated memory */
void memory_free(void *ptr);


/* Print memory statistics */
void memory_print_statistics(void);


/* Get used memory */
size_t memory_get_used(void);


/* Get free memory */
size_t memory_get_free(void);


/* Get active allocations */
size_t memory_get_allocation_count(void);

#endif