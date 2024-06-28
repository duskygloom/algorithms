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

void _tree_print_node_inorder(const Node *node)
{
	static bool first_node = true;
	if (!node) return;
	_tree_print_node_inorder(node->left);
	if (first_node) {
		printf("[%d", node->value);
		first_node = false;
	}
	else printf(", %d", node->value);
	_tree_print_node_inorder(node->right);
}

void tree_print_inorder(const Tree *tree)
{
	if (!tree->root) {
		printf("[]\n");
		return;
	}
	_tree_print_node_inorder(tree->root);
	printf("]\n");
}

void _tree_print_node_reverse_inorder(const Node *node)
{
	static bool first_node = true;
	if (!node) return;
	_tree_print_node_reverse_inorder(node->right);
	if (first_node) {
		printf("[%d", node->value);
		first_node = false;
	}
	else printf(", %d", node->value);
	_tree_print_node_reverse_inorder(node->left);
}

void tree_print_reverse_inorder(const Tree *tree)
{
	if (!tree->root) {
		printf("[]\n");
		return;
	}
	_tree_print_node_reverse_inorder(tree->root);
	printf("]\n");
}
