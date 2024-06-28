/*
Algorithm

min = minimum number in array
max = maximum number in array

int count_array[max-min+1]

for i in array
	count_array[i-min] += 1

index = 0
for i in [0, max-min]
	for j in [0, count_array[i]]
		array[index++] = i
*/


#include <stdio.h>
#include <stdlib.h>


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


void sort(int *array, int length)
{
	// finding range of numbers
	int max = array[0], min = array[0];
	for (int i = 0; i < length; ++i) {
		if (array[i] > max) max = array[i];
		if (array[i] < min) min = array[i];
	}
	// creating counting array
	int *count_array = create_array(max-min+1);
	for (int i = 0; i < length; ++i)
		count_array[array[i]-min] += 1;
	// sorting array
	int index = 0;
	for (int i = 0; i <= max-min; ++i)
		for (int j = 0; j < count_array[i]; ++j)
			array[index++] = min+i;
	free(count_array);
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
