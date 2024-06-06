#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#include "vertex.h"
#include "adjmatrix.h"
#include "vertex_list.h"

typedef struct Graph {
	VertexList *list;
	AdjMatrix *matrix;
} Graph;

Graph *create_graph(int size);
void delete_graph(Graph *graph);
void print_graph(const Graph *graph);

bool add_to_graph(Graph *graph, int id, int value);
bool remove_from_graph(Graph *graph, int id);

bool connect_vertices(Graph *graph, int from_id, int to_id);
bool disconnect_vertices(Graph *graph, int from_id, int to_id);

#endif
