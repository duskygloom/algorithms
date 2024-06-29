#ifndef HEAP_H
#define HEAP_H

/**
 * @note
 * These macros take an index and corresponding
 * index where its parent or children are.
 */
#define LEFT_CHILD(index)       2*index+1
#define RIGHT_CHILD(index)      2*index+2
#define PARENT_NODE(index)      (index-1)/2

typedef enum {
    MAX_HEAP,
    MIN_HEAP
} heap_type_t;

typedef struct Heap {
    int length;
    int *array;
} Heap;

/**
 * @note
 * same array passed in argument in used in heap
 * so don't delete the array
 */
Heap *create_heap(int *array, int length);

/**
 * @note
 * array will not be deleted so make sure to 
 * store it somewhere before this function
 */
void delete_heap(Heap *heap);

void print_heap(Heap *heap);

void heapify(Heap *heap, heap_type_t heaptype);

#endif // HEAP_H
