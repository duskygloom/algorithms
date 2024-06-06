/*
Algorithm

counter = 0

for i in [0, length)
	if arr[i] == match
		++counter
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


int count(int *array, int length, int match)
{
	int counter = 0;
	for (int i = 0; i < length; ++i)
		if (array[i] == match)
			++counter;
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

	printf("Found %d times.", count(array, length, match));

	free(array);
	return 0;
}
