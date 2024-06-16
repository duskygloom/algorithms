#ifndef VERTEX_H
#define VERTEX_H

#include "list.h"

typedef enum { WHITE, GRAY, BLACK } Color;

typedef struct {
	int value;
	Color color;
	List *adjacent;
} Vertex;

Vertex *vertex_create(int value);

void vertex_delete(Vertex *vertex);

static inline void void_vertex_delete(void *vertex)
{
	vertex_delete((Vertex *)vertex);
}

void vertex_print(const Vertex *vertex);

static inline void void_vertex_print(const void *vertex)
{
	vertex_print((Vertex *)vertex);
}

#endif // VERTEX_H
