#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>


void iterative_multiplication(Matrix *r, const Matrix *a, const Matrix *b);
void recursive_multiplication(Matrix *r, const Matrix *a, const Matrix *b, 
                              int rx, int ry, int ax, int ay, int bx, int by, int length);

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

    printf("Iterative multiplication:\n");
    iterative_multiplication(r_iter, a, b);
    print_matrix(r_iter);

    printf("Recursive multiplication:\n");
    recursive_multiplication(r_recur, a, b, 0, 0, 0, 0, 0, 0, get_sqmatrix_length(r_recur));
    print_matrix(r_recur);

    delete_sqmatrix(r_recur);
    delete_sqmatrix(r_iter);
    delete_sqmatrix(b);
    delete_sqmatrix(a);
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

/**
 * @note
 * R00 = A00.B00 + A01.B10
 * R01 = A00.B01 + A01.B11
 * R10 = A10.B00 + A11.B10
 * R11 = A10.B01 + A11.B11
 */
void recursive_multiplication(Matrix *r, const Matrix *a, const Matrix *b, 
                              int rx, int ry, int ax, int ay, int bx, int by, int length)
{
    if (length == 1) {
        int value = get_value(r, rx, ry);
        value += get_value(a, ax, ay)*get_value(b, bx, by);
        set_value(r, rx, ry, value);
        return;
    }
    recursive_multiplication(r, a, b, rx, ry, ax, ay, bx, by, length/2);
    recursive_multiplication(r, a, b, rx, ry, ax, ay+length/2, bx+length/2, by, length/2);
    recursive_multiplication(r, a, b, rx, ry+length/2, ax, ay, bx, by+length/2, length/2);
    recursive_multiplication(r, a, b, rx, ry+length/2, ax, ay+length/2, bx+length/2, by+length/2, length/2);
    recursive_multiplication(r, a, b, rx+length/2, ry, ax+length/2, ay, bx, by, length/2);
    recursive_multiplication(r, a, b, rx+length/2, ry, ax+length/2, ay+length/2, bx+length/2, by, length/2);
    recursive_multiplication(r, a, b, rx+length/2, ry+length/2, ax+length/2, ay, bx, by+length/2, length/2);
    recursive_multiplication(r, a, b, rx+length/2, ry+length/2, ax+length/2, ay+length/2, bx+length/2, by+length/2, length/2);
}
