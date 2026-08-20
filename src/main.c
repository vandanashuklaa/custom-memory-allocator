#include <stdio.h>

#include "memory_allocator.h"


int main(void)
{
    memory_init();

    printf("=====================================\n");
    printf("     CUSTOM MEMORY ALLOCATOR\n");
    printf("=====================================\n");

    memory_print_statistics();


    printf("\nAllocating memory...\n");


    /* Allocate memory for one integer */
    int *number =
        (int *)memory_allocate(sizeof(int));


    if (number != NULL)
    {
        *number = 42;

        printf(
            "Stored value: %d\n",
            *number
        );
    }


    /* Allocate memory for an array */
    int *array =
        (int *)memory_allocate(sizeof(int) * 10);


    if (array != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            array[i] = i * 10;
        }

        printf(
            "Array allocated successfully\n"
        );

        printf(
            "Array values: "
        );

        for (int i = 0; i < 10; i++)
        {
            printf(
                "%d ",
                array[i]
            );
        }

        printf("\n");
    }


    memory_print_statistics();


    printf("\nFreeing memory...\n");


    memory_free(number);

    memory_free(array);


    memory_print_statistics();


    printf("\n=====================================\n");
    printf("Program completed successfully.\n");
    printf("=====================================\n");


    return 0;
}