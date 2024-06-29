#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int *create_array(int length)
{
    return calloc(length, sizeof(int));
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

typedef enum {
    ASCENDING,
    DESCENDING
} sorting_type_t;

/**
 * @note
 * array will be modified in the function
 */
void heap_sort(int *array, int length, int k, sorting_type_t sorting_type)
{
    Heap *heap = create_heap(k, array, length);
    // choosing heap type
    heap_type_t heap_type;
    if (sorting_type == ASCENDING)
        heap_type = MAX_HEAP;
    else
        heap_type = MIN_HEAP;
    // sort
    while (heap->length > 1) {
        heapify(heap, heap_type);
        int temp = heap->array[0];
        heap->array[0] = heap->array[heap->length-1];
        heap->array[heap->length-1] = temp;
        --heap->length;
    }
    delete_heap(heap);
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
    // sort
    heap_sort(array, length, k, ASCENDING);
    printf("\nAscending: ");
    print_array(array, length);
    heap_sort(array, length, k, DESCENDING);
    printf("Descending: ");
    print_array(array, length);
    free(array);
    return 0;
}
