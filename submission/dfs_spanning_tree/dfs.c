/*
ALGORITHM

timestamp = 0

function DFS_VISIT(vertex):
    # increase timestamp
    timestamp += 1
    vertex.discovered = timestamp
    vertex.color = GRAY
    for v in vertex.adjacent:
        if v.color == WHITE:
            v.parent = vertex
            DFS_VISIT(v)
    vertex.finished = timestamp
    vertex.color = BLACK

function DFS(graph):
    # whiten all vertices
    for v in graph.vertices:
        v.color = WHITE
        v.parent = NULL
    # reset timestamp
    timestamp = 0
    # visit every vertex
    for v in graph.vertices:
        if v.color == WHITE:
            DFS_VISIT(graph, v)
*/

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
	v2 = vertex_create('S');
	v3 = vertex_create('T');
	v4 = vertex_create('U');
	v5 = vertex_create('V');
	v6 = vertex_create('W');
	v7 = vertex_create('X');
	v8 = vertex_create('Y');
	v9 = vertex_create('Z');
	// add vertices
	graph_add_vertex(graph, v2);
	graph_add_vertex(graph, v3);
	graph_add_vertex(graph, v4);
	graph_add_vertex(graph, v5);
	graph_add_vertex(graph, v6);
	graph_add_vertex(graph, v7);
	graph_add_vertex(graph, v8);
	graph_add_vertex(graph, v9);
	// vertices from S
	graph_add_edge(graph, v2, v9);
	graph_add_edge(graph, v2, v6);
	// vertices from T
	graph_add_edge(graph, v3, v5);
	graph_add_edge(graph, v3, v4);
	// vertices from U
	graph_add_edge(graph, v4, v3);
	graph_add_edge(graph, v4, v5);
	// vertices from V
	graph_add_edge(graph, v5, v2);
	graph_add_edge(graph, v5, v6);
	// vertices from W
	graph_add_edge(graph, v6, v7);
	// vertices from X
	graph_add_edge(graph, v7, v9);
	// vertices from Y
	graph_add_edge(graph, v8, v7);
	// vertices from Z
	graph_add_edge(graph, v9, v8);
	graph_add_edge(graph, v9, v6);
	return graph;
}

void dfs_visit(Vertex *root, List *stack)
{
	root->color = GRAY;
	putchar('(');
	vertex_print(root);
	Node *node = root->adjacent->head;
	while (node) {
		Vertex *curr = node->value;
		// remove edge from parent to child if
		// child already discovered
		if (curr->color != WHITE)
			graph_remove_edge(root, curr);
		else
			dfs_visit(curr, stack);
		node = node->next;
	}
	list_append(stack, root);
	root->color = BLACK;
	vertex_print(root);
	putchar(')');
}

void dfs_print(Graph *graph)
{
	// set all colors to WHITE
	Node *node = graph->vertices->head;
	while (node != NULL) {
		((Vertex *)node->value)->color = WHITE;
		node = node->next;
	}
	// stack for vertices
	List *stack = list_create();
	Node *curr = graph->vertices->head;
	while (curr) {
		if (((Vertex *)curr->value)->color == WHITE)
			dfs_visit(curr->value, stack);
		curr = curr->next;
	}
	printf("\nDFS: ");
	list_print(stack, void_vertex_print);
	list_delete(stack, NULL);
}

int main()
{
	Graph *graph = get_graph();
	printf("BEFORE:\n");
	graph_print(graph);
	putchar('\n');
	dfs_print(graph);
	putchar('\n');
	printf("AFTER:\n");
	tree_print(graph);
	graph_delete(graph);
	return 0;
}
