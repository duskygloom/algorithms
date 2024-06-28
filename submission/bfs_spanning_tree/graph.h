#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "vertex.h"

typedef struct {
	List *vertices;
} Graph;

Graph *graph_create();

void graph_delete(Graph *graph);

void graph_print(const Graph *graph);

/**
 * @note
 * It only prints tree, i.e. the graph must be acyclic.
 */
void tree_print(const Graph *graph, const Vertex *head);

void graph_add_vertex(Graph *graph, Vertex *vertex);

void graph_remove_vertex(Graph *graph, Vertex *vertex);

bool graph_contains(const Graph *graph, const Vertex *vertex);

void graph_add_edge(Graph *graph, Vertex *from, Vertex *to);

void graph_remove_edge(Vertex *from, Vertex *to);

#endif // GRAPH_H
