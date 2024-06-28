#include "vertex.h"

#include <stdio.h>
#include <stdlib.h>

Vertex *vertex_create(int value)
{
	Vertex *vertex = malloc(sizeof(Vertex));
	vertex->value = value;
	vertex->adjacent = list_create();
	return vertex;
}

void vertex_delete(Vertex *vertex)
{
	list_delete(vertex->adjacent, NULL);
	free(vertex);
}

void vertex_print(const Vertex *vertex)
{
	// printf("%d", vertex->value);
	putchar(vertex->value);
}
