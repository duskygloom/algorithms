#include "graph.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Graph *graph_create()
{
	Graph *graph = malloc(sizeof(Graph));
	graph->vertices = list_create();
	return graph;
}

void graph_delete(Graph *graph)
{
	list_delete(graph->vertices, void_vertex_delete);
	free(graph);
}

void graph_print(const Graph *graph)
{
	Node *node = graph->vertices->head;
	while (node != NULL) {
		vertex_print(node->value);
		printf(" -> ");
		list_print(((Vertex *)node->value)->adjacent, void_vertex_print);
		node = node->next;
	}
}

void graph_add_vertex(Graph *graph, Vertex *vertex)
{
	list_append(graph->vertices, vertex);
}

void graph_remove_vertex(Graph *graph, Vertex *vertex)
{
	Node *node = graph->vertices->head;
	while (node != NULL) {
		if (node->value == vertex) {
			list_remove_node(graph->vertices, node, void_vertex_delete);
			continue;
		}
		List *adjacent_list = ((Vertex *)node->value)->adjacent;
		Node *innernode = adjacent_list->head;
		while (innernode != NULL) {
			if (innernode->value == vertex)
				list_remove_node(adjacent_list, innernode, void_vertex_delete);
		}
	}
}

bool graph_contains(const Graph *graph, const Vertex *vertex)
{
	return list_contains(graph->vertices, vertex);
}

void graph_add_edge(Graph *graph, Vertex *from, Vertex *to)
{
	list_append(from->adjacent, to);
}

void graph_remove_edge(Graph *graph, Vertex *from, Vertex *to)
{
	list_remove(from->adjacent, to, void_vertex_delete);
}
