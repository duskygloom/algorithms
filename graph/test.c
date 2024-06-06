#include "graph.h"

#include <stdio.h>

int main()
{
	Graph *graph = create_graph(5);
	add_to_graph(graph, 0, 0);
	add_to_graph(graph, 1, 1);
	add_to_graph(graph, 2, 2);
	add_to_graph(graph, 3, 3);
	add_to_graph(graph, 4, 4);
	connect_vertices(graph, 0, 2);
	connect_vertices(graph, 2, 0);
	connect_vertices(graph, 0, 1);
	connect_vertices(graph, 1, 2);
	connect_vertices(graph, 2, 3);
	connect_vertices(graph, 4, 1);
	print_graph(graph);
	putchar('\n');
	putchar('\n');
	remove_from_graph(graph, 2);
	remove_from_graph(graph, 2);
	print_graph(graph);
	putchar('\n');
	delete_graph(graph);
	return 0;
}
