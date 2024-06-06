#include "adjmatrix.h"
#include "graph.h"

#include <stdio.h>

int get_option();

int main()
{
	Graph *graph = NULL;
	int option, size, id, value, to, from;
	while ((option = get_option()) != 0) {
		switch (option) {
		case 1:
			if (graph) {
				printf("A graph already exists.\n");
				break;
			}
			printf("Size: ");
			scanf("%d", &size);
			graph = create_graph(size);
			break;
		case 2:
			if (!graph) {
				printf("Create a graph first.\n");
				break;
			}
			delete_graph(graph);
			graph = NULL;
			break;
		case 3:
			if (!graph) {
				printf("Create a graph first.\n");
				break;
			}
			printf("ID, value: ");
			scanf("%d %d", &id, &value);
			add_to_graph(graph, id, value);
			break;
		case 4:
			if (!graph) {
				printf("Create a graph first.\n");
				break;
			}
			printf("ID: ");
			scanf("%d", &id);
			remove_from_graph(graph, id);
			break;
		case 5:
			if (!graph) {
				printf("Create a graph first.\n");
				break;
			}
			printf("From, to: ");
			scanf("%d %d", &from, &to);
			connect_vertices(graph, from, to);
			print_adjmatrix(graph->matrix);
			putchar('\n');
			break;
		case 6:
			if (!graph) {
				printf("Create a graph first.\n");
				break;
			}
			printf("From, to: ");
			scanf("%d %d", &from, &to);
			disconnect_vertices(graph, from, to);
			print_adjmatrix(graph->matrix);
			putchar('\n');
			break;
		case 7:
			print_graph(graph);
			putchar('\n');
			break;
		default:
			printf("Invalid option.\n");
		}
	}
	delete_graph(graph);
	return 0;
}

int get_option()
{
	putchar('\n');
	printf("1. Create graph.\n");
	printf("2. Delete graph.\n");
	printf("3. Add vertex.\n");
	printf("4. Remove vertex.\n");
	printf("5. Add edge.\n");
	printf("6. Remove edge.\n");
	printf("7. Print graph.\n");
	printf("0. Exit.\n");
	int option;
	printf("Option: ");
	scanf("%d", &option);
	return option;
}
