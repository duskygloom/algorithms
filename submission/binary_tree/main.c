#include "binary_tree.h"

#include <stdio.h>

/**
 * @note
 * Example binary tree used in this program.
 * 			12
 * 		   /  \
 * 		 16   10
 * 		/  \    \
 * 	   4   9    21
 * 	  / \
 * 	 0  20
 */

int main()
{
	printf("Tree:\n");
	printf("        12\n");
	printf("       /  \\\n");
	printf("     16   10\n");
	printf("    /  \\    \\\n");
	printf("   4   9    21\n");
	printf("  / \\\n");
	printf(" 0  20\n");
	Tree *tree = tree_create();
	// nodes
	Node *node00 = node_create(0);
	Node *node04 = node_create(4);
	Node *node09 = node_create(9);
	Node *node10 = node_create(10);
	Node *node12 = node_create(12);
	Node *node16 = node_create(16);
	Node *node20 = node_create(20);
	Node *node21 = node_create(21);
	// connect the nodes
	tree->root = node12;
	node12->left = node16;
	node16->parent = node12;
	node12->right = node10;
	node10->parent = node12;
	node16->left = node04;
	node04->parent = node16;
	node16->right = node09;
	node09->parent = node16;
	node10->right = node21;
	node21->parent = node10;
	node04->left = node00;
	node00->parent = node04;
	node04->right = node20;
	node20->parent = node04;
	// print
	printf("Inorder: ");
	tree_print_inorder(tree);
	printf("Preorder: ");
	tree_print_preorder(tree);
	printf("Postorder: ");
	tree_print_postorder(tree);
	// delete tree
	tree_delete(tree);
	return 0;
}
