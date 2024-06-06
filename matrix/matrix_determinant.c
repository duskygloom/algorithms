#include "matrix.h"

#include <stdio.h>

#define POW_MINUS_1(n)	((-2)*(n%2) + 1)

int recursive_determinant(const Matrix *m);

int main()
{
    int row;
    printf("Size: ");
    scanf("%d", &row);

    Matrix *m = create_matrix(row, row);

    printf("Matrix:\n");
    fill_matrix(m);

    printf("Recursive determinant: %d\n", recursive_determinant(m));
    
    delete_matrix(m);
    return 0;
}

int recursive_determinant(const Matrix *m)
{
	int size = m->rows;
	if (size == 1)
		return get_value(m, 0, 0);
	int d = 0;
	for (int i = 0; i < size; ++i) {
		Matrix *adj = create_matrix(size-1, size-1);
		int row = 0, col = 0;
		for (int j = 1; j < size; ++j, ++row) {
			for (int k = 0; k < size; ++k) {
				if (k == i) continue;
				set_value(adj, row, col, get_value(m, j, k));
				++col;
			}
			col = 0;
		}
		d += POW_MINUS_1(i) * get_value(m, 0, i) * recursive_determinant(adj);
		delete_matrix(adj);
	}
	return d;
}
