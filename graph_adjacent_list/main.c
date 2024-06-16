#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "graph.h"

typedef struct {
	int value;
} Container;

Container *container_create(int value)
{
	Container *container = malloc(sizeof(Container));
	container->value = value;
	return container;
}

void print_function(const void *pointer)
{
	printf("%d", ((const Container *)pointer)->value);
}

void delete_function(void *pointer)
{
	free((Container *)pointer);
}

void test_list()
{
	List *list = list_create();
	printf("Length = %d\n", list_length(list));
	list_print(list, print_function);
	Container *c1 = container_create(12);
	Container *c2 = container_create(13);
	Container *c3 = container_create(14);
	Container *c4 = container_create(15);
	list_append(list, c1);
	list_append(list, c2);
	list_append(list, c3);
	list_append(list, c4);
	printf("Length = %d\n", list_length(list));
	list_print(list, print_function);
	list_remove(list, c3, delete_function);
	list_append(list, container_create(16));
	printf("Length = %d\n", list_length(list));
	list_print(list, print_function);
	list_pop_left(list);
	printf("Length = %d\n", list_length(list));
	list_print(list, print_function);
	list_pop_right(list);
	printf("Length = %d\n", list_length(list));
	list_print(list, print_function);
	list_delete(list, delete_function);
}

void test_graph()
{
	Graph *graph = graph_create();
	Vertex *v1 = vertex_create('A');
	Vertex *v2 = vertex_create('B');
	Vertex *v3 = vertex_create('C');
	Vertex *v4 = vertex_create('D');
	Vertex *v5 = vertex_create('E');
	graph_add_vertex(graph, v1);
	graph_add_vertex(graph, v2);
	graph_add_vertex(graph, v4);
	graph_add_edge(graph, v1, v3);
	graph_add_edge(graph, v1, v2);
	graph_add_edge(graph, v2, v2);
	graph_print(graph);
	graph_delete(graph);
	vertex_delete(v3);
	vertex_delete(v5);
}

int main()
{
	test_graph();
	return 0;
}
