#include <assert.h>
#include <stdio.h>

#include "memory_allocator.h"


void test_single_allocation(void)
{
    memory_init();

    int *number =
        (int *)memory_allocate(sizeof(int));

    assert(number != NULL);

    *number = 100;

    assert(*number == 100);

    memory_free(number);

    assert(
        memory_get_allocation_count() == 0
    );

    printf(
        "test_single_allocation PASSED\n"
    );
}


void test_multiple_allocations(void)
{
    memory_init();

    int *first =
        (int *)memory_allocate(sizeof(int));

    int *second =
        (int *)memory_allocate(sizeof(int));


    assert(first != NULL);

    assert(second != NULL);


    assert(
        memory_get_allocation_count() == 2
    );


    memory_free(first);

    memory_free(second);


    assert(
        memory_get_allocation_count() == 0
    );


    printf(
        "test_multiple_allocations PASSED\n"
    );
}


void test_large_allocation(void)
{
    memory_init();

    void *memory =
        memory_allocate(512 * 1024);


    assert(memory != NULL);


    memory_free(memory);


    printf(
        "test_large_allocation PASSED\n"
    );
}


void test_zero_allocation(void)
{
    memory_init();

    void *memory =
        memory_allocate(0);


    assert(memory == NULL);


    printf(
        "test_zero_allocation PASSED\n"
    );
}


void test_memory_reuse(void)
{
    memory_init();


    int *first =
        (int *)memory_allocate(sizeof(int));


    assert(first != NULL);


    memory_free(first);


    int *second =
        (int *)memory_allocate(sizeof(int));


    assert(second != NULL);


    memory_free(second);


    printf(
        "test_memory_reuse PASSED\n"
    );
}


int main(void)
{
    printf(
        "=====================================\n"
    );

    printf(
        "RUNNING MEMORY ALLOCATOR TESTS\n"
    );

    printf(
        "=====================================\n\n"
    );


    test_single_allocation();

    test_multiple_allocations();

    test_large_allocation();

    test_zero_allocation();

    test_memory_reuse();


    printf(
        "\n=====================================\n"
    );

    printf(
        "ALL TESTS PASSED SUCCESSFULLY!\n"
    );

    printf(
        "=====================================\n"
    );


    return 0;
}