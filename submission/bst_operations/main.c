#include "bst.h"
#include "binary_tree.h"

#include <stdio.h>

int get_option()
{
	int option;
	printf("1. Create.\n");
	printf("2. Delete.\n");
	printf("3. Insert.\n");
	printf("4. Remove.\n");
	printf("5. Search.\n");
	printf("6. Print.\n");
	printf("0. Quit.\n");
	printf("Option: ");
	scanf("%d", &option);
	return option;
}

int main()
{
	Tree *tree = NULL;
	int running = 1;
	int value;
	Node *node;
	while (running) {
		putchar('\n');
		switch (get_option()) {
		case 0:
			running = 0;
			break;
		case 1:
			if (tree) {
				printf("Tree already exists.\n");
				break;
			}
			tree = tree_create();
			printf("Created a tree.\n");
			break;
		case 2:
			if (!tree) {
				printf("No tree exists.\n");
				break;
			}
			tree_delete(tree);
			tree = NULL;
			printf("Deleted the tree.\n");
			break;
		case 3:
			if (!tree) {
				printf("No tree exists.\n");
				break;
			}
			printf("Value: ");
			scanf("%d", &value);
			bst_insert(tree, value);
			printf("Inserted %d.\n", value);
			break;
		case 4:
			if (!tree) {
				printf("No tree exists.\n");
				break;
			}
			printf("Node address: ");
			scanf("%p", &node);
			if (!tree_contains_node(tree, node)) {
				printf("Tree does not contain %p.\n", node);
				break;
			}
			value = node->value;
			bst_remove(tree, node);
			printf("Removed %d.\n", value);
			break;
		case 5:
			if (!tree) {
				printf("No tree exists.\n");
				break;
			}
			printf("Value: ");
			scanf("%d", &value);
			node = bst_search(tree, value);
			if (!node) printf("%d not found.\n", value);
			else printf("Found at %p.\n", node);
			break;
		case 6:
			if (!tree) {
				printf("No tree exists.\n");
				break;
			}
			tree_print(tree);
			break;
		default:
			printf("Invalid option.\n");
			break;
		}
	}
	// delete tree
	if (tree) tree_delete(tree);
	return 0;
}
