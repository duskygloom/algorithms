#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "node.h"

typedef struct Tree {
	Node *root;
} Tree;

Tree *create_tree();
void delete_tree(Tree *tree);
void print_tree(const Tree *tree);

/**
 * Algorithm
 * function inorder(node)
 *     print(node->value)
 *     inorder(node->left)
 *     inorder(node->right)
 */
void print_inorder(const Tree *tree);

/**
 * Algorithm
 * function preorder(node)
 *     preorder(node->left)
 *     print(node->value)
 *     preorder(node->right)
 */
void print_preorder(const Tree *tree);

/**
 * Algorithm
 * function postorder(node)
 *     print(node->value)
 *     postorder(node->left)
 *     postorder(node->right)
 */
void print_postorder(const Tree *tree);

#endif
