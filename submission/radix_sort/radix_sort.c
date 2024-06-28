/*
Algorithm

max_number = maximum number in array
max_digits = number of digits in max_number

for i in [0, max_digits)
	insertion sort on the basis of ith digit

Note: only works for positive numbers
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

/**
 * @return
 * Returns the number of digits in the number.
 */
int get_digits(int number)
{
	int digits = 0;
	while (number > 0) {
		++digits;
		number /= 10;
	}
	return digits;
}

/**
 * @return
 * Returns the nth digit in number.
 * Counting starts from the LSB, 0 being the LSB and
 * get_digits(number)-1 being the MSB.
 */
int get_nth_digit(int number, int n)
{
	for (int i = 0; i < n; ++i)
		number /= 10;
	return number % 10;
}

void sort(int *array, int length)
{
	// finding maximum digits
	int max_number = array[0];
	for (int i = 0; i < length; ++i)
		if (array[i] > max_number)
			max_number = array[i];
	int max_digits = get_digits(max_number);
	// radix sort
	for (int i = 0; i < max_digits; ++i)
		// insertion sort on the basis of ith digit
		for (int j = 1; j < length; ++j)
			for (int k = j-1; k >= 0; --k) {
				int digit1 = get_nth_digit(array[k], i);
				int digit2 = get_nth_digit(array[k+1], i);
				if (digit1 <= digit2) break;
				int temp = array[k];
				array[k] = array[k+1];
				array[k+1] = temp;
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
