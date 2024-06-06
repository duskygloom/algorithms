#include "list.h"
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(void *addr)
{
	Node *node = malloc(sizeof(Node));
	node->addr = addr;
	node->next = NULL;
	return node;
}

void delete_node(Node *node, list_t type)
{
	if (type == VERTEX_LIST)
		free((Vertex *)node->addr);
	else if (type == EDGE_LIST)
		free((Edge *)node->addr);
	free(node);
}

List *create_list(list_t type)
{
	List *list = malloc(sizeof(List));
	list->type = type;
	list->head = NULL;
	list->tail = NULL;
	list->iter = NULL;
	return list;
}

void delete_list(List *list)
{
	Node *curr = list->head;
	Node *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		delete_node(curr, list->type);
		curr = next;
	}
	free(list);
}

void print_list(const List *list)
{
	Node *node = list->head;
	if (list->type == VERTEX_LIST)
		while (node)
			printf("%d ", ((Vertex *)node->addr)->value);
	else if (list->type == EDGE_LIST)
		while (node)
			printf("%d->%d ", ((Edge *)node->addr)->from->value, ((Edge *)node->addr)->to->value);
}

int get_length(const List *list)
{
	int length = 0;
	Node *curr = list->head;
	for (; curr; curr = curr->next, ++length);
	return length;
}

void *append_node(List *list, void *addr)
{
	Node *node = create_node(addr);
	if (!list->head)
		list->head = list->tail = node;
	else {
		list->tail->next = node;
		list->tail = node;
	}
	return node ? node->addr : NULL;
}

bool remove_node(List *list, void *addr)
{
	Node *prev = NULL;
	Node *curr = list->head;
	while (curr) {
		if (curr->addr == addr) {
			if (prev) prev->next = curr->next;
			else list->head = curr->next;
			delete_node(curr, list->type);
			return true;
		}
		curr = curr->next;
	}
	return false;
}

void start_iteration(List *list)
{
	list->iter = NULL;
}

void *next_iteration(List *list)
{
	if (!list->iter)
		list->iter = list->head;
	else
		list->iter = list->iter->next;
	return list->iter ? list->iter->addr : NULL;
}

bool exists_in(const List *list, const void *addr)
{
	Node *node = list->head;
	while (node) {
		if (node->addr == addr) return true;
		node = node->next;
	}
	return false;
}
