#include "graph.h"

int main()
{
	Graph *graph = create_graph();
	Vertex *a = add_vertex(graph, 12);
	Vertex *b = add_vertex(graph, 14);
	Vertex *c = add_vertex(graph, 16);
	add_edge(graph, a, b);
	add_edge(graph, a, a);
	add_edge(graph, a, c);
	add_edge(graph, b, c);
	print_graph(graph);
	delete_graph(graph);
	return 0;
}
