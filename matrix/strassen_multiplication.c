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


/**
 * S1 = B12 x B22
 * S2 = A11 x A12
 * S3 = A21 x A22
 * S4 = B21 x B11
 * S5 = A11 x A22
 * S6 = B11 x B22
 * S7 = A12 x A22
 * S8 = B21 x B22
 * S9 = A11 x A21
 * S10 = B11 x B12
 * 
 * P1 = A11 x S1 = A11 x B12 - A11 x B22
 * P2 = S2 x B22 = A11 x B22 + A12 x B22
P3 D S3  B11 .D A21  B11 C A22  B11 / ;
P4 D A22  S4 .D A22  B21  A22  B11 / ;
P5 D S5  S6 .D A11  B11 C A11  B22 C A22  B11 C A22  B22 / ;
P6 D S7  S8 .D A12  B21 C A12  B22  A22  B21  A22  B22 / ;
P7 D S9  S10 .D A11  B11 C A11  B12  A21  B11  A21  B12 / :
 */
void strassen_multiplication(Matrix *r, const Matrix *a, const Matrix *b,
                             int rx, int ry, int ax, int ay, int bx, int by, int length)
{
    if (length == 1) {
        int value = get_value(r, rx, ry);
        value += get_value(a, ax, ay)*get_value(b, bx, by);
        set_value(r, rx, ry, value);
        return;
    }
    strassen_multiplication(r, )
}
