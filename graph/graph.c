#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "graph.h"
#include "adjmatrix.h"
#include "vertex_list.h"

Graph *create_graph(int size)
{
	Graph *graph = malloc(sizeof(Graph));
	assert(graph);
	graph->list = create_vertex_list(size);
	graph->matrix = create_adjmatrix(size);
	return graph;
}

void delete_graph(Graph *graph)
{
	if (!graph) return;
	delete_vertex_list(graph->list);
	delete_adjmatrix(graph->matrix);
	free(graph);
}

void print_graph(const Graph *graph)
{
	if (!graph) {
		printf("NULL");
		return;
	}
	if (graph->list->length > 0) {
		Vertex *vertex = get_vertex(graph->list, 0);
		printf("%d(%d) -> ", vertex->value, vertex->id);
		VertexList *adjacent = create_vertex_list(0);
		for (int i = 0; i < graph->matrix->length; ++i)
			if (get_adjacency(graph->matrix, 0, i) > 0) {
				Vertex *adjvertex = get_vertex(graph->list, i);
				append_vertex(adjacent, adjvertex->id, adjvertex->value);
			}
		print_vertex_list(adjacent);
		delete_vertex_list(adjacent);
	} else {
		printf("EMPTY");
		return;
	}
	for (int i = 1; i < graph->list->length; ++i) {
		Vertex *vertex = get_vertex(graph->list, i);
		printf("\n%d(%d) -> ", vertex->value, vertex->id);
		VertexList *adjacent = create_vertex_list(0);
		for (int j = 0; j < graph->matrix->length; ++j)
			if (get_adjacency(graph->matrix, i, j) > 0) {
				Vertex *adjvertex = get_vertex(graph->list, j);
				append_vertex(adjacent, adjvertex->id, adjvertex->value);
			}
		print_vertex_list(adjacent);
		delete_vertex_list(adjacent);
	}
}

bool add_to_graph(Graph *graph, int id, int value)
{
	bool vertex_status = append_vertex(graph->list, id, value);
	bool row_status = append_row(graph->matrix);
	return vertex_status || row_status;
}

bool remove_from_graph(Graph *graph, int id)
{
	int index = get_index(graph->list, id);
	int vertex_status = remove_vertex(graph->list, index);
	int row_status = remove_row(graph->matrix, index);
	return vertex_status || row_status;
}

bool connect_vertices(Graph *graph, int from_id, int to_id)
{
	int from_index = get_index(graph->list, from_id);
	int to_index = get_index(graph->list, to_id);
	if (from_index < 0 && to_index < 0) return false;
	return set_adjacency(graph->matrix, from_index, to_index, 1);
}

bool disconnect_vertices(Graph *graph, int from_id, int to_id)
{
	int from_index = get_index(graph->list, from_id);
	int to_index = get_index(graph->list, to_id);
	if (from_index < 0 && to_index < 0) return false;
	return set_adjacency(graph->matrix, from_index, to_index, 0);
}
