/*
Algorithm

1. Search for the index of the match using bisection method.
2. Count the number of match in it's left and right.
*/


#include <stdio.h>
#include <stdlib.h>


int *input_array(int length) {
	int *array = calloc(length, sizeof(int));
	printf("Elements: ");
	for (int i = 0; i < length; ++i)
		scanf("%d", array+i);
	return array;
}


int search(int *array, int start, int end, int match)
{
	// base condition
	if (end-start == 0) return -1;
	// recursion
	int mid = (start + end) / 2;
	if (match == array[mid])
		return mid;
	else if (match < array[mid])
		return search(array, start, mid, match);
	else
		return search(array, mid+1, end, match);
}


int count(int *array, int length, int match)
{
	int index = search(array, 0, length, match);
	// not found
	if (index == -1) return 0;
	int counter = 1;
	// left
	for (int i = index-1; i >= 0; --i) {
		if (array[i] != match) break;
		++counter;
	}
	// right
	for (int i = index+1; i < length; ++i) {
		if (array[i] != match) break;
		++counter;
	}
	return counter;
}


int main(int argc, char const *argv[])
{
	int length;
	printf("Length: ");
	scanf("%d", &length);

	int *array = input_array(length);

	int match;
	printf("Match: ");
	scanf("%d", &match);

	printf("Found %d times.\n", count(array, length, match));

	free(array);
	return 0;
}
