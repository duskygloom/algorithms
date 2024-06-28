/*
Algorithm

for i in [1, length)
	for j in [i, 0, -1)
		if arr[i] < arr[j-1]
			swap(arr[i], arr[j])
*/


#include <stdio.h>
#include <stdlib.h>


int *input_array(int length)
{
	int *array = calloc(length, sizeof(int));
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


void sort(int *array, int length)
{
	for (int i = 0; i < length; ++i)
		for (int j = i; j > 0; --j)
			if (array[j] < array[j-1]) {
				int temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
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
