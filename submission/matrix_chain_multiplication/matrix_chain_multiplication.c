#include <stdio.h>
#include <stdlib.h>

int *create_array(int length)
{
	return calloc(length, sizeof(int));
}

int **create_sqmatrix(int size)
{
	int **matrix = calloc(size, sizeof(int *));
	for (int i = 0; i < size; ++i) 
		matrix[i] = calloc(size, sizeof(int));
	return matrix;
}

void delete_sqmatrix(int **matrix, int size)
{
	for (int i = 0; i < size; ++i)
		free(matrix[i]);
	free(matrix);
}

int get_digits(int num)
{
	int digits = 0;
	while (num > 0) {
		num /= 10;
		++digits;
	}
	return digits;
}

void print_sqmatrix(int **matrix, int size)
{
	// finding maximum digits
	int max_number = matrix[0][0];
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (matrix[i][j] > max_number)
				max_number = matrix[i][j];
	int max_digits = get_digits(max_number);
	// print
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			printf("%*d ", max_digits, matrix[i][j]);
		putchar('\n');
	}
}

void fill_array(int *array, int length)
{
	printf("%d dimensions: ", length);
	for (int i = 0; i < length; ++i)
		scanf("%d", &array[i]);
}

void print_array(const int *array, int length)
{
	if (length <= 0) {
		printf("[]\n");
		return;
	}
	printf("[%d", array[0]);
	for (int i = 1; i < length; ++i)
		printf(", %d", array[i]);
	printf("]\n");
}

/**
 * ALGORITHM
 * num_operations
 * 
 * @param pivot
 * pivot at which to divide
 * if pivot is n, one sub array is array[:n] (inclusive) and another is [n+1:]
 * default pivot is 0
 */
int num_operations(const int *dimensions, int **lookup, int start, int length)
{
	if (length <= 1)
		return 0;
	int min = -1;
	int operations = lookup[start][length-1];
	if (operations > 0)
		return operations;
	// printf("(%d ", start);
	for (int pivot = 1; pivot < length; ++pivot) {
		operations = num_operations(dimensions, lookup, start, pivot);
		operations += num_operations(dimensions, lookup, start+pivot, length-pivot);
		operations += dimensions[start] * dimensions[start+pivot] * dimensions[start+length];
		if (operations < min || min < 0) 
			min = operations;
	}
	// printf("%d) ", start);
	lookup[start][length-1] = operations;
	return min;
}

int main()
{
	int n_matrices;
	printf("Number of matrices: ");
	scanf("%d", &n_matrices);
	int *dimensions = create_array(n_matrices+1);
	fill_array(dimensions, n_matrices+1);
	int **lookup = create_sqmatrix(n_matrices);
	printf("\nNumber of operations: %d\n", num_operations(dimensions, lookup, 0, n_matrices));
	printf("\nLookup matrix\n");
	print_sqmatrix(lookup, n_matrices);
	delete_sqmatrix(lookup, n_matrices);
	free(dimensions);
	return 0;
}
