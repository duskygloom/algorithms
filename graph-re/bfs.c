#include "list.h"
#include "graph.h"

void print_bfs(const Graph *graph);

int main()
{
	return 0;
}

void _collect_vertices(const Graph *graph, List *vertex_list, Vertex *vertex)
{
	if (!vertex) return;
	while ()
}

void print_bfs(const Graph *graph)
{
	int size = get_graph_size(graph);
	List *vertex_list = create_list(VERTEX_LIST);
	_collect_vertices(graph, vertex_list, graph->vertex->head);
	print_list(vertex_list);
	delete_list(vertex_list);
}
