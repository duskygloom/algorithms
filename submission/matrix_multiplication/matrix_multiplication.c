#include "matrix.h"

#include <stdio.h>


void iterative_multiplication(Matrix *r, const Matrix *a, const Matrix *b);

int main()
{
    int row1, col1, col2;

    printf("Rows of first matrix: ");
    scanf("%d", &row1);
    printf("Columns of first matrix: ");
    scanf("%d", &col1);
    Matrix *a = create_matrix(row1, col1);
    printf("Matrix A:\n");
    fill_matrix(a);

    printf("Columns of second matrix: ");
    scanf("%d", &col2);
    Matrix *b = create_matrix(col1, col2);
    printf("Matrix B:\n");
    fill_matrix(b);

    Matrix *r_iter = create_matrix(row1, col2);

    printf("Iterative multiplication:\n");
    iterative_multiplication(r_iter, a, b);
    print_matrix(r_iter);

    delete_matrix(r_iter);
    delete_matrix(b);
    delete_matrix(a);
    return 0;
}


void iterative_multiplication(Matrix *r, const Matrix *a, const Matrix *b)
{
    for (int i = 0; i < r->rows; ++i)
        for (int j = 0; j < r->cols; ++j)
            for (int k = 0; k < a->cols; ++k) {
                int value = get_value(r, i, j);
                value += get_value(a, i, k)*get_value(b, k, j);
                set_value(r, i, j, value);
            }
}
