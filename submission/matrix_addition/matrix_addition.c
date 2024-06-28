#include "matrix.h"

#include <stdio.h>


void iterative_addition(Matrix *r, const Matrix *a, const Matrix *b);

int main()
{
	int row, col;
	printf("Rows, columns: ");
	scanf("%d %d", &row, &col);

	Matrix *a = create_matrix(row, col);
	Matrix *b = create_matrix(row, col);
	Matrix *r_iter = create_matrix(row, col);

	printf("Matrix A:\n");
	fill_matrix(a);
	printf("Matrix B:\n");
	fill_matrix(b);

	printf("Iterative addition:\n");
	iterative_addition(r_iter, a, b);
	print_matrix(r_iter);

	delete_matrix(r_iter);
	delete_matrix(b);
	delete_matrix(a);
	return 0;
}


void iterative_addition(Matrix *r, const Matrix *a, const Matrix *b)
{
	for (int i = 0; i < r->rows; ++i)
		for (int j = 0; j < r->cols; ++j)
			set_value(r, i, j, get_value(a, i, j) + get_value(b, i, j));
}
