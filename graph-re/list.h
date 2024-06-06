#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/**
 * @note
 * Double linked list.
 */

typedef enum { VERTEX_LIST, EDGE_LIST } list_t;

typedef struct Node {
	struct Node *next;
	void *addr;
} Node;

Node *create_node(void *addr);
void delete_node(Node *node, list_t type);

typedef struct {
	list_t type;
	Node *head;
	Node *tail;
	Node *iter;
} List;

List *create_list(list_t type);
void delete_list(List *list);
void print_list(const List *list);

int get_length(const List *list);

void *append_node(List *list, void *addr);
bool remove_node(List *list, void *addr);

void start_iteration(List *list);
void *next_iteration(List *list);

#endif // LIST_H
