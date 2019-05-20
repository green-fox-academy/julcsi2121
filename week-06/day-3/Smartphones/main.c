#include <stdio.h>
#include "smartphone.h"

int main()
{
    int size = count_lines("../smartphones_to_read.txt");
    smartphone_t phone_array[size];
    fill_array(phone_array, "../smartphones_to_read.txt");
    print_phones(phone_array, size);

    screen_size type_to_check = MEDIUM;
    printf("The %s is the oldest device in the database\n", get_oldest_phone(phone_array, size));
    printf("There are %d phones with %s screen in the database\n", get_screen_size_count(phone_array, size, type_to_check), screen_size_to_string(type_to_check));

    create_price_list(phone_array, size);
    return 0;
}
