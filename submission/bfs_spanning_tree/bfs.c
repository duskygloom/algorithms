/*
ALGORITHM

function BFS(graph, source):
    # whiten all vertices
    for v in graph.vertices:
        v.color = WHITE
        v.parent = NULL
    # traverse source
    source.color = GRAY
    source.depth = 0
    source.parent = NULL
    enqueue(source)
    # keep dequeuing
    while not is_queue_empty():
        curr = dequeue()
        # traverse nodes adjacent to source
        for v in curr.adjacent:
            if v.color == WHITE:
                v.color = GRAY
                v.depth = curr.depth + 1
                v.parent = curr
                enqueue(v)
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
	graph_add_edge(graph, v2, v4);
	graph_add_edge(graph, v2, v5);
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

/**
 * @brief
 * Prints bfs traversal and modifies the graph to
 * a spanning tree.
 */
void bfs_print(Graph *graph, Vertex *head)
{
	// set all colors to WHITE
	Node *node = graph->vertices->head;
	while (node != NULL) {
		((Vertex *)node->value)->color = WHITE;
		node = node->next;
	}
	// for null head
	if (!head) {
		printf("[]\n");
		return;
	}
	// queue for vertices
	List *bfs = list_create();
	List *queue = list_create();
	list_append(queue, head);
	head->color = GRAY;
	// add root vertex
	while (!list_empty(queue)) {
		list_print(queue, void_vertex_print);
		Vertex *curr = list_pop_left(queue);
		list_append(bfs, curr);
		Node *node = curr->adjacent->head;
		while (node != NULL) {
			Vertex *neighbour = node->value;
			// remove edge from parent to child if
			// child is already discovered
			if (neighbour->color != WHITE) 
				graph_remove_edge(curr, neighbour);
			else {
				list_append(queue, neighbour);
				neighbour->color = GRAY;
			}
				
			node = node->next;
		}
		curr->color = BLACK;
	}
	printf("BFS traversal: ");
	list_print(bfs, void_vertex_print);
	list_delete(bfs, NULL);
	list_delete(queue, NULL);
	return;
}

int main()
{
	Graph *graph = get_graph();
	printf("BEFORE:\n");
	graph_print(graph);
	putchar('\n');
	bfs_print(graph, v2);
	putchar('\n');
	printf("AFTER:\n");
	tree_print(graph, v2);
	graph_delete(graph);
	return 0;
}
