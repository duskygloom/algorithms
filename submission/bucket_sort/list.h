#ifndef LIST_H
#define LIST_H

typedef struct Node {
	int value;
	struct Node *prev;
	struct Node *next;
} Node;

Node *node_create(int value);

typedef struct {
	Node *head;
} List;

List *list_create();

void list_delete(List *list);

void list_print(const List *list);

void list_append(List *list, int value);

void list_insertion_sort(List *list);

#endif // LIST_H
