//
// Created by Varga Júlia on 2019-05-20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector {
    size_t size;
    size_t capacity;
    int *content;
}vector_t;

vector_t create_vector(int content[], size_t size);
void print_vector(vector_t vector);
void insert_to_end(vector_t *destination, int value);
void insert_after(vector_t *destination, int value, size_t pos);
size_t get_size(vector_t vector);
size_t get_capacity(vector_t vector);
int empty(vector_t vector);
void delete_from_end(vector_t *destination);
int delete_by_index(vector_t *destination, size_t pos);
int search(vector_t destination, int value);
void shuffle(vector_t *destination);
void swap(int a, int b);

#endif //VECTOR_VECTOR_H
