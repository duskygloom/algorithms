#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Heap *create_heap(int k, int *array, int length)
{
    Heap *heap      = malloc(sizeof(Heap));
    heap->k         = k;
    heap->length    = length;
    heap->array     = calloc(length, sizeof(int));
    memcpy(heap->array, array, length*sizeof(int));
    return heap;
}

void delete_heap(Heap *heap)
{
    free(heap->array);
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

/**
 * @return
 * returns the index of the node it has been replaced with
 * if not replaced, returns -1
 */
void replace_with_children(Heap *heap, int parent, heap_type_t heaptype)
{
    // returns if no children
    if (LEFT_MOST_CHILD(parent, heap->k) >= heap->length)
        return;
    // replace with maximum or minimum child
    int child = LEFT_MOST_CHILD(parent, heap->k);
    int replacement = child;
    // find the most suitable replacement
    for (; child <= RIGHT_MOST_CHILD(parent, heap->k); ++child)
        if ((heaptype == MIN_HEAP && heap->array[child] < heap->array[replacement]) 
            || (heaptype == MAX_HEAP && heap->array[child] > heap->array[replacement]))
            replacement = child;
    // replace if more suitable than parent
    if ((heaptype == MIN_HEAP && heap->array[replacement] < heap->array[parent])
        || (heaptype == MAX_HEAP && heap->array[replacement] > heap->array[parent])) {
        int temp = heap->array[parent];
        heap->array[parent] = heap->array[replacement];
        heap->array[replacement] = temp;
        // check again for the parent that is now at replacement
        replace_with_children(heap, replacement, heaptype);
    }
}

void heapify(Heap *heap, heap_type_t heaptype)
{
    /**
     * @note
     * last intermediate node is the parent node of
     * the last node (length - 1)
     * = (length - 1 - 1) / 2
     * = (length - 2) / 2
     */
    // for (int i = (heap->length-2)/2; i >= 0; --i)
    for (int i = heap->length-1; i >= 0; --i)
        replace_with_children(heap, i, heaptype);
}
