#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);


int main ()
{
    char data[50];

    puts("Give me your full name and age");
    gets(data);

    char* first_name = strtok(data, " ");
    char* last_name = strtok(NULL, " ");
    char* age = strtok(NULL, "\n");

    printf("Your name is: %s %s and you are %d years old", first_name, last_name, atoi(age));

    return 0;
}