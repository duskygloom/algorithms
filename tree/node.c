#include "node.h"

#include <stdio.h>
#include <stdlib.h>

Node *create_node(int value)
{
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void delete_node(Node *node)
{
	if (!node) return;
	free(node);
}

void print_node(const Node *node)
{
	printf("%d -> [%p, %p]", node->value, node->left, node->right);
}
