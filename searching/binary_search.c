/*
Algorithm

function search(array, start, end, match)
	mid = (start + end) / 2
	if match == arr[mid]
		return 1
	else if match < arr[mid]
		return search(array, start, mid, match)
	else
		return search(array, mid+1, end, match)
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


int main(int argc, char const *argv[])
{
	int length;
	printf("Length: ");
	scanf("%d", &length);

	int *array = input_array(length);

	int match;
	printf("Match: ");
	scanf("%d", &match);

	int index = search(array, 0, length, match);
	if (index == -1)
		printf("Not found.\n");
	else
		printf("Found at %d.\n", index);

	free(array);
	return 0;
}
