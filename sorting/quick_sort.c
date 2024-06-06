/*
Algorithm

function sort(array, start, length)
	if length < 2
		return
	pivot = start
	for i in [pivot+1, start+length)
		if array[i] < array[pivot]
			for j in [i, start, -1)
				swap(array[j], array[j-1])
			++pivot
	sort(array, start, pivot-start)
	sort(array, pivot+1, length-pivot-1)
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


void print_array(int *array, int length) {
	printf("[");
	if (length > 0) printf("%d", array[0]);
	for (int i = 1; i < length; ++i)
		printf(", %d", array[i]);
	printf("]\n");
}


void sort(int *array, int start, int length)
{
	if (length < 2) return;
	int pivot = start;
	for (int i = pivot+1; i < start+length; ++i) {
		if (array[i] < array[pivot]) {
			for (int j = i; j > start; --j) {
				int temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
			++pivot;
		}
	}
	sort(array, start, pivot-start);
	sort(array, pivot+1, length-pivot-1);
}


int main(int argc, char const *argv[])
{
	int length;
	printf("Length: ");
	scanf("%d", &length);

	int *array = input_array(length);

	sort(array, 0, length);

	printf("\nSorted array: ");
	print_array(array, length);

	free(array);
	
	return 0;
}
