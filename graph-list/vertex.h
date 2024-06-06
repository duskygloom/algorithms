#ifndef VERTEX_H
#define VERTEX_H

#include "list.h"

typedef struct {
	int value;
	List *adjacent;
} Vertex;

Vertex *create_vertex(int value);

/**
 * @note
 * Frees the vertex along with its adjacent list and
 * its nodes, but not the corresponding vertices.
 * It also does not remove itself from the adjacent list
 * of other vertices.
 */
void delete_vertex(Vertex *vertex);

#endif // VERTEX_H
