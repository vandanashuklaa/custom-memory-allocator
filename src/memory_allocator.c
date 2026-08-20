#include <stdio.h>
#include "memory_allocator.h"


/* Fixed memory pool */
static char memory_pool[MEMORY_POOL_SIZE];


/* Pointer to first memory block */
static Block *head = NULL;


/* Statistics */
static size_t used_memory = 0;

static size_t allocation_count = 0;


/* Find a suitable free block */
static Block *find_free_block(size_t size)
{
    Block *current = head;

    while (current != NULL)
    {
        if (current->is_free && current->size >= size)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}


/* Split a large block into two blocks */
static void split_block(Block *block, size_t size)
{
    if (block->size <= size + sizeof(Block))
    {
        return;
    }

    Block *new_block;

    new_block = (Block *)
        ((char *)block + sizeof(Block) + size);

    new_block->size =
        block->size - size - sizeof(Block);

    new_block->is_free = 1;

    new_block->next = block->next;

    block->size = size;

    block->next = new_block;
}


/* Merge adjacent free blocks */
static void merge_free_blocks(void)
{
    Block *current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->is_free &&
            current->next->is_free)
        {
            current->size =
                current->size +
                sizeof(Block) +
                current->next->size;

            current->next =
                current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
}


/* Initialize allocator */
void memory_init(void)
{
    head = (Block *)memory_pool;

    head->size =
        MEMORY_POOL_SIZE - sizeof(Block);

    head->is_free = 1;

    head->next = NULL;

    used_memory = 0;

    allocation_count = 0;
}


/* Allocate memory */
void *memory_allocate(size_t size)
{
    if (size == 0)
    {
        return NULL;
    }

    Block *block = find_free_block(size);

    if (block == NULL)
    {
        return NULL;
    }

    split_block(block, size);

    block->is_free = 0;

    used_memory += block->size;

    allocation_count++;

    return (char *)block + sizeof(Block);
}


/* Free memory */
void memory_free(void *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    Block *block =
        (Block *)((char *)ptr - sizeof(Block));

    if (block->is_free)
    {
        return;
    }

    block->is_free = 1;

    used_memory -= block->size;

    allocation_count--;

    merge_free_blocks();
}


/* Print statistics */
void memory_print_statistics(void)
{
    printf("\n----- Memory Statistics -----\n");

    printf("Total Memory: %d bytes\n",
           MEMORY_POOL_SIZE);

    printf("Used Memory: %lu bytes\n",
           (unsigned long)memory_get_used());

    printf("Free Memory: %lu bytes\n",
           (unsigned long)memory_get_free());

    printf("Active Allocations: %lu\n",
           (unsigned long)memory_get_allocation_count());
}


/* Return used memory */
size_t memory_get_used(void)
{
    return used_memory;
}


/* Return free memory */
size_t memory_get_free(void)
{
    return MEMORY_POOL_SIZE - used_memory;
}


/* Return active allocations */
size_t memory_get_allocation_count(void)
{
    return allocation_count;
}