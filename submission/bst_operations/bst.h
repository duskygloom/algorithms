#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_tree.h"

void bst_insert(Tree *tree, int value);

void bst_remove(Tree *tree, Node *node);

Node *bst_search(Tree *tree, int value);

#endif // BINARY_SEARCH_TREE_H
