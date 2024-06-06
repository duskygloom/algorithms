/*
Algorithm

function sort
	if length = 1
		return
	else if length = 2
		swap in order
	else
		sort(first half, second half)
		merge(first half, second half)
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


/*
Algorithm

for i in [start+mid-1, start, -1]
	for j in [i, start+length-1)
		if arr[j] > arr[j+1]
			swap(arr[j], arr[j+1])
		else break
*/
void merge(int *array, int start, int mid, int length)
{
	for (int i = start+mid-1; i >= start; --i)
		for (int j = i; j < start+length-1; ++j) {
			if (array[j] > array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
			else break;
		}
}


void sort(int *array, int start, int length)
{
	if (length == 2) {
		if (array[start] > array[start+1]) {
			int temp = array[start];
			array[start] = array[start+1];
			array[start+1] = temp;
		}
	} else if (length > 2) {
		sort(array, start, length/2);
		sort(array, start+length/2, length-length/2);
		merge(array, start, length/2, length);
	}
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
