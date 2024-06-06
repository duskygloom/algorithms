#ifndef VERTEX_LIST_H
#define VERTEX_LIST_H

#include <stdbool.h>

#include "vertex.h"

typedef struct {
	int length, size;
	Vertex **array;
} VertexList;

VertexList *create_vertex_list(int length);
void delete_vertex_list(VertexList *list);
void print_vertex_list(const VertexList *list);

int get_index(const VertexList *list, int id);

Vertex *get_vertex(const VertexList *list, int index);
bool set_vertex(const VertexList *list, int index, int id, int value);

bool append_vertex(VertexList *list, int id, int value);
bool remove_vertex(VertexList *list, int index);

#endif
