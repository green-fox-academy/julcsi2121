#include <stdio.h>
#include "vector.h"

int main() {
    srand(time(NULL));
    vector_t vector;
    int input_data[6] = {3, 7, 9, 2, 6, 1};
    vector = create_vector(input_data, 6);

    print_vector(vector);
    insert_to_end(&vector, 8);
    print_vector(vector);
    insert_after(&vector, 4, 2);
    print_vector(vector);

    //printf("Size: %lu, Capacity: %lu\n", get_size(vector), get_capacity(vector));
    //printf("If vector is empty, you will see 1: %d\n", empty(vector));

    vector_t vector2;
    //print_vector(vector2);
    //printf("If vector is empty, you will see 1: %d\n", empty(vector2));

    //insert_to_end(&vector2, 5);
    //print_vector(vector2);

    delete_from_end(&vector);
    delete_from_end(&vector);
    print_vector(vector);

    delete_by_index(&vector, 2);
    print_vector(vector);

    //printf("The value you're searching for is in %dth position.\n", search(vector, 2));

    shuffle(&vector);
    print_vector(vector);
    return 0;
}