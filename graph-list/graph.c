#include "graph.h"

#include <stdlib.h>

Graph *create_graph()
{
	Graph *graph = malloc(sizeof(Graph));
	graph->vertices = create_list();
	return graph;
}

void delete_graph(Graph *graph)
{
	delete_list(graph->vertices, DELETE_VERTEX);
	graph->vertices = NULL;
	free(graph);
}

Vertex *add_vertex(Graph *graph, int value)
{
	Vertex *vertex = create_vertex(value);
	append_node(graph->vertices, vertex);
	return vertex;
}

void remove_vertex(Graph *graph, Vertex *vertex)
{
	Node *temp = graph->vertices->head;
	
}

void add_directed_edge(Graph *graph, Vertex *to, const Vertex *from)
{
	append_node(to->adjacent, from);
}

void add_undirected_edge(Graph *graph, Vertex *to, Vertex *from)
{
	append_node(to->adjacent, from);
	append_node(from->adjacent, to);
}
