#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *node_create(int value)
{
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = node->parent = NULL;
	return node;
}

Tree *tree_create()
{
	Tree *tree = malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}

void _tree_delete_node(Node *node)
{
	if (!node) return;
	_tree_delete_node(node->left);
	_tree_delete_node(node->right);
	free(node);
}

void tree_delete(Tree *tree)
{
	_tree_delete_node(tree->root);
	free(tree);
}

void _tree_print_node(const Node *root, int spaces)
{
	if (!root) return;
    for (int i = 0; i < spaces; ++i)
    	printf("... ");
    printf("%d\n", root->value);
    _tree_print_node(root->left, spaces+1);
    _tree_print_node(root->right, spaces+1);
}

void tree_print(const Tree *tree)
{
	_tree_print_node(tree->root, 0);
}

bool _tree_compare_node(const Node *root, const Node *node)
{
	if (!root) return false;
	else if (root == node) return true;
	return _tree_compare_node(root->left, node) || _tree_compare_node(root->right, node);
}

bool tree_contains_node(const Tree *tree, const Node *node)
{
	return _tree_compare_node(tree->root, node);
}
