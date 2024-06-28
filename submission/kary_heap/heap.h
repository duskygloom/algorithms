#ifndef HEAP_H
#define HEAP_H

/**
 * @note
 * These macros take an index and corresponding
 * index where its parent or children are.
 */
#define LEFT_MOST_CHILD(index, k)       (k * index + 1)
#define RIGHT_MOST_CHILD(index, k)      (k * index + k)

typedef enum {
    MAX_HEAP,
    MIN_HEAP
} heap_t;

typedef struct Heap {
    int k;
    int length;
    int *array;
} Heap;

/**
 * @note
 * copies the content of array to Heap.array
 */
Heap *create_heap(int k, int *array, int length);
void delete_heap(Heap *heap);
void print_heap(Heap *heap);

void heapify(Heap *heap, heap_t heaptype);

#endif // HEAP_H
