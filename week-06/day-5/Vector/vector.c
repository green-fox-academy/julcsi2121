//
// Created by Varga Júlia on 2019-05-20.
//

#include "vector.h"

vector_t create_vector(int content[], size_t size)
{
    vector_t vector;
    vector.size = size;
    vector.capacity = size;

    vector.content = (int*)malloc(vector.capacity * sizeof(int));
    memcpy(vector.content, content, size * sizeof(int));

    return vector;
}

void print_vector(vector_t vector)
{
    printf("Size: %lu, Capacity: %lu\nElements: ", vector.size, vector.capacity);
    if (vector.content == NULL) {
        printf("Vector has no values!\n");
        return;
    }

    for (int i = 0; i < vector.size; ++i) {
        printf("%d, ", vector.content[i]);
    }
    printf("\n");
}

void insert_to_end(vector_t *destination, int value)
{
    destination->size++;
    if(destination->size > destination->capacity) {
        if (destination->capacity == 0) {
            destination->capacity = 1;
        }
        destination->capacity *= 2;
        destination->content = (int*)realloc(destination->content, destination->capacity * sizeof(int));
    }

    destination->content[destination->size - 1] = value;
}

void insert_after(vector_t *destination, int value, size_t pos)
{
    destination->size++;
    if(destination->size > destination->capacity) {
        destination->capacity *= 2;
        destination->content = (int *) realloc(destination->content, destination->capacity * sizeof(int));
    }

    for (int i = destination->size - 1; i > pos; --i) {
        destination->content[i] = destination->content[i - 1];
    }
    destination->content[pos] = value;
}

size_t get_size(vector_t vector)
{
    return vector.size;
}

size_t get_capacity(vector_t vector)
{
    return vector.capacity;
}

int empty(vector_t vector)
{
    if (vector.content == NULL) {
        return 1;
    }
    return 0;
}

void delete_from_end(vector_t *destination)
{
    destination->size--;
    if (destination->capacity >= destination->size * 2) {
        destination->capacity = (destination->capacity) * 3 / 4;
        destination->content = (int *) realloc(destination->content, destination->capacity * sizeof(int));
    }
}

int delete_by_index(vector_t *destination, size_t pos)
{
    if (pos > (destination->size) - 1) {
        return 0;
    }

    for (int i = pos; i < destination->size; ++i) {
        destination->content[i] = destination->content[i + 1];
    }

    destination->size--;
    if (destination->capacity >= destination->size * 2) {
        destination->capacity = (destination->capacity) * 3 / 4;
        destination->content = (int *) realloc(destination->content, destination->capacity * sizeof(int));
    }
    return 1;
}

int search(vector_t destination, int value)
{
    for (int i = 0; i < destination.size; ++i) {
        if (destination.content[i] == value) {
            return i;
        }
    }
    return -1;
}

void shuffle(vector_t *destination)
{
    swap (destination->content[rand() % destination->size], destination->content[rand() % destination->size]);
}

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}