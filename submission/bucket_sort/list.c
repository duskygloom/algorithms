#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node *node_create(int value)
{
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->prev = node->next = NULL;
	return node;
}

List *list_create()
{
	List *list = malloc(sizeof(List));
	list->head = NULL;
	return list;
}

void list_delete(List *list)
{
	Node *curr = list->head, *next;
	while (curr) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(list);
}

void list_print(const List *list)
{
	if (!list || !list->head) {
		printf("[]\n");
		return;
	}
	printf("[%d", list->head->value);
	Node *curr = list->head->next;
	while (curr) {
		printf(", %d", curr->value);
		curr = curr->next;
	}
	printf("]\n");
}

void list_append(List *list, int value)
{
	if (!list->head) {
		list->head = node_create(value);
		return;
	}
	Node *curr = list->head;
	while (curr->next) curr = curr->next;
	curr->next = node_create(value);
	curr->next->prev = curr;
}

void list_insertion_sort(List *list)
{
	if (!list->head || !list->head->next)
		return;
	Node *pivot = list->head->next;
	Node *outer = pivot;
	while (outer) {
		Node *inner = outer;
		while (inner != list->head) {
			if (inner->prev->value <= inner->value)
				break;
			int temp = inner->value;
			inner->value = inner->prev->value;
			inner->prev->value = temp;
			inner = inner->prev;
		}
		outer = outer->next;
	}
}
