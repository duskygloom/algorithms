#include <stdio.h>
#include <stdlib.h>

#include "vertex.h"

Vertex *create_vertex(int id, int value)
{
	Vertex *vertex = malloc(sizeof(Vertex));
	vertex->id = id;
	vertex->value = value;
	return vertex;
}

void delete_vertex(Vertex *vertex)
{
	if (!vertex) return;
	free(vertex);
}

void print_vertex(const Vertex *vertex)
{
	if (!vertex) {
		printf("NULL");
		return;
	}
	printf("%d(%d)", vertex->value, vertex->id);
}
