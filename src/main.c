#include <stdio.h>
#include <stdlib.h>
#include "memory_allocator.h"

#define MAX_ALLOCATIONS 100

int main(void)
{
    void *allocations[MAX_ALLOCATIONS] = {NULL};
    int allocation_count = 0;

    int choice;

    memory_init();

    printf("\n=====================================\n");
    printf("     CUSTOM MEMORY ALLOCATOR\n");
    printf("=====================================\n");

    while (1)
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Show memory statistics\n");
        printf("4. Exit\n");
        printf("----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Allocate memory */
        if (choice == 1)
        {
            if (allocation_count >= MAX_ALLOCATIONS)
            {
                printf("Maximum allocation limit reached.\n");
                continue;
            }

            

            printf("How many integers do you want to store? ");
            unsigned long input_count;
            scanf("%lu", &input_count);
            size_t count = (size_t)input_count;

            if (count == 0)
            {
                printf("Number of integers must be greater than 0.\n");
                continue;
            }

            size_t size = count * sizeof(int);

            int *ptr = (int *)memory_allocate(size);

            if (ptr == NULL)
            {
                printf("Memory allocation failed!\n");
                continue;
            }

            printf("Enter %lu integers:\n", (unsigned long)count);

            for (size_t i = 0; i < count; i++)
            {
                scanf("%d", &ptr[i]);
            }

            allocations[allocation_count] = ptr;

            printf("\nMemory allocated successfully!\n");
            printf("Allocation ID: %d\n", allocation_count + 1);

            printf("Stored values: ");

            for (size_t i = 0; i < count; i++)
            {
                printf("%d ", ptr[i]);
            }

            printf("\n");

            allocation_count++;
        }

        /* Free memory */
        else if (choice == 2)
        {
            if (allocation_count == 0)
            {
                printf("There is no allocated memory to free.\n");
                continue;
            }

            printf("\nActive allocations:\n");

            for (int i = 0; i < allocation_count; i++)
            {
                if (allocations[i] != NULL)
                {
                    printf("Allocation ID: %d\n", i + 1);
                }
            }

            int id;

            printf("Enter allocation ID to free: ");
            scanf("%d", &id);

            if (id < 1 || id > allocation_count)
            {
                printf("Invalid allocation ID.\n");
                continue;
            }

            if (allocations[id - 1] == NULL)
            {
                printf("This memory has already been freed.\n");
                continue;
            }

            memory_free(allocations[id - 1]);

            allocations[id - 1] = NULL;

            printf("Allocation %d freed successfully!\n", id);
        }

        /* Statistics */
        else if (choice == 3)
        {
            memory_print_statistics();
        }

        /* Exit */
        else if (choice == 4)
        {
            printf("\nFreeing remaining allocated memory...\n");

            for (int i = 0; i < allocation_count; i++)
            {
                if (allocations[i] != NULL)
                {
                    memory_free(allocations[i]);
                    allocations[i] = NULL;
                }
            }

            printf("All memory released.\n");

            memory_print_statistics();

            printf("\n=====================================\n");
            printf("       PROGRAM TERMINATED\n");
            printf("=====================================\n");

            break;
        }

        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}