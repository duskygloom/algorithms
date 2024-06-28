#include "bst.h"
#include "binary_tree.h"

#include <stdio.h>

int main()
{
	Tree *tree = tree_create();
	int length, value;
	printf("Length of array: ");
	scanf("%d", &length);
	printf("Elements: ");
	for (int i = 0; i < length; ++i) {
		scanf("%d", &value);
		bst_insert(tree, value);
	}
	printf("Ascending: ");
	tree_print_inorder(tree);
	printf("Descending: ");
	tree_print_reverse_inorder(tree);
	tree_delete(tree);
	return 0;
}
