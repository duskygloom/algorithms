#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int *create_array(int length)
{
    int *array = calloc(length, sizeof(int));
    return array;
}

void fill_array(int *array, int length)
{
    printf("%d elements: ", length);
    for (int i = 0; i < length; ++i)
        scanf("%d", &array[i]);
}

void print_array(int *array, int length)
{
    if (length <= 0) {
        printf("[]\n");
        return;
    }
    printf("[%d", array[0]);
    for (int i = 1; i < length; ++i)
        printf(", %d", array[i]);
    printf("]\n");
}

int main()
{
    int k;
    printf("K: ");
    scanf("%d", &k);
    putchar('\n');
    int length;
    printf("Length of array: ");
    scanf("%d", &length);
    // create array
    int *array = create_array(length);
    fill_array(array, length);
    // create heap
    Heap *heap = create_heap(k, array, length);
    printf("\nBEFORE HEAPIFY\n");
    print_heap(heap);
    // min heap
    heapify(heap, MIN_HEAP);
    printf("\nMIN HEAP\n");
    print_heap(heap);
    // max heap
    heapify(heap, MAX_HEAP);
    printf("\nMAX HEAP\n");
    print_heap(heap);
    // delete heap
    delete_heap(heap);
    return 0;
}
