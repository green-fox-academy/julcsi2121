#include "smartphone.h"

int count_lines(char* path)
{
    FILE* fileptr = fopen(path, "r");

    if (fileptr == NULL) {
        return 0;
    }

    char buffer;
    int counter = 0;

    while (buffer != EOF) {
        buffer = fgetc(fileptr);

        if (buffer == '\n') {
            counter++;
        }
    }

    fclose(fileptr);
    return counter + 1;

}

screen_size get_screen_size(int size) {
    if (size < 12) {
        return SMALL;
    } else if (size >= 15) {
        return BIG;
    } else {
        return MEDIUM;
    }
}

char* screen_size_to_string(screen_size size)
{
    if (size == BIG) {
        return "big";
    } else if (size == MEDIUM) {
        return "medium";
    } else {
        return "small";
    }
}

smartphone_t read_phone(char* line)
{
    smartphone_t phone;

    strcpy(phone.name, strtok(line, " "));
    phone.release_year = atoi(strtok(NULL, " "));
    phone.size = get_screen_size(atoi(strtok(NULL, "\n")));
    //printf("Type: %s, year: %d, size: %s", phone.name, phone.size, screen_size_to_string(phone.size));
    return phone;
}

void fill_array(smartphone_t phone_array[], char* path)
{
    FILE* my_file = fopen(path, "r");
    char buffer[50];
    int i = 0;

    while (fgets(buffer, 50, my_file) != NULL) {
        phone_array[i] = read_phone(buffer);
        i++;
    }

    fclose(my_file);

}

void print_phones(smartphone_t phone_array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("Phone type: %s, release year: %d, screen size: %s\n", phone_array[i].name, phone_array[i].release_year, screen_size_to_string(phone_array[i].size));
    }
}

char* get_oldest_phone(smartphone_t phone_array[], int size)
{
    int oldest = 10000;
    char* oldest_name;

    for (int i = 0; i < size; ++i) {
        if (phone_array[i].release_year < oldest) {
            oldest = phone_array[i].release_year;
            oldest_name = phone_array[i].name;
        }
    }
    return oldest_name;
}

int get_screen_size_count(smartphone_t phone_array[], int size, screen_size ssize)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (phone_array[i].size == ssize) {
            count++;
        }
    }
    return count;
}

int calculate_price(smartphone_t phone)
{
    int price = 300;
    int current_year = 2019;

    if (phone.size == BIG) {
        price *= 2;
    } else if (phone.size == MEDIUM) {
        price += 100;
    }

    int loss_from_age = (current_year - phone.release_year) * 50;
    if (loss_from_age > 250) {
        loss_from_age = 250;
    }

    return price - loss_from_age;
}

void create_price_list(smartphone_t phone_array[], int size)
{
    FILE *my_file = fopen("../price_list.txt", "w");

    for (int i = 0; i < size; ++i) {
        fprintf(my_file, "%s, %d\n", phone_array[i].name, calculate_price(phone_array[i]));
    }

    fclose(my_file);
}