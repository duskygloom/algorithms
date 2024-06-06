/*
Algorithm

for i in [0, length)
	min_index = i
	for j in [i, length)
		if arr[j] < arr[min_index]
			min_index = j
	swap(arr[i], arr[j])
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


void sort(int *array, int length) {
	for (int i = 0; i < length; ++i) {
		int min = i;
		for (int j = i; j < length; ++j)
			if (array[j] < array[min])
				min = j;
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}


int main(int argc, char const *argv[])
{
	int length;
	printf("Length: ");
	scanf("%d", &length);

	int *array = input_array(length);

	sort(array, length);

	printf("\nSorted array: ");
	print_array(array, length);

	free(array);
	
	return 0;
}
