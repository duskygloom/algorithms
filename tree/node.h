#ifndef NODE_H
#define NODE_H

typedef struct Node {
	int value;
	struct Node *left, *right;
} Node;

Node *create_node(int value);
void delete_node(Node *node);
void print_node(const Node *node);

#endif
