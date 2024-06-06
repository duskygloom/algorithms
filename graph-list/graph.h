#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "vertex.h"

typedef struct {
	List *vertices;
} Graph;

Graph *create_graph();

/**
 * @note
 * Frees memory allocated by the graph.
 * Including all of its vertices and nodes.
 */
void delete_graph(Graph *graph);

Vertex *add_vertex(Graph *graph, int value);

#endif // GRAPH_H
