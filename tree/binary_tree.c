#include "binary_tree.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Tree *create_tree()
{
	Tree *tree = malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}

void _delete_tree(Node *root)
{
	if (!root) return;
	_delete_tree(root->left);
	_delete_tree(root->right);
	delete_node(root);
}

void delete_tree(Tree *tree)
{
	if (!tree) return;
	if (!tree->root) {
		free(tree);
		return;
	}
	_delete_tree(tree->root);
	free(tree);
}

typedef enum { ROOT_NODE, LEFT_NODE, RIGHT_NODE } NodePos;

void _print_tree(const Node *root, int tabs, NodePos pos)
{
	if (!root) return;
	if (pos == ROOT_NODE)
		for (int i = 0; i < tabs; ++i)
			printf("    ");
	else {
		putchar('\n');
		for (int i = 0; i < tabs; ++i)
			printf("    ");
	}
	if (pos == ROOT_NODE)
		printf("B: %d", root->value);
	else if (pos == LEFT_NODE)
		printf("L: %d", root->value);
	else if (pos == RIGHT_NODE)
		printf("R: %d", root->value);
	_print_tree(root->left, tabs+1, LEFT_NODE);
	_print_tree(root->right, tabs+1, RIGHT_NODE);
}

void print_tree(const Tree *tree)
{
	if (!tree) {
		printf("NULL");
		return;
	}
	if (!tree->root) {
		printf("EMPTY");
		return;
	}
	_print_tree(tree->root, 0, ROOT_NODE);
}

void _print_inorder(const Node *root)
{
	if (!root) return;
	_print_inorder(root->left);
	printf("%d, ", root->value);
	_print_inorder(root->right);
}

void print_inorder(const Tree *tree)
{
	putchar('[');
	_print_inorder(tree->root);
	putchar(']');
}

void _print_preorder(const Node *root, bool first_node)
{
	if (!root) return;
	printf("%d, ", root->value);
	_print_preorder(root->left, false);
	_print_preorder(root->right, false);
}

void print_preorder(const Tree *tree)
{
	putchar('[');
	_print_preorder(tree->root, true);
	putchar(']');
}

void _print_postorder(const Node *root, bool first_node)
{
	if (!root) return;
	_print_postorder(root->left, false);
	_print_postorder(root->right, false);
	printf("%d, ", root->value);
}

void print_postorder(const Tree *tree)
{
	putchar('[');
	_print_postorder(tree->root, true);
	putchar(']');
}
