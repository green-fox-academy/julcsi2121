//
// Created by Varga Júlia on 2019-05-20.
//

#ifndef SMARTPHONES_SMARTPHONE_H
#define SMARTPHONES_SMARTPHONE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    BIG,
    MEDIUM,
    SMALL
}screen_size;

typedef struct smartphone {
    char name[256];
    int release_year;
    screen_size size;
}smartphone_t;

int count_lines(char* path);
screen_size get_screen_size(int size);
char* screen_size_to_string(screen_size size);
smartphone_t read_phone(char* line);
void fill_array(smartphone_t phone_array[], char* path);
void print_phones(smartphone_t phone_array[], int size);

char* get_oldest_phone(smartphone_t phone_array[], int size);
int get_screen_size_count(smartphone_t phone_array[], int size, screen_size ssize);

int calculate_price(smartphone_t phone);
void create_price_list(smartphone_t phone_array[], int size);
#endif //SMARTPHONES_SMARTPHONE_H
