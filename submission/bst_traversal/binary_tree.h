#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node *left, *right, *parent;
} Node;

Node *node_create(int value);

typedef struct Tree {
	Node *root;
} Tree;

Tree *tree_create();

void tree_delete(Tree *tree);

void tree_print_inorder(const Tree *tree);

void tree_print_preorder(const Tree *tree);

void tree_print_postorder(const Tree *tree);

#endif // BINARY_TREE_H
