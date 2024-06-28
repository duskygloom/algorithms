#include "bst.h"

#include <stdlib.h>

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

/**
 * ALGORITHM
 * if node has no children
 *     simply delete the node
 * else if node has one child
 *     replace itself with child
 *     then delete itself
 * else
 *     replace the value of node with the left-most node
 *     in the right subtree
 *     delete the left-most node in the right subtree
 */

void bst_remove(Tree *tree, Node *node)
{
	Node *replacement;
	// case 1: node has no child
	if (!node->left && !node->right)
		replacement = NULL;
	// case 2: node has one child
	else if (node->left && !node->right)
		replacement = node->left;
	else if (!node->left && node->right)
		replacement = node->right;
	// case 3: node has two children
	else {
		Node *next_node = node->right;
		while (next_node->left)
			next_node = next_node->left;
		int temp = node->value;
		node->value = next_node->value;
		next_node->value = temp;
		node = next_node;
		replacement = NULL;
	}
	// replace
	if (node->parent && node->parent->left == node)
		node->parent->left = replacement;
	else if (node->parent)
		node->parent->right = replacement;
	else
		tree->root = replacement;
	free(node);
}

/**
 * ALGORITHM
 * function search(node, value)
 *     if value == node.value
 *         found
 *     else if value < node.value
 *         search(node.left, value)
 *     else
 *         search(node.right, value)
 */

Node *_bst_search_node(Node *node, int value)
{
	if (!node)
		return NULL;
	else if (value == node->value)
		return node;
	else if (value < node->value)
		return _bst_search_node(node->left, value);
	else
		return _bst_search_node(node->right, value);
}

Node *bst_search(Tree *tree, int value)
{
	return _bst_search_node(tree->root, value);
}
