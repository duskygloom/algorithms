#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node {
	void *value;
	struct Node *prev;
	struct Node *next;
} Node;

Node *node_create(void *value);

/**
 * @brief
 * Frees node but does not free the value.
 */
void node_delete(Node *node);

typedef struct {
	Node *head;
	Node *tail;
} List;

List *list_create();

typedef void (*value_delete_function_t) (void *);

/**
 * @brief
 * Frees list but does not free the value.
 * 
 * @note
 * Pass an empty function as delete_function to not delete the value
 * and only delete the node.
 */
void list_delete(List *list, value_delete_function_t delete_function);

int list_length(const List *list);

typedef void (*value_print_function_t) (const void *);

void list_print(const List *list, value_print_function_t print_function);

void list_append(List *list, void *value);

void list_remove_node(List *list, Node *node, value_delete_function_t delete_function);

/**
 * @brief
 * Removes the first node containg value.
 * 
 * @note
 * Pass an empty function as delete_function to not delete the value
 * and only delete the node.
 */
void list_remove(List *list, void *value, value_delete_function_t delete_function);

/**
 * @brief
 * Deletes the first node and returns the value.
 */
void *list_pop_left(List *list);

/**
 * @breif
 * Deletes the last node and returns the value.
 */
void *list_pop_right(List *list);

bool list_contains(const List *list, const void *value);

bool list_empty(const List *list);

#endif // LIST_H
