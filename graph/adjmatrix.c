#include "adjmatrix.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

AdjMatrix *create_adjmatrix(int size)
{
	AdjMatrix *matrix = malloc(sizeof(AdjMatrix));
	assert(matrix);
	matrix->array2d = calloc(size, sizeof(int *));
	assert(matrix->array2d);
	for (int i = 0; i < size; ++i) {
		matrix->array2d[i] = calloc(size, sizeof(int));
		assert(matrix->array2d[i]);
	}
	matrix->size = size;
	matrix->length = 0;
	return matrix;
}

void delete_adjmatrix(AdjMatrix *matrix)
{
	if (!matrix) return;
	if (!matrix->array2d) {
		free(matrix);
		return;
	}
	for (int i = 0; i < matrix->size; ++i)
		free(matrix->array2d[i]);
	free(matrix->array2d);
	free(matrix);
}

void print_adjmatrix(const AdjMatrix *matrix)
{
	if (!matrix) {
		printf("NULL");
		return;
	}
	if (matrix->length > 0) {
		putchar('[');
		for (int i = 0; i < matrix->length; ++i)
			printf(" % 4d", get_adjacency(matrix, 0, i));
		putchar(' ');
		putchar(']');
	} else {
		printf("EMPTY");
		return;
	}
	for (int i = 1; i < matrix->length; ++i) {
		putchar('\n');
		putchar('[');
		for (int j = 0; j < matrix->length; ++j)
			printf(" % 4d", get_adjacency(matrix, i, j));
		putchar(' ');
		putchar(']');
	}
}

int get_adjacency(const AdjMatrix *matrix, int from, int to)
{
	if (!matrix || from < 0 || from >= matrix->length || to < 0 || to >= matrix->length)
		return -1;
	return matrix->array2d[from][to];
}

bool set_adjacency(const AdjMatrix *matrix, int from, int to, int value)
{
	if (!matrix || from < 0 || from >= matrix->length || to < 0 || to >= matrix->length)
		return false;
	matrix->array2d[from][to] = value;
	return true;
}

bool append_row(AdjMatrix *matrix)
{
	if (matrix->size > matrix->length) {
		++matrix->length;
		return false;
	}
	for (int i = 0; i < matrix->size; ++i) {
		matrix->array2d[i] = reallocarray(matrix->array2d[i], matrix->size+1, sizeof(int));
		assert(matrix->array2d[i]);
		matrix->array2d[i][matrix->size] = 0;
	}
	matrix->array2d = reallocarray(matrix->array2d, matrix->size+1, sizeof(int *));
	assert(matrix->array2d);
	++matrix->size;
	++matrix->length;
	matrix->array2d[matrix->size-1] = calloc(matrix->size, sizeof(int));
	for (int i = 0; i < matrix->size; ++i)
		matrix->array2d[matrix->size-1][i] = 0;
	return true;
}

bool remove_row(AdjMatrix *matrix, int row)
{
	if (row < 0 || row >= matrix->size)
		return false;
	// swap and shift column
	for (int i = 0; i < matrix->length; ++i)
		for (int j = row; j < matrix->length-1; ++j)
			matrix->array2d[i][j] = matrix->array2d[i][j+1];
	// swap and shift row
	free(matrix->array2d[row]);
	for (int i = row; i < matrix->length-1; ++i)
		for (int j = 0; j < matrix->length; ++j)
			matrix->array2d[i] = matrix->array2d[i+1];
	// free row and column
	for (int i = 0; i < matrix->size-1; ++i) {
		matrix->array2d[i] = reallocarray(matrix->array2d[i], matrix->size-1, sizeof(int));
		assert(matrix->array2d[i]);
	}
	matrix->array2d = reallocarray(matrix->array2d, matrix->size-1, sizeof(int *));
	assert(matrix->array2d);
	--matrix->size;
	--matrix->length;
	return true;
}
