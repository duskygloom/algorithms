#include "matrix.h"

#include <stdio.h>


void recursive_addition(Matrix *r, const Matrix *a, const Matrix *b, int x, int y, int length);

int main()
{
	int row, col;
	printf("Rows, columns: ");
	scanf("%d %d", &row, &col);

	Matrix *a = create_sqmatrix(row, col);
	Matrix *b = create_sqmatrix(row, col);
	Matrix *r_recur = create_sqmatrix(row, col);

	printf("Matrix A:\n");
	fill_matrix(a);
	printf("Matrix B:\n");
	fill_matrix(b);

	printf("Recursive addition:\n");
	recursive_addition(r_recur, a, b, 0, 0, get_sqmatrix_length(r_recur));
	print_matrix(r_recur);

	delete_sqmatrix(r_recur);
	delete_sqmatrix(b);
	delete_sqmatrix(a);
	return 0;
}


/**
 * @note
 * R00 = A00 + B00
 * R01 = A01 + B01
 * R10 = A10 + B10
 * R11 = A11 + B11
 */
void recursive_addition(Matrix *r, const Matrix *a, const Matrix *b,
				int x, int y, int length)
{
	if (length == 1) {
		set_value(r, x, y, get_value(a, x, y) + get_value(b, x, y));
		return;
	}
	recursive_addition(r, a, b, x, y, length/2);
	recursive_addition(r, a, b, x+length/2, y, length/2);
	recursive_addition(r, a, b, x, y+length/2, length/2);
	recursive_addition(r, a, b, x+length/2, y+length/2, length/2);
}
