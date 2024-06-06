#ifndef LIST_H
#define LIST_H

typedef enum { DELETE_NODE, DELETE_VERTEX } node_deletion_mode_t;

/**
 * @note
 * Node->vertex is a void * to avoid cyclic dependency with
 * vertex.h
 * During the implementation in list.c or anywhere else,
 * include vertex.h and cast it into vertex.
 */
typedef struct Node {
	void *vertex;
	struct Node *prev;
	struct Node *next;
} Node;

Node *create_node(void *vertex);

/**
 * @note
 * Frees the memory allocated by the node.
 * Does not frees the corresponding vertex if DELETE_NODE mode.
 * Frees the corresponding vertex if DELETE_VERTEX mode.
 */
void delete_node(Node *node, node_deletion_mode_t mode);

typedef struct {
	Node *head;
	Node *tail;
} List;

/**
 * @note
 * Creates and returns an empty double linked list.
 */
List *create_list();

/**
 * @note
 * Frees the memory allocated by the list and all the nodes.
 * Does not frees the corresponding vertices if DELETE_NODE mode.
 * Frees the corresponding vertices if DELETE_VERTEX mode.
 */
void delete_list(List *list, node_deletion_mode_t mode);

void append_node(List *list, void *vertex);

/**
 * @note
 * Returns address of the first node containing vertex.
 * If vertex is not found, returns NULL.
*/
Node *find_node(List *list, void *vertex);

void remove_node(List *list, Node *node);

#endif // LIST_H
