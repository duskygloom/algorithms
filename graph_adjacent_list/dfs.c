#include "list.h"
#include "graph.h"
#include "vertex.h"

#include <stdio.h>
#include <stdlib.h>

Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8, *v9;

Graph *get_graph()
{
	Graph *graph = graph_create();
	// create vertices
	v1 = vertex_create('R');
	v2 = vertex_create('S');
	v3 = vertex_create('T');
	v4 = vertex_create('U');
	v5 = vertex_create('V');
	v6 = vertex_create('W');
	v7 = vertex_create('X');
	v8 = vertex_create('Y');
	v9 = vertex_create('Z');
	// add vertices
	graph_add_vertex(graph, v1);
	graph_add_vertex(graph, v2);
	graph_add_vertex(graph, v3);
	graph_add_vertex(graph, v4);
	graph_add_vertex(graph, v5);
	graph_add_vertex(graph, v6);
	graph_add_vertex(graph, v7);
	graph_add_vertex(graph, v8);
	graph_add_vertex(graph, v9);
	// vertices from R
	graph_add_edge(graph, v1, v2);
	graph_add_edge(graph, v1, v3);
	graph_add_edge(graph, v1, v6);
	// vertices from S
	graph_add_edge(graph, v2, v1);
	graph_add_edge(graph, v2, v5);
	graph_add_edge(graph, v2, v4);
	// vertices from T
	graph_add_edge(graph, v3, v1);
	graph_add_edge(graph, v3, v4);
	// vertices from U
	graph_add_edge(graph, v4, v2);
	graph_add_edge(graph, v4, v3);
	graph_add_edge(graph, v4, v8);
	// vertices from V
	graph_add_edge(graph, v5, v2);
	graph_add_edge(graph, v5, v6);
	graph_add_edge(graph, v5, v8);
	// vertices from W
	graph_add_edge(graph, v6, v1);
	graph_add_edge(graph, v6, v5);
	graph_add_edge(graph, v6, v7);
	graph_add_edge(graph, v6, v9);
	// vertices from X
	graph_add_edge(graph, v7, v6);
	graph_add_edge(graph, v7, v8);
	graph_add_edge(graph, v7, v9);
	// vertices from Y
	graph_add_edge(graph, v8, v4);
	graph_add_edge(graph, v8, v5);
	graph_add_edge(graph, v8, v7);
	// vertices from Z
	graph_add_edge(graph, v9, v6);
	graph_add_edge(graph, v9, v7);
	return graph;
}

void dfs_visit(Vertex *root, List *stack)
{
	Node *node = root->adjacent->head;
	while (node) {
		Vertex *curr = node->value;
		if (curr->color == WHITE) {
			curr->color = GRAY;
			dfs_visit(curr, stack);
		}
		node = node->next;
	}
	list_append(stack, root);
	root->color = BLACK;
}

void dfs_print(Graph *graph, Vertex *root)
{
	// set all colors to WHITE
	Node *node = graph->vertices->head;
	while (node != NULL) {
		((Vertex *)node->value)->color = WHITE;
		node = node->next;
	}
	// for null head
	if (!root) {
		printf("[]\n");
		return;
	}
	// stack for vertices
	List *stack = list_create();
	dfs_visit(root, stack);
	list_print(stack, void_vertex_print);
	list_delete(stack, NULL);
}

int main()
{
	Graph *graph = get_graph();
	// graph_print(graph);
	printf("DFS: ");
	dfs_print(graph, v2);
	graph_delete(graph);
	return 0;
}
