#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


Heap *create_heap(int *array, int length)
{
    Heap *heap = malloc(sizeof(Heap));
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
    for (int i = 1; ; i*=2) {
        for (int j = 0; j < i && index < heap->length; ++j)
            printf("%d ", heap->array[index++]);
        putchar('\n');
        if (index >= heap->length) break;
    }
}

void replace_with_children(Heap *heap, int parent, heap_type_t heap_type)
{
    // returns if no children
    if (LEFT_CHILD(parent) >= heap->length)
        return;
    int *array = heap->array;
    // find the most suitable replacement
    int left_child = LEFT_CHILD(parent);
    int right_child = RIGHT_CHILD(parent);
    int replacement;
    if (right_child >= heap->length) 
        replacement = left_child;
    else {
        if (heap_type == MIN_HEAP && array[left_child] < array[right_child])
            replacement = left_child;
        else if (heap_type == MIN_HEAP)
            replacement = right_child;
        else if (heap_type == MAX_HEAP && array[left_child] > array[right_child])
            replacement = left_child;
        else
            replacement = right_child;
    }
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
    /**
     * @note
     * last intermediate node is the parent node of
     * the last node (length - 1)
     * = (length - 1 - 1) / 2
     * = (length - 2) / 2
     */
    for (int i = (heap->length-2)/2; i >= 0; --i)
        replace_with_children(heap, i, heap_type);
}
