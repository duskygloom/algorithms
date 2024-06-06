#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "vertex.h"
#include "vertex_list.h"


VertexList *create_vertex_list(int size)
{
	VertexList *list = malloc(sizeof(VertexList));
	assert(list);
	list->array = calloc(size, sizeof(Vertex *));
	assert(list->array);
	list->size = size;
	list->length = 0;
	return list;
}

void delete_vertex_list(VertexList *list)
{
	if (!list) return;
	if (!list->array) {
		free(list);
		return;
	}
	for (int i = 0; i < list->size; ++i)
		delete_vertex(list->array[i]);
	free(list->array);
	free(list);
}

void print_vertex_list(const VertexList *list)
{
	if (!list) {
		printf("NULL");
		return;
	}
	putchar('[');
	if (list->length > 0)
		print_vertex(get_vertex(list, 0));
	for (int i = 1; i < list->length; ++i) {
		printf(", ");
		print_vertex(get_vertex(list, i));
	}
	putchar(']');
}

int get_index(const VertexList *list, int id)
{
	for (int i = 0; i < list->length; ++i)
		if (list->array[i]->id == id) return i;
	return -1;
}

Vertex *get_vertex(const VertexList *list, int index)
{
	if (!list || index < 0 || index >= list->length)
		return NULL;
	return list->array[index];
}

bool set_vertex(const VertexList *list, int index, int id, int value)
{
	if (!list || index < 0 || index >= list->length)
		return false;
	list->array[index]->id = id;
	list->array[index]->value = value;
	return true;
}

bool append_vertex(VertexList *list, int id, int value)
{
	bool reallocated = false;
	if (list->length >= list->size) {
		list->array = reallocarray(list->array, list->size+1, sizeof(Vertex *));
		assert(list->array);
		list->array[list->size++] = NULL;
		reallocated = true;
	}
	list->array[list->length++] = create_vertex(id, value);
	return reallocated;
}

bool remove_vertex(VertexList *list, int index)
{
	if (!list || index < 0 || index >= list->size)
		return false;
	delete_vertex(list->array[index]);
	for (int i = index; i < list->size-1; ++i)
		list->array[i] = list->array[i+1];
	list->array = reallocarray(list->array, list->size-1, sizeof(Vertex *));
	assert(list->array);
	--list->size;
	--list->length;
	return true;
}
