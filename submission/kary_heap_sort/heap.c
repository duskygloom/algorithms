#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Heap *create_heap(int k, int *array, int length)
{
    Heap *heap = malloc(sizeof(Heap));
    heap->k = k;
    heap->length = length;
    heap->array = array;
    return heap;
}

void delete_heap(Heap *heap)
{
    free(heap);
}

void print_heap(Heap *heap)
{
    int index = 0;
    for (int i = 1; ; i *= heap->k) {
        for (int j = 0; j < i && index < heap->length; ++j) {
            printf("%d ", heap->array[index++]);
        }
        putchar('\n');
        if (index >= heap->length) break;
    }
}

void replace_with_children(Heap *heap, int parent, heap_type_t heap_type)
{
    // returns if no children
    if (LEFT_MOST_CHILD(parent, heap->k) >= heap->length)
        return;
    // replace with maximum or minimum child
    int child = LEFT_MOST_CHILD(parent, heap->k);
    int replacement = child;
    // find the most suitable replacement
    for (; child <= RIGHT_MOST_CHILD(parent, heap->k) && child < heap->length; ++child)
        if ((heap_type == MIN_HEAP && heap->array[child] < heap->array[replacement]) 
            || (heap_type == MAX_HEAP && heap->array[child] > heap->array[replacement]))
            replacement = child;
    // replace if more suitable than parent
    if ((heap_type == MIN_HEAP && heap->array[replacement] < heap->array[parent])
        || (heap_type == MAX_HEAP && heap->array[replacement] > heap->array[parent])) {
        int temp = heap->array[parent];
        heap->array[parent] = heap->array[replacement];
        heap->array[replacement] = temp;
        // check again for the parent that is now at replacement
        replace_with_children(heap, replacement, heap_type);
    }
}

void heapify(Heap *heap, heap_type_t heap_type)
{
    for (int i = PARENT(heap->length-1, heap->k); i >= 0; --i)
        replace_with_children(heap, i, heap_type);
}
