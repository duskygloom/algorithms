#ifndef ADJ_MATRIX_H
#define ADJ_MATRIX_H

#include <stdbool.h>

typedef struct AdjMatrix {
	int length, size;
	int **array2d;
} AdjMatrix;

AdjMatrix *create_adjmatrix(int size);
void delete_adjmatrix(AdjMatrix *matrix);
void print_adjmatrix(const AdjMatrix *matrix);

int get_adjacency(const AdjMatrix *matrix, int from, int to);
bool set_adjacency(const AdjMatrix *matrix, int from, int to, int value);

bool append_row(AdjMatrix *matrix);
bool remove_row(AdjMatrix *matrix, int row);

#endif
