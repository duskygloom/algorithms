#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

Vertex *create_vertex(int value)
{
	Vertex *vertex = malloc(sizeof(Vertex));
	vertex->value = value;
	return vertex;
}

Edge *create_edge(Vertex *from, Vertex *to)
{
	Edge *edge = malloc(sizeof(Edge));
	edge->from = from;
	edge->to = to;
	return edge;
}

Graph *create_graph()
{
	Graph *graph = malloc(sizeof(Graph));
	graph->vertices = create_list(VERTEX_LIST);
	graph->edges = create_list(EDGE_LIST);
	return graph;
}

void delete_graph(Graph *graph)
{
	delete_list(graph->vertices);
	delete_list(graph->edges);
	free(graph);
}

void print_adjacent_vertices(const Graph *graph, const Vertex *vertex)
{
	start_iteration(graph->edges);
	Edge *edge;
	while ((edge = next_iteration(graph->edges))) {
		if (edge->from != vertex) continue;
		printf("%d ", edge->to->value);
	}
}

void print_graph(const Graph *graph)
{
	start_iteration(graph->vertices);
	Vertex *vertex;
	while ((vertex = next_iteration(graph->vertices))) {
		printf("%d -> ", vertex->value);
		print_adjacent_vertices(graph, vertex);
		putchar('\n');
	}
}

int get_graph_size(const Graph *graph)
{
	return get_length(graph->vertices);
}

Vertex *add_vertex(Graph *graph, int value)
{
	Vertex *vertex = create_vertex(value);
	return append_node(graph->vertices, vertex);
}

Edge *add_edge(Graph *graph, Vertex *from, Vertex *to)
{
	Edge *edge = create_edge(from, to);
	return append_node(graph->edges, edge);
}

void _remove_edge_with_vertex(List *list, Vertex *vertex)
{
	Node *prev = NULL;
	Node *curr = list->head;
	Edge *edge;
	while (curr) {
		edge = curr->addr;
		if (edge->from == vertex || edge->to == vertex) {
			if (prev) prev->next = curr->next;
			else list->head = curr->next;
			delete_node(curr, list->type);
		}
		curr = curr->next;
	}
}

bool remove_vertex(Graph *graph, Vertex *vertex)
{
	_remove_edge_with_vertex(graph->edges, vertex);
	return remove_node(graph->vertices, vertex);
}

bool remove_edge(Graph *graph, Edge *edge)
{
	return remove_node(graph->edges, edge);
}
