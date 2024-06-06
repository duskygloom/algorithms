#include "matrix.h"

#include <stdio.h>


void iterative_subtraction(Matrix *r, const Matrix *a, const Matrix *b);
void recursive_subtraction(Matrix *r, const Matrix *a, const Matrix *b, int x, int y, int length);

int main()
{
	int row, col;
	printf("Rows, columns: ");
	scanf("%d %d", &row, &col);

	Matrix *a = create_sqmatrix(row, col);
	Matrix *b = create_sqmatrix(row, col);
	Matrix *r_iter = create_sqmatrix(row, col);
	Matrix *r_recur = create_sqmatrix(row, col);

	printf("Matrix A:\n");
	fill_matrix(a);
	printf("Matrix B:\n");
	fill_matrix(b);

	printf("Iterative subtraction:\n");
	iterative_subtraction(r_iter, a, b);
	print_matrix(r_iter);

	printf("Recursive subtraction:\n");
	recursive_subtraction(r_recur, a, b, 0, 0, get_sqmatrix_length(r_recur));
	print_matrix(r_recur);

	delete_sqmatrix(r_recur);
	delete_sqmatrix(r_iter);
	delete_sqmatrix(b);
	delete_sqmatrix(a);
	return 0;
}


void iterative_subtraction(Matrix *r, const Matrix *a, const Matrix *b)
{
	for (int i = 0; i < r->rows; ++i)
		for (int j = 0; j < r->cols; ++j)
			set_value(r, i, j, get_value(a, i, j) - get_value(b, i, j));
}

void recursive_subtraction(Matrix *r, const Matrix *a, const Matrix *b,
				int x, int y, int length)
{
	if (length == 1) {
		set_value(r, x, y, get_value(a, x, y) - get_value(b, x, y));
		return;
	}
	recursive_subtraction(r, a, b, x, y, length/2);
	recursive_subtraction(r, a, b, x+length/2, y, length/2);
	recursive_subtraction(r, a, b, x, y+length/2, length/2);
	recursive_subtraction(r, a, b, x+length/2, y+length/2, length/2);
}

