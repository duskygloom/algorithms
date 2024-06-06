#include "vertex.h"

#include <stdlib.h>

Vertex *create_vertex(int value)
{
	Vertex *vertex = malloc(sizeof(Vertex));
	vertex->value = value;
	vertex->adjacent = create_list();
	return vertex;
}

void delete_vertex(Vertex *vertex)
{
	delete_list(vertex->adjacent, DELETE_NODE);
	vertex->adjacent = NULL;
	free(vertex);
}
