#ifndef VERTEX_H
#define VERTEX_H

typedef struct {
	int id, value;
} Vertex;

Vertex *create_vertex(int id, int value);
void delete_vertex(Vertex *vertex);
void print_vertex(const Vertex *vertex);

#endif
