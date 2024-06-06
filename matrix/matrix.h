#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix {
	int rows, cols;
	int **array2d;
} Matrix;

Matrix *create_matrix(int rows, int cols);
Matrix *create_sqmatrix(int rows, int cols);
void delete_matrix(Matrix *matrix);
void delete_sqmatrix(Matrix *matrix);

int get_sqmatrix_length(const Matrix *matrix);

void fill_matrix(Matrix *matrix);
void print_matrix(const Matrix *matrix);

int get_value(const Matrix *matrix, int row, int col);
void set_value(Matrix *matrix, int row, int col, int value);

#endif // MATRIX_H

