#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node *node_create(void *value)
{
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void node_delete(Node *node)
{
	free(node);
}

List *list_create()
{
	List *list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void list_delete(List *list, value_delete_function_t delete_function)
{
	Node *curr = list->head;
	Node *next;
	while (curr) {
		next = curr->next;
		if (delete_function)
			delete_function(curr->value);
		node_delete(curr);
		curr = next;
	}
	free(list);
}

int list_length(const List *list)
{
	int length = 0;
	Node *curr = list->head;
	for (; curr; curr = curr->next)
		++length;
	return length;
}

void list_print(const List *list, value_print_function_t print_function)
{
	if (!list->head) {
		printf("[]\n");
		return;
	}
	printf("[");
	if (print_function)
		print_function(list->head->value);
	Node *curr = list->head->next;
	for (; curr; curr = curr->next) {
		printf(", ");
		if (print_function)
			print_function(curr->value);
	}
	printf("]\n");
}

void list_append(List *list, void *value)
{
	Node *newnode = node_create(value);
	if (!list->head) {
		list->head = newnode;
		list->tail = newnode;
		return;
	}
	newnode->prev = list->tail;
	list->tail->next = newnode;
	list->tail = newnode;
}

void list_remove_node(List *list, Node *node, value_delete_function_t delete_function)
{
	if (node->prev) node->prev->next = node->next;
	else list->head = node->next;
	if (node->next) node->next->prev = node->prev;
	else list->tail = node->prev;
	if (delete_function)
		delete_function(node->value);
	node_delete(node);
}

void list_remove(List *list, void *value, value_delete_function_t delete_function)
{
	Node *curr = list->head;
	for (; curr; curr = curr->next) {
		if (curr->value != value)
			continue;
		list_remove_node(list, curr, delete_function);
		break;
	}
}

void *list_pop_left(List *list)
{
	if (!list->head) return NULL;
	if (list->head == list->tail) {
		void *value = list->head->value;
		node_delete(list->head);
		list->head = list->tail = NULL;
		return value;
	}
	Node *firstnode = list->head;
	void *value = firstnode->value;
	list->head = list->head->next;
	list->head->prev = NULL;
	node_delete(firstnode);
	return value;
}

void *list_pop_right(List *list)
{
	if (!list->tail) return NULL;
	if (list->tail == list->head) {
		void *value = list->head->value;
		node_delete(list->tail);
		list->head = list->tail = NULL;
		return value;
	}
	Node *lastnode = list->tail;
	void *value = lastnode->value;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	node_delete(lastnode);
	return value;
}

bool list_contains(const List *list, const void *value)
{
	Node *curr = list->head;
	while (curr) {
		if (curr->value == value)
			return true;
		curr = curr->next;
	}
	return false;
}

bool list_empty(const List *list)
{
	return list->head == NULL;
}
