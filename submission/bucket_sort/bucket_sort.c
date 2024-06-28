/*
Algorithm

min = minimum number in array
max = maximum number in array

bucket = array of lists of integers

for value in array
	append value to a bucket proportional to it
clear array

for list in bucket
	sort(list)
	for value in list
		append value to array
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int *create_array(int length)
{
	int *array = calloc(length, sizeof(int));
	return array;
}

int *input_array(int length)
{	
	int *array = create_array(length);
	printf("Elements: ");
	for (int i = 0; i < length; ++i)
		scanf("%d", array+i);
	return array;
}

void print_array(int *array, int length)
{
	printf("[");
	if (length > 0) printf("%d", array[0]);
	for (int i = 1; i < length; ++i)
		printf(", %d", array[i]);
	printf("]\n");
}

void sort(int *array, int length, int bucket_size)
{
	// finding min and max number
	int min, max;
	min = max = array[0];
	for (int i = 1; i < length; ++i) {
		if (array[i] < min) min = array[i];
		if (array[i] > max) max = array[i];
	}
	// create bucket
	List **bucket = calloc(bucket_size, sizeof(List *));
	for (int i = 0; i < bucket_size; ++i)
		bucket[i] = list_create();
	for (int i = 0; i < length; ++i) {
		int index = (array[i]-min) * bucket_size / (max-min+1);
		list_append(bucket[index], array[i]);
	}
	// sort each bucket
	int index = 0;
	for (int i = 0; i < bucket_size; ++i) {
		printf("Before sort: ");
		list_print(bucket[i]);
		list_insertion_sort(bucket[i]);
		printf("After sort: ");
		list_print(bucket[i]);
		putchar('\n');
		Node *node = bucket[i]->head;
		while (node != NULL && index < length) {
			array[index++] = node->value;
			node = node->next;
		}
	}
	// delete bucket
	for (int i = 0; i < bucket_size; ++i)
		list_delete(bucket[i]);
	free(bucket);
}

int main(int argc, char const *argv[])
{
	int length;
	printf("Length: ");
	scanf("%d", &length);

	int *array = input_array(length);
	putchar('\n');

	sort(array, length, 4);

	printf("\nSorted array: ");
	print_array(array, length);

	free(array);
	
	return 0;
}
