#include "matrix.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

Matrix *create_matrix(int row, int col)
{
	Matrix *matrix = malloc(sizeof(Matrix));
	assert(matrix);
	matrix->rows = row;
	matrix->cols = col;
	matrix->array2d = calloc(row, sizeof(int *));
	assert(matrix->array2d);
	for (int i = 0; i < matrix->rows; ++i) {
		matrix->array2d[i] = calloc(col, sizeof(int));
		assert(matrix->array2d[i]);
	}
	return matrix;
}

int nearest_sqnumber(int n)
{
	int result = 1;
	while (result < n) result *= 2;
	return result;
}

int get_sqmatrix_length(const Matrix *matrix)
{
	return nearest_sqnumber(matrix->rows > matrix->cols ? matrix->rows : matrix->cols);
}

Matrix *create_sqmatrix(int row, int col)
{
	Matrix *matrix = malloc(sizeof(Matrix));
	assert(matrix);
	matrix->rows = row;
	matrix->cols = col;
	int dimension = get_sqmatrix_length(matrix);
	matrix->array2d = calloc(dimension, sizeof(int *));
	assert(matrix->array2d);
	for (int i = 0; i < dimension; ++i) {
		matrix->array2d[i] = calloc(dimension, sizeof(int));
		assert(matrix->array2d[i]);
	}
	return matrix;
}

void delete_matrix(Matrix *matrix)
{
	if (!matrix) return;
	if (!matrix->array2d) {
		free(matrix);
		return;
	}
	for (int i = 0; i < matrix->rows; ++i)
		free(matrix->array2d[i]);
	free(matrix->array2d);
	free(matrix);
}

void delete_sqmatrix(Matrix *matrix)
{
	int dimension = nearest_sqnumber(matrix->rows > matrix->cols ? matrix->rows : matrix->cols);
	if (!matrix) return;
	if (!matrix->array2d) {
		free(matrix);
		return;
	}
	for (int i = 0; i < dimension; ++i)
		free(matrix->array2d[i]);
	free(matrix->array2d);
	free(matrix);
}

void fill_matrix(Matrix *matrix)
{
	assert(matrix && matrix->array2d);
	for (int i = 0; i < matrix->rows; ++i)
		for (int j = 0; j < matrix->cols; ++j)
			scanf("%d", &matrix->array2d[i][j]);
}

void print_matrix(const Matrix *matrix)
{
	assert(matrix && matrix->array2d);
	for (int i = 0; i < matrix->rows; ++i) {
		for (int j = 0; j < matrix->cols; ++j)
			printf("%d ", matrix->array2d[i][j]);
		putchar('\n');
	}
}

int get_value(const Matrix *matrix, int row, int col)
{
	return matrix->array2d[row][col];
}

void set_value(Matrix *matrix, int row, int col, int value)
{
	matrix->array2d[row][col] = value;
}
