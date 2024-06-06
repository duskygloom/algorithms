#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

#include <stdbool.h>

/**
 * @note
 * Graph contains a list of vertices.
 * A vertex is a struct containing an
 * integer value.
 * 
 * Graph also contains a list of edges.
 * An edge is a struct containing two
 * Vertex pointers `from` and `to`.
 */

typedef struct {
	int value;
} Vertex;

Vertex *create_vertex(int value);

typedef struct {
	Vertex *from;
	Vertex *to;
} Edge;

Edge *create_edge(Vertex *from, Vertex *to);

typedef struct {
	List *vertices;
	List *edges;
} Graph;

Graph *create_graph();
void delete_graph(Graph *graph);
void print_graph(const Graph *graph);

int get_graph_size(const Graph *graph);

Vertex *add_vertex(Graph *graph, int value);
Edge *add_edge(Graph *graph, Vertex *from, Vertex *to);

bool remove_vertex(Graph *graph, Vertex *vertex);
bool remove_edge(Graph *graph, Edge *edge);

#endif // GRAPH_H
