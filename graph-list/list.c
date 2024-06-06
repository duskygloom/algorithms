#include "list.h"
#include "vertex.h"

#include <stdlib.h>

Node *create_node(void *vertex)
{
	Node *node = malloc(sizeof(Node));
	node->vertex = vertex;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void delete_node(Node *node, node_deletion_mode_t mode)
{
	if (mode == DELETE_VERTEX)
		delete_vertex(node->vertex);
	free(node);
}

List *create_list()
{
	List *list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void delete_list(List *list, node_deletion_mode_t mode)
{
	Node *temp;
	while (list->head) {
		temp = list->head;
		list->head = list->head->next;
		delete_node(temp, mode);
	}
	list->tail = NULL;
	free(list);
}

void append_node(List *list, void *vertex)
{
	Node *node = create_node(vertex);
	if (!list->head) {
		list->head = list->tail = node;
		return;
	}
	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
}

void remove_node(List *list, Node *node)
{
	if (!node) return;
	if (node->prev) node->prev = node->next;
	else list->head = node->next;
	if (node->next) node->next->prev = node->prev;
	else list->tail = node->prev;
	delete_node(list, node);
}

Node *find_node(List *list, void *vertex)
{
	Node *temp = list->head;
	while (temp) {
		if (temp->vertex == vertex)
			return temp;
		temp = temp->next;
	}
	return NULL;
}
