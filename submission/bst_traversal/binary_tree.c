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

/**
 * ALGORITHM
 * print root
 * print left subtree
 * print right subtree
 */

void _tree_print_node_preorder(const Node *node)
{
	static bool first_node = true;
	if (!node) return;
	if (first_node) {
		printf("[%d", node->value);
		first_node = false;
	}
	else printf(", %d", node->value);
	_tree_print_node_preorder(node->left);
	_tree_print_node_preorder(node->right);
}

void tree_print_preorder(const Tree *tree)
{
	if (!tree->root) {
		printf("[]\n");
		return;
	}
	_tree_print_node_preorder(tree->root);
	printf("]\n");
}

/**
 * ALGORITHM
 * print left subtree
 * print right subtree
 * print root
 */

void _tree_print_node_postorder(const Node *node)
{
	static bool first_node = true;
	if (!node) return;
	_tree_print_node_postorder(node->left);
	_tree_print_node_postorder(node->right);
	if (first_node) {
		printf("[%d", node->value);
		first_node = false;
	}
	else printf(", %d", node->value);
}

void tree_print_postorder(const Tree *tree)
{
	if (!tree->root) {
		printf("[]\n");
		return;
	}
	_tree_print_node_postorder(tree->root);
	printf("]\n");
}
