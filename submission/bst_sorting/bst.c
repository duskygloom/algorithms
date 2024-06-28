#include "bst.h"

/**
 * ALGORITHM
 * function insert(node, value)
 *     if value < node.value
 *         if node.left == null
 *             node.left = value
 *         else
 *             insert(node.left, value)
 *     else
 *         if node.right == null
 *             node.right = value
 *         else
 *             insert(node.right, value)
 */

void _bst_insert_node(Node *node, int value)
{
	if (value < node->value && node->left)
		_bst_insert_node(node->left, value);
	else if (value < node->value) {
		node->left = node_create(value);
		node->left->parent = node;
	}
	else if (node->right)
		_bst_insert_node(node->right, value);
	else {
		node->right = node_create(value);
		node->right->parent = node;
	}
}

void bst_insert(Tree *tree, int value)
{
	if (!tree->root) {
		tree->root = node_create(value);
		return;
	}
	_bst_insert_node(tree->root, value);
}
