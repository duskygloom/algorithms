#include "node.h"
#include "binary_tree.h"

#include <stdio.h>

int main()
{
	Tree *tree = create_tree();
	tree->root = create_node(10);
	tree->root->left = create_node(20);
	tree->root->left->left = create_node(40);
	tree->root->right = create_node(30);
	tree->root->right->right = create_node(50);
	print_tree(tree);
	putchar('\n');
	print_inorder(tree);
	putchar('\n');
	print_preorder(tree);
	putchar('\n');
	print_postorder(tree);
	putchar('\n');
	delete_tree(tree);
	return 0;
}
