#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int *create_array(int length)
{
	int *array = calloc(length, sizeof(int));
	assert(array);
	return array;
}

void fill_array(int *array, int length)
{
	for (int i = 0; i < length; ++i)
		scanf("%d", array+i);
}

void print_array(int *array, int length)
{
	putchar('[');
	if (length > 0)
		printf("%d", array[0]);
	for (int i = 1; i < length; ++i)
		printf(", %d", array[i]);
	putchar(']');
}

int count_digits(int num)
{
	int count = 0;
	for (; num != 0; num /= 10, ++count);
	return count;
}

/**
 * @brief		returns 10^n
 */
int pow10(int n)
{
	int result = 1;
	for (int i = 0; i < n; ++i, result *= 10);
	return result;
}

/**
 * @brief		returns the nth digit in num
 */
int nth_digit(int num, int n)
{
	return (num % pow10(n)) % 10;
}

void radix_sort(int *array, int length)
{
	// finding maximum digits
	int max_digits = 0;
	for (int i = 0; i < length; ++i) {
		int count = count_digits(array[i]);
		if (count > max_digits)
			max_digits = count;
	}
	// radix sort
	for (int i = 0; i < max_digits; ++i) {
		for (int i = 1; i < length; ++i) {
			int jth_element = array[i];
			for (int j = i; j > 0; --j) {
				if (array[j] < array[j-1])
					array[j] = array[j-1];
				else {
					array
				}
			}
		}
	}
}


int main()
{
	printf("Length of array: ");
	int length;
	scanf("%d", &length);
	int *array = calloc(length, sizeof(int));
	assert(array);

	free(array);
	return 0;
}

